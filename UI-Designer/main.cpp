#include "view/mainwindow/mainwindow.h"
#include <QApplication>

#include "core/models/model.h"
#include "core/models/selectionmodel.h"
#include "core/export/fileio.h"
#include "core/lua/luahandle.h"
#include <QPushButton>

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    haevn::view::MainWindow w;

    haevn::core::lua::LuaHandle* handler = new haevn::core::lua::LuaHandle();
    handler->runScript("D:\\dev\\MMI-GUI\\UI-Designer\\res\\scripts\\config.lua");



    w.show();

    int retCode = a.exec();

    delete handler;
    delete haevn::core::models::Model::getInstance();
    delete haevn::core::models::SelectionModel::getInstance();

    return retCode;
}
