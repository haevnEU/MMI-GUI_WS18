#include "propertiesview.h"
#include "ui_propertiesview.h"

PropertiesView::PropertiesView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesView)
{
    ui->setupUi(this);
}

PropertiesView::~PropertiesView()
{
    delete ui;
}

void PropertiesView::accept(){
    ui->textEdit->toPlainText();
}

void PropertiesView::reject(){

}

core::data::BaseProperties PropertiesView::getProperties(){
    return m_properties;
}
