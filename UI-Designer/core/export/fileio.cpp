#include "fileio.h"


haevn::core::file::FileIO::FileIO(){

}
haevn::core::file::FileIO::~FileIO(){

}

void haevn::core::file::FileIO::write(const char* t_data){

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

bool haevn::core::file::FileIO::fileExist(const char* t_path){
    std::ifstream file(t_path);
    return file.good();
}


QMap<QString, QString>* haevn::core::file::FileIO::loadScripts(){

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
