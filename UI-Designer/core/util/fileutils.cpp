#include "fileutils.h"
#include <QDebug>

haevn::core::util::FileUtils::FileUtils(){

}

haevn::core::util::FileUtils::~FileUtils(){

}

void haevn::core::util::FileUtils::write(const char* t_data){

    // Open a new File save dialog
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export scenegraph", "", "(*.*);;All Files (*)");

    // Determine if the user canceled, nothing will be saved and it is possible to return
    if (fileName.isEmpty()){
        return;
    }
    QFile file(fileName);
    // open the file if an error occurred display a message and return
    if (file.open(QIODevice::WriteOnly | QIODevice::Text)) {

        // Create a new stream which handles writing
        QTextStream out(&file);
        // Set the encoding to UTF-8
        out.setCodec("UTF-8");
        // Write the data into the stream
        out << t_data;

        file.flush();
        file.close();
    }

}

bool haevn::core::util::FileUtils::fileExist(const char* t_path){
    std::ifstream file(t_path);
    return file.good();
}


QMap<QString, QString>* haevn::core::util::FileUtils::loadScripts(){

    QMap<QString, QString>* availableScripts = new QMap<QString, QString>();

    // The scripts.toc file is contained inside the root directory of the application
    // The toc file contains the path to every build script.
    QFile inputFile(qApp->applicationDirPath().append("/build.toc"));

    // Open the file as readonly
    // If the file was opened it is possible to read it
    if (inputFile.open(QIODevice::ReadOnly)){
        // Create a new inputstream which handles reading
        QTextStream inStream(&inputFile);

        // Read until the stream ends
        while (!inStream.atEnd()){
            // Read a line
            QString input = inStream.readLine();
            // Skip lines which starts with # => comment
            if(!input.startsWith("#")){
                // Get information about the file
                QFileInfo fileInfo(qApp->applicationDirPath().append(input));
                QString name = fileInfo.fileName();
                QString path = fileInfo.filePath();
                availableScripts->insert(name, path);
            }

        }
        inputFile.close();
    }
    return availableScripts;
}


void haevn::core::util::FileUtils::checkFiles(bool forceRepair){
    // The directory of the application should look like
    // root
    //  |-----build.toc
    //  |-----data
    //  |       |-----settings.lua
    //  |       |-----scripts

    QFile tocFile(qApp->applicationDirPath().append("/build.toc"));
    QDir dataDirectory(qApp->applicationDirPath().append("/data"));
    QFile settingsFile(qApp->applicationDirPath().append("/data/settings.lua"));
    QDir scriptDirectory(qApp->applicationDirPath().append("/data/scripts"));

    // The directory should be reseted
    if(forceRepair){
        tocFile.remove();
        dataDirectory.removeRecursively();
    }

    // First evaluate the tocFile, the next step is to evaluate the data directory
    // If one of these doesnt exist the last part will not be evaluated
    // If booth exist the settings file and script direcotry is evaluated
    // If all exist the repair function is skipped
    if(!tocFile.exists() || !dataDirectory.exists()
            || !settingsFile.exists() || !scriptDirectory.exists()){
        repairFiles();
    }
}

void haevn::core::util::FileUtils::repairFiles(){
    QFile tocFile(qApp->applicationDirPath().append("/build.toc"));

    QDir dataDirectory(qApp->applicationDirPath().append("/data"));
    QFile settingsFile(qApp->applicationDirPath().append("/data/settings.lua"));
    QDir scriptDirectory(qApp->applicationDirPath().append("/data/scripts"));

    if(!tocFile.exists()){
        tocFile.open(QIODevice::WriteOnly);
        tocFile.write("# Place scripts inside data/scripts and copy their path into this file\n# Example /data/scripts/example.lua");
        tocFile.flush();
        tocFile.close();
    }

    if(!dataDirectory.exists()){
        dataDirectory.mkdir(qApp->applicationDirPath().append("/data"));
    }

    if(!scriptDirectory.exists()){
        scriptDirectory.mkdir(qApp->applicationDirPath().append("/data/scripts"));
    }

    if(!settingsFile.exists()){
        settingsFile.open(QIODevice::WriteOnly);
        settingsFile.write("# This file contains all settings, note this function is not implemented");
        settingsFile.flush();
        settingsFile.close();
    }
}
