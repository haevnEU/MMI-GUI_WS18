#include "scene.h"

#include <QDebug>
#include <QPushButton>
#include <QGraphicsItem>
#include <QLabel>
#include <QTreeWidget>
#include "core/custom_objects/htreeview.h"
#include "core/enumerations.h"
#include "core/objects/buttons/hbutton.h"

using namespace haevn::core;

Scene::Scene(QObject *parent) : QGraphicsScene(parent){
    m_model = haevn::core::Model::getInstance();
    connect(m_model, &Model::itemAdded, this, &Scene::AddItem);
}

void Scene::AddItem(QWidget* t_item){
    qDebug() << "Item added";
    QGraphicsScene::addWidget(t_item);
}

void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragEnterEvent(event);
}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){

}

void Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
}


void Scene::dropEvent(QGraphicsSceneDragDropEvent *event){
    haevn::core::e_haevn_objects t_type = static_cast<haevn::core::e_haevn_objects>(event->mimeData()->property("type").toInt());
    core::objects::IAbstractObject* item2 = nullptr;

    QWidget* item;
    switch(t_type){
        // Control part
        case e_haevn_objects::control_Button:
            item = new objects::buttons::HButton();
       break;
        case e_haevn_objects::control_CheckBox:
            break;
        case e_haevn_objects::control_RadioButton:
            break;

        // input part
        case e_haevn_objects::input_Date:
            break;
        case e_haevn_objects::input_Time:
            break;
        case e_haevn_objects::input_Slider:
            break;
        case e_haevn_objects::input_SpinBox:
            break;
        case e_haevn_objects::input_ComboBox:
            break;
        case e_haevn_objects::input_TextField:
            break;

        // Display part
        case e_haevn_objects::display_Label:
            break;
        case e_haevn_objects::display_WebView:
            break;
        case e_haevn_objects::display_ProgressBar:
            break;

        // Layout part
        case e_haevn_objects::layout_Grid:
            break;
        case e_haevn_objects::layout_Canvas:
            break;
        case e_haevn_objects::layout_HBox:
            break;
        case e_haevn_objects::layout_VBox:
            break;

        // Grouping part
        case e_haevn_objects::grouping_GroupBox:
            break;
        case e_haevn_objects::grouping_RadioButtonGroup:
            break;
        // Items part
        case e_haevn_objects::dataVisualization_ListView:
            break;
        case e_haevn_objects::dataVisualization_TreeView:
            break;
        case e_haevn_objects::dataVisualization_TableView:
            break;
    }

    if(nullptr != item){
        int x = event->scenePos().x();
        int y = event->scenePos().y();
        item->move(x, y);
        selectedItem = item;

        m_model->addItem(item);
        addWidget(item);
        emit selectedItemChanged(selectedItem);
    }
}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = true;
        qDebug() << itemAt(event->scenePos().x(), event->scenePos().y(), QTransform())->isWidget();

        QWidget* tmp = dynamic_cast<QWidget*>(itemAt(event->scenePos().x(), event->scenePos().y(), QTransform()));

            selectedItem = tmp;
            emit selectedItemChanged(selectedItem);

    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
   // if(m_grab && selectedItem != nullptr) selectedItem->move(event->scenePos().x(), event->scenePos().y());
    qDebug() << event->scenePos().x() << " " << event->scenePos().y();
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = false;
    }
}

QWidget* Scene::getSelectedWidget(){
    return selectedItem;
}

