#include "fileutils.h"

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
    QFile inputFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/build.toc"));

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
                QFileInfo fileInfo(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append(input));
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
    //  |-----scripts
    //  |       |-----settings.lua
    //  |-----scripts

    QFile tocFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/build.toc"));
    QFile settingsFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/settings.lua"));
    QDir scriptDirectory(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/scripts"));
    QFile exampleFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/scripts/example.lua"));

    // The directory should be reseted
    if(forceRepair){
        QDir root(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
        if(root.removeRecursively()){
            repairFiles();
        }
    }
    // First evaluate the tocFile,
    // the next step is to evaluate the settings file and script direcotry
    // If all exist the repair function is skipped
    else if(!tocFile.exists() || settingsFile.exists() || !scriptDirectory.exists() || !exampleFile.exists()){
        repairFiles();
    }
}

void haevn::core::util::FileUtils::repairFiles(){
    QDir root(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));

    if(!root.exists()){
        root.mkdir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation));
    }

    QFile tocFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/build.toc"));
    QFile settingsFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/settings.lua"));
    QDir scriptDirectory(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/scripts"));
    QFile exampleFile(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/scripts/example.lua"));

    if(!tocFile.exists()){
        tocFile.open(QIODevice::WriteOnly);
        tocFile.write("# Place scripts inside data/scripts and copy their path into this file\n# Example /scripts/example.lua");
        tocFile.flush();
        tocFile.close();
    }

    if(!scriptDirectory.exists()){
        scriptDirectory.mkdir(QStandardPaths::writableLocation(QStandardPaths::AppDataLocation).append("/scripts"));
    }

    if(!settingsFile.exists()){
        settingsFile.open(QIODevice::WriteOnly);
        settingsFile.write("# This file contains all settings, note this function is not implemented");
        settingsFile.flush();
        settingsFile.close();
    }

    if(!exampleFile.exists()){
        exampleFile.open(QIODevice::WriteOnly);
        exampleFile.write("-- You can find the example script at"
                           "\n-- https://github.com/nimile/MMI-GUI/wiki/Empty-script"
                           "\n-- https://github.com/nimile/MMI-GUI/wiki/API-Beispiel");
        exampleFile.flush();
        exampleFile.close();
    }
}
