#include "fileio.h"
#include <QDebug>
#include <QFileDialog>
#include <QMessageBox>

void haevn::core::FileIO::write(const char* path, const char* data){
    std::ofstream file;
    try {
        file.open (path, std::ios::out | std::ios::binary);
        file << data;
        file.flush();
    } catch(std::ofstream::failure f){
        qDebug() << f.what();
    }
    if(file.is_open()){
        file.close();
    }

}

void haevn::core::FileIO::write(const char* data){
    std::ofstream file;
    const char* path = "";

    QString fileName = QFileDialog::getSaveFileName(nullptr,
           "Export scenegraph", "",
           "(*.*);;All Files (*)");

       if (fileName.isEmpty())
           return;
       else {
           QFile file(fileName);
           if (!file.open(QIODevice::WriteOnly)) {
               QMessageBox::information(nullptr, "Unable to open file",
                   file.errorString());
               return;
           }

           QDataStream out(&file);
           out.setVersion(QDataStream::Qt_4_5);
           out << data;

       }
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


    return 0;
}

bool haevn::core::FileIO::fileExist(const char* path){
    std::ifstream file(path);
    return file.good();

}
