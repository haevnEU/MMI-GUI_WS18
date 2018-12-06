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
