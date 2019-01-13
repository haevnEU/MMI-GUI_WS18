#include "view/mainwindow/mainwindow.h"
#include <QApplication>

#include "core/models/model.h"
#include "core/models/selectionmodel.h"
#include "core/export/dataexport.h"

int main(int argc, char *argv[]){

    QApplication a(argc, argv);
    haevn::view::MainWindow w;
    w.show();

    int retCode = a.exec();

    // Clean up singleton
    delete haevn::core::models::Model::getInstance();
    delete haevn::core::models::Model::getInstance();
    delete haevn::core::models::SelectionModel::getInstance();
    delete haevn::core::exporting::DataExport::getInstance();

    return retCode;
}
