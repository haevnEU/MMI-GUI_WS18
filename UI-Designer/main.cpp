#include "view/mainwindow/mainwindow.h"
#include <QApplication>

#include "core/models/model.h"
#include "core/models/selectionmodel.h"
#include "core/export/dataexport.h"
#include "core/lua/luahandle.h"
#include <QPushButton>
int main(int argc, char *argv[]){

    haevn::core::lua::LuaHandle* luaHandler = haevn::core::lua::LuaHandle::getInstance();
    haevn::core::models::Model* model = haevn::core::models::Model::getInstance();

    QApplication a(argc, argv);
    haevn::view::MainWindow w;
    w.show();

    int retCode = a.exec();

    luaHandler->runScript("C:\\Users\\nilsm\\OneDrive\\Desktop\\javaFX.lua", model);
    delete haevn::core::lua::LuaHandle::getInstance();
    delete haevn::core::models::Model::getInstance();
    delete haevn::core::models::SelectionModel::getInstance();
    delete haevn::core::exporting::DataExport::getInstance();

    return retCode;
}
