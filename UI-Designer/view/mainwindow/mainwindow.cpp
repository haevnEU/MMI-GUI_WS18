#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QDebug>
#include <iostream>
#include <QMouseEvent>
#include "core/scene.h"

#include "core/objects/buttons/hbutton.h"
#include "core/enumerations.h"
#include <QSpinBox>

using namespace haevn::view;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow){
    ui->setupUi(this);

    // Create custom scene//
    m_scene = new core::Scene();
    // Set canvas center to the topleft point
    ui->canvas->setAlignment(Qt::AlignTop|Qt::AlignLeft);
    // Apply scene to canvas
    ui->canvas->setScene(m_scene);

    tools = new haevn::core::custom_objects::HTreeView();

    tools->addRootHeader("Control");
    tools->insertData(0, core::e_haevn_objects::control_Button);
    tools->insertData(0, core::e_haevn_objects::control_RadioButton);
    tools->insertData(0, core::e_haevn_objects::control_CheckBox);

    tools->addRootHeader("Input");
    tools->insertData(1, core::e_haevn_objects::input_TextField);
    tools->insertData(1, core::e_haevn_objects::input_ComboBox);
    tools->insertData(1, core::e_haevn_objects::input_Slider);
    tools->insertData(1, core::e_haevn_objects::input_SpinBox);
    tools->insertData(1, core::e_haevn_objects::input_Date);
    tools->insertData(1, core::e_haevn_objects::input_Time);

    tools->addRootHeader("Display");
    tools->insertData(2,  core::e_haevn_objects::display_Label);
    tools->insertData(2,  core::e_haevn_objects::display_ProgressBar);
    tools->insertData(2,  core::e_haevn_objects::display_WebView);

    tools->addRootHeader("Grouping");
    tools->insertData(3, core::e_haevn_objects::grouping_GroupBox);
    tools->insertData(3, core::e_haevn_objects::grouping_RadioButtonGroup);

    tools->addRootHeader("Items");
    tools->insertData(4, core::e_haevn_objects::dataVisualization_ListView);
    tools->insertData(4, core::e_haevn_objects::dataVisualization_TableView);
    tools->insertData(4, core::e_haevn_objects::dataVisualization_TreeView);

    tools->addRootHeader("Layout");
    tools->insertData(5, core::e_haevn_objects::layout_Grid);
    tools->insertData(5, core::e_haevn_objects::layout_Canvas);
    tools->insertData(5, core::e_haevn_objects::layout_HBox);
    tools->insertData(5, core::e_haevn_objects::layout_VBox);

    tools->setDragEnabled(true);
    layout()->addWidget(tools);

    connect(ui->spPosX, SIGNAL(valueChanged(int)), this, SLOT(posXChanged(int)));
    connect(ui->spPosY, SIGNAL(valueChanged(int)), this, SLOT(posYChanged(int)));


    connect(ui->sbObjectWidth, SIGNAL(valueChanged(int)), this, SLOT(widthChanged(int)));
    connect(ui->sbObjectMaxWidth, SIGNAL(valueChanged(int)), this, SLOT(maxWidthChanged(int)));
    connect(ui->sbObjectMinWidth, SIGNAL(valueChanged(int)), this, SLOT(minWidthChanged(int)));

    connect(ui->sbObjectHeight, SIGNAL(valueChanged(int)), this, SLOT(heightChanged(int)));
    connect(ui->sbObjectMaxWidth, SIGNAL(valueChanged(int)), this, SLOT(minWidthChanged(int)));
    connect(ui->sbObjectMinHeight, SIGNAL(valueChanged(int)), this, SLOT(minHeightChanged(int)));

    connect(ui->leContent, SIGNAL(textChanged(QString)), this, SLOT(contentChanged(QString)));
    connect(ui->leTooltip, SIGNAL(textChanged(QString)), this, SLOT(tooltipChanged(QString)));

    connect(ui->cbVisibility, SIGNAL(stateChanged(int)), this, SLOT(visibilityChanged(int)));

    connect(m_scene, SIGNAL(selectedItemChanged(QWidget*)), this, SLOT(selectedItemChanged(QWidget*)));
}

void MainWindow::posXChanged(int t_x){
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->move(t_x, ui->spPosY->value());
    }
}
void MainWindow::posYChanged(int t_y){
    if(m_scene != nullptr) {
        qDebug() << ui->spPosX->value();
        m_scene->getSelectedWidget()->move(ui->spPosX->value(), t_y);
    }
}

void MainWindow::widthChanged(int t_width){
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->resize(t_width, ui->sbObjectHeight->value());
    }
}

void MainWindow::maxWidthChanged(int t_width){
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->setMaximumWidth(t_width);
    }
}

void MainWindow::minWidthChanged(int t_width){
    if(m_scene != nullptr) {

        m_scene->getSelectedWidget()->setMinimumWidth(t_width);
    }
}

void MainWindow::heightChanged(int t_height){
    if(m_scene != nullptr) {

        m_scene->getSelectedWidget()->resize(ui->sbObjectWidth->value(), t_height);
    }
}

void MainWindow::maxHeightChanged(int t_height){
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->setMaximumHeight(t_height);
    }
}

void MainWindow::minHeightChanged(int t_height){
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->setMinimumHeight(t_height);
    }
}

void MainWindow::contentChanged(QString t_content){

    qDebug() << t_content;
}

void MainWindow::tooltipChanged(QString t_tooltip){
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->setToolTip(t_tooltip);
    }
}

void MainWindow::visibilityChanged(int t_visibility){
    bool state = t_visibility == Qt::CheckState::Checked ? true : false;
    if(m_scene != nullptr) {
        m_scene->getSelectedWidget()->setEnabled(state);
    }
}

void MainWindow::selectedItemChanged(QWidget* widget){
    if(nullptr != widget){
        ui->spPosX->setValue(widget->pos().x());
        ui->spPosY->setValue(widget->pos().y());

        ui->sbObjectWidth->setValue(widget->width());
        ui->sbObjectMaxWidth->setValue(widget->maximumWidth());
        ui->sbObjectMinWidth->setValue(widget->minimumWidth());

        ui->sbObjectHeight->setValue(widget->height());
        ui->sbObjectMaxHeight->setValue(widget->maximumHeight());
        ui->sbObjectMinHeight->setValue(widget->minimumHeight());

        ui->cbVisibility->setCheckState(widget->isEnabled() == true ? Qt::CheckState::Checked : Qt::CheckState::Unchecked);
        ui->leTooltip->setText(widget->toolTip());
    }
}

MainWindow::~MainWindow(){
    if(m_scene != nullptr){
        delete m_scene;
        m_scene = nullptr;
    }
    delete ui;
}


void MainWindow::resizeEvent(QResizeEvent* t_event){

    int posY = 10;
    int height = size().height() - 20;

    int canvasPosX = 320;
    int canvasWidth = (size().width() * 0.97) - 620;

    int detailsPosX = (canvasWidth) + 320;


    tools->resize(300, height);
    tools->move(10, posY);

    ui->canvas->resize(canvasWidth, height);
    ui->canvas->move(canvasPosX, posY);

    ui->details->resize(300, height);
    ui->details->move(detailsPosX, posY);


}
