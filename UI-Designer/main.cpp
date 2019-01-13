#include "view/mainwindow/mainwindow.h"
#include <QApplication>
#include "core/visual/scene.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    haevn::view::MainWindow w;
    w.show();

    return a.exec();
}
