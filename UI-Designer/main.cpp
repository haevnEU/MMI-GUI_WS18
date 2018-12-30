#include "view/mainwindow/mainwindow.h"
#include <QApplication>
#include "core/model.h"
#include "core/scene.h"


int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    haevn::core::Model model;
    haevn::view::MainWindow w;
    w.link(&model);
    w.show();

    return a.exec();
}
