#include "view/mainwindow/mainwindow.h"
#include <QApplication>

int main(int argc, char *argv[]){


    QApplication a(argc, argv);
    haevn::view::MainWindow w;

    w.show();
    int retCode = a.exec();

    // Delete singleton instances
    delete haevn::core::models::Model::getInstance();
    delete haevn::core::models::SelectionModel::getInstance();

    return retCode;
}
