#include "propertiesview.h"
#include "ui_propertiesview.h"

PropertiesView::PropertiesView(core::objects::IBaseElement* t_properties, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::PropertiesView) {
    ui->setupUi(this);

    m_properties = t_properties;
    load();
}

PropertiesView::~PropertiesView() {
    delete ui;
}

void PropertiesView::accept() {

    m_baseElement->setName(ui->m_inputName->toPlainText());
    m_baseElement->setToolTip(ui->m_inputToolTip->toPlainText());
    m_baseElement->setAction(ui->m_inputAction->toPlainText());

    m_baseElement->setWidth(ui->m_doubleSpinnBoxWidth->value());
    m_baseElement->setMinWidth(ui->m_doubleSpinnBoxMinWidth->value());
    m_baseElement->setMaxWidth(ui->m_doubleSpinnBoxMaxWidth->value());

    m_baseElement->setHeight(ui->m_doubleSpinnBoxHeight->value());
    m_baseElement->setMinHeight(ui->m_doubleSpinnBoxMinHeight->value());
    m_baseElement->setMaxHeight(ui->m_doubleSpinnBoxMaxHeigth->value());

   // m_properties.setColor(ui->m_comboColor->model()->toPlainText());
   // m_properties.setVisibility(ui->m_inputName->toPlainText());
    m_baseElement->setEnabled(ui->m_radioEnabledYes->isChecked());
    this->done(true);
}

void PropertiesView::reject() {
    this->done(false);
}

void PropertiesView::load(){

    ui->m_inputName->setText(m_baseElement->getName());
    ui->m_inputToolTip->setText(m_baseElement->getToolTip());
    ui->m_inputAction->setText(m_baseElement->getAction());

    ui->m_doubleSpinnBoxWidth->setValue(m_baseElement->getWidth());
    ui->m_doubleSpinnBoxMinWidth->setValue(m_baseElement->getMinWidth());
    ui->m_doubleSpinnBoxMaxWidth->setValue(m_baseElement->getMaxWidth());


    ui->m_doubleSpinnBoxHeight->setValue(m_baseElement->getHeight());
    ui->m_doubleSpinnBoxMinHeight->setValue(m_baseElement->getMinHeight());
    ui->m_doubleSpinnBoxMaxHeigth->setValue(m_baseElement->getMaxHeight());


   // m_properties.setColor(ui->m_comboColor->model()->toPlainText());
   // m_properties.setVisibility(ui->m_inputName->toPlainText());
    ui->m_radioEnabledYes->setChecked(m_baseElement->getEnabled());
    ui->m_radioEnabledNo->setChecked(!m_baseElement->getEnabled());
}
