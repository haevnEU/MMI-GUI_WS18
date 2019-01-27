/*
 *
  +----------------------------------------+
  | Important note                         |
  +----------------------------------------+
  | This file was created by Qt Creator,   |
  | just a couple of lines are added.      |
  | The custom lines are marked            |
  | with a start and an end comment        |
  +----------------------------------------+
 *
 */
#include "view/mainwindow/mainwindow.h"
#include <QApplication>

#include "core/util/fileutils.h"

int main(int argc, char *argv[]){
    QApplication a(argc, argv);
    haevn::view::MainWindow w;

    // Custom lines to enable command line argument
    for(int i = 0; i < argc; i++){
        QString arg = QString(argv[i]);
        // Repairing was requested over start argument
        if(arg.contains("repair")){
            haevn::core::util::FileUtils fileHandler;
            fileHandler.checkFiles();
        }
        // Reseting was requested over start argument
        if(arg.contains("reset")){
            haevn::core::util::FileUtils fileHandler;
            fileHandler.checkFiles(true);
        }
    }

    // End custom lines
    w.show();
    return a.exec();
}
