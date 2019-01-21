#include "fileio.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>


void haevn::core::FileIO::write(const char* data){
    // Open a new File save dialog
    QString fileName = QFileDialog::getSaveFileName(nullptr, "Export scenegraph", "", "(*.*);;All Files (*)");

    // Determine if the user canceled, nothing will be saved and it is possible to return
    if (fileName.isEmpty()){
        return;
    }
    QFile file(fileName);
    // open the file if an error occurred display a message and return
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
        QMessageBox::information(nullptr, "Unable to open file", file.errorString());
        return;
    }


    // Write the data to disk using streams
    QTextStream out(&file);
    out.setCodec("UTF-8");
    out << data;
    file.flush();
    file.close();

}

const char* haevn::core::FileIO::read(const char* path){
    std::ifstream file;
    try {
        file.open (path, std::ios::in | std::ios::binary);

    } catch(std::ifstream::failure f){
        qDebug() << f.what();
    }

    if(file.is_open()){
        file.close();
    }

    return nullptr;
}

bool haevn::core::FileIO::fileExist(const char* path){
    std::ifstream file(path);
    return file.good();
}
