#include "view/mainwindow/mainwindow.h"
#include <QApplication>
#include "core/util/fileutils.h"
#include <QDebug>

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    haevn::view::MainWindow w;

    for(int i = 0; i < argc; i++){
        QString arg = QString(argv[i]);
        if(arg.contains("repair")){
            haevn::core::util::FileUtils fileHandler;
            fileHandler.checkFiles();
        }
        if(arg.contains("reset")){
            haevn::core::util::FileUtils fileHandler;
            fileHandler.checkFiles(true);
        }
    }

    w.show();
    int retCode = a.exec();

    return retCode;
}
