#include "scene.h"

#include <QPushButton>

Scene::Scene(QObject *parent) : QGraphicsScene(parent)
{
    selectedItem = new QPushButton("TEST");
    addWidget(selectedItem);
//setMouseTracking(true); // E.g. set in your constructor of your widget.
}



void Scene::contextMenuEvent(QGraphicsSceneContextMenuEvent *event){

}

void Scene::dragEnterEvent(QGraphicsSceneDragDropEvent *event){

}

void Scene::dragMoveEvent(QGraphicsSceneDragDropEvent *event){

}

void Scene::dragLeaveEvent(QGraphicsSceneDragDropEvent *event){

}

void Scene::dropEvent(QGraphicsSceneDragDropEvent *event){

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
        GraphicsItem *item = itemAt(event->scenePos());
    }

}

void Scene::mouseMoveEvent(QGraphicsSceneMouseEvent *event){
    if(m_grab) selectedItem->move(event->scenePos().x(), event->scenePos().y());
}

void Scene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event){
    if(event->button() == Qt::MouseButton::LeftButton){
        m_grab = false;
    }
}

