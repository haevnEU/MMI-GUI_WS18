#include "scene.h"

#include <QPushButton>
#include <QGraphicsItem>
#include <QLabel>
#include <QTreeWidget>
#include "core/custom_objects/htreeview.h"

using namespace haevn::core;

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{

    selectedItem = new QPushButton("TEST");
    addWidget(selectedItem);
//setMouseTracking(true); // E.g. set in your constructor of your widget.
}


void Scene::AddItem(core::objects::IAbstractObject* t_item){
    //QGraphicsScene::addWidget(t_item);
}


void Scene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

}

void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){
    std::cout << "Drag entered" << std::endl;
}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){
    std::cout << "drag move" << std::endl;
    std::cout << event->scenePos().x() << " " << event->scenePos().y() << std::endl;
}

void Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){
    std::cout << "Drag leave" << std::endl;
}


void Scene::dropEvent(QGraphicsSceneDragDropEvent *event){
    if(event->mimeData()->hasText() || true){
        std::cout << "DROP: " <<  event->mimeData()->text().toStdString() << std::endl;
    }
}

void Scene::focusInEvent(QFocusEvent *event){

}

void Scene::focusOutEvent(QFocusEvent *event){

}

void Scene::helpEvent(QGraphicsSceneHelpEvent *event){

}

void Scene::keyPressEvent(QKeyEvent *event){

}

void Scene::keyReleaseEvent(QKeyEvent *event){


}

void Scene::mousePressEvent(QGraphicsSceneMouseEvent *event){

    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = true;
        // ?!
    }
}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(m_grab && selectedItem != nullptr) selectedItem->move(event->scenePos().x(), event->scenePos().y());
    std::cout << event->scenePos().x() << " " << event->scenePos().y() << std::endl;
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = false;
    }
}

