#include "runscriptwizard.h"
#include "ui_runscriptwizard.h"

#include <QDebug>

haevn::view::RunScriptWizard::RunScriptWizard(haevn::core::models::Model* t_appModel, QWidget *parent) : QWizard(parent), ui(new Ui::RunScriptWizard){
    ui->setupUi(this);
    m_appModel = t_appModel;
    m_luaScriptHandler = new haevn::core::lua::LuaHandle(m_appModel);

    for(QString item : m_appModel->getScripts()->values()){
        ui->listAvailableScripts->addItem(item);
    }

    connect(ui->listAvailableScripts, SIGNAL(itemSelectionChanged()), this, SLOT(itemSelectionChanged()));
}

haevn::view::RunScriptWizard::~RunScriptWizard(){
    delete m_luaScriptHandler;
    m_luaScriptHandler = nullptr;
    delete ui;
}

void haevn::view::RunScriptWizard::itemSelectionChanged(){
    QListWidgetItem* item = ui->listAvailableScripts->selectedItems().at(0);
    m_appModel->getScripts()->value(item->text());
    qDebug() << item->text();
    qDebug() << m_appModel->getScripts()->value(item->text());

}
