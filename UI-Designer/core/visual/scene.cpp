#include "scene.h"

haevn::core::visual::Scene::Scene(QObject *parent) : QGraphicsScene(parent){
    m_selectionModel = haevn::core::models::SelectionModel::getInstance();
}

// Events

void haevn::core::visual::Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    QGraphicsScene::dragEnterEvent(event);
}

void haevn::core::visual::Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    //qDebug() << event->scenePos();
}

void haevn::core::visual::Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
}

void haevn::core::visual::Scene::dropEvent(QGraphicsSceneDragDropEvent *event){
    haevn::core::e_haevn_objects t_type = static_cast<haevn::core::e_haevn_objects>(event->mimeData()->property("type").toInt());


    QWidget* item = nullptr;
    switch(t_type){
        // Control part
        case e_haevn_objects::control_Button:
            item = new QPushButton();
       break;
        case e_haevn_objects::control_CheckBox:
            item = new QCheckBox();
            break;
        case e_haevn_objects::control_RadioButton:
            item = new QRadioButton();
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


        int x = static_cast<int>(event->scenePos().x());
        int y = static_cast<int>(event->scenePos().y());
        item->resize(100,50);
        m_selectionModel->selectWidget(item);
        m_selectionModel->setPosition(x, y);
        addWidget(m_selectionModel->getSelectedwidget());
        emit selectedItemChanged(m_selectionModel->getSelectedwidget());
    }
}

void haevn::core::visual::Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = true;
        QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
        if(nullptr != item){
            QGraphicsProxyWidget* tmp = static_cast<QGraphicsProxyWidget*>(item);
            m_selectionModel->selectWidget(tmp->widget());
            m_selectionModel->setPosition(event->scenePos().x(), event->scenePos().y());
            emit(selectedItemChanged(m_selectionModel->getSelectedwidget()));
        }
    }else if(event->button() == Qt::MouseButton::RightButton){
        QGraphicsItem* item = itemAt(event->scenePos(), QTransform());
        if(nullptr != item){
            removeItem(item);
            m_selectionModel->selectWidget(nullptr);
            emit(selectedItemChanged(m_selectionModel->getSelectedwidget()));
        }
    }
}

void haevn::core::visual::Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(m_grab && m_selectionModel->getSelectedwidget() != nullptr){
        int x = static_cast<int>(event->scenePos().x());
        int y = static_cast<int>(event->scenePos().y());

        qDebug() << "x: " << x << " y: " << y;
        m_selectionModel->setPosition(x, y);
    }

}

void haevn::core::visual::Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = false;
    }
}

// End events

bool haevn::core::visual::Scene::isGrabbed(){
    return m_grab;
}

haevn::core::models::SelectionModel* haevn::core::visual::Scene::getSelectionModel(){
    return m_selectionModel;
}

QList<QGraphicsItem*> haevn::core::visual::Scene::getScenegraph(){
    return items();
}
