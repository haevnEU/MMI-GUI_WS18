#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <iostream>
#include <QPushButton>
#include <QRadioButton>
#include <QCheckBox>
#include <QTreeWidgetItem>
#include <QLabel>


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QLabel* lbLayout = new QLabel("Layout");
    QLabel* lbControl = new QLabel("Control");
    QLabel* lbInput= new QLabel("Input");
    QLabel* lbDisplay = new QLabel("Display");
    QLabel* lbGrouping = new QLabel("Grouping");
    QLabel* lbItems = new QLabel("Items");

    QPushButton* btButtonItem = new QPushButton("Button");
    QCheckBox* cbCheckBoxItem = new QCheckBox("CheckBox");
    QRadioButton* rbRadioButton = new QRadioButton("RadioButton");

    QTreeWidgetItem* seconLevelItemButton = new QTreeWidgetItem();
    QTreeWidgetItem* seconLevelItemCheckBox = new QTreeWidgetItem();
    QTreeWidgetItem* seconLevelItemRadioButton = new QTreeWidgetItem();



    // Creating widgetitems
    QTreeWidgetItem *topLevelItemLayout = new QTreeWidgetItem();
    QTreeWidgetItem *topLevelItemControl = new QTreeWidgetItem();
    QTreeWidgetItem *topLevelItemInputt = new QTreeWidgetItem();
    QTreeWidgetItem *topLevelItemDisplay = new QTreeWidgetItem();
    QTreeWidgetItem *topLevelItemGrouping = new QTreeWidgetItem();
    QTreeWidgetItem *topLevelItemItems = new QTreeWidgetItem();


    ui->tools->addTopLevelItem(topLevelItemLayout);
    ui->tools->addTopLevelItem(topLevelItemControl);
    ui->tools->addTopLevelItem(topLevelItemInputt);
    ui->tools->addTopLevelItem(topLevelItemDisplay);
    ui->tools->addTopLevelItem(topLevelItemGrouping);
    ui->tools->addTopLevelItem(topLevelItemItems);


    ui->tools->setItemWidget(topLevelItemLayout, 0, lbLayout);
    ui->tools->setItemWidget(topLevelItemControl, 0, lbControl);
    ui->tools->setItemWidget(topLevelItemInputt, 0, lbInput);
    ui->tools->setItemWidget(topLevelItemDisplay, 0, lbDisplay);
    ui->tools->setItemWidget(topLevelItemGrouping, 0, lbGrouping);
    ui->tools->setItemWidget(topLevelItemItems, 0, lbItems);


    topLevelItemControl->addChild(seconLevelItemButton);
    topLevelItemControl->addChild(seconLevelItemCheckBox);
    topLevelItemControl->addChild(seconLevelItemRadioButton);
    ui->tools->setItemWidget(seconLevelItemButton, 0, btButtonItem);
    ui->tools->setItemWidget(seconLevelItemCheckBox, 0, cbCheckBoxItem);
    ui->tools->setItemWidget(seconLevelItemRadioButton, 0, rbRadioButton);

   /*
    *
    childItem->addChild(nestedChildItem);

    ui->tools->setItemWidget(topLevelItem, 0, lbLayout);
      ui->tools->setItemWidget(childItem, 0, childButton);
      ui->tools->setItemWidget(childItem1, 0, lb21);
      ui->tools->setItemWidget(nestedChildItem, 0, nestedChildButton);
*/
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::resizeEvent(QResizeEvent* event){

    double posY = 10;
    double height = size().height() - 20;

    double canvasPosX = 320;
    double canvasWidth = (size().width() * 0.97) - 620;

    double detailsPosX = (canvasWidth) + 320;


    ui->tools->resize(300, height);
    ui->tools->move(10, posY);

    ui->canvas->resize(canvasWidth, height);
    ui->canvas->move(canvasPosX, posY);

    ui->details->resize(300, height);
    ui->details->move(detailsPosX, posY);
}
