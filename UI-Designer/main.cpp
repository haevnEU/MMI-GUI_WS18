#include "view/mainwindow/mainwindow.h"
#include <QApplication>

#include "core/models/model.h"
#include "core/models/selectionmodel.h"
#include "core/export/fileio.h"
#include "core/lua/luahandle.h"
#include <QPushButton>
#include <QWidget>
#include <QCheckBox>

#include <QDebug>

int main(int argc, char *argv[]){


    QApplication a(argc, argv);
    haevn::view::MainWindow w;

    w.show();

    int retCode = a.exec();

    delete haevn::core::models::Model::getInstance();
    delete haevn::core::models::SelectionModel::getInstance();

    return retCode;
}
