#include "model.h"

#include <QDebug>

haevn::core::models::Model* haevn::core::models::Model::s_instance = nullptr;
haevn::core::models::Model* haevn::core::models::Model::getInstance(QObject* parent){
    if(s_instance == nullptr){
        s_instance = new Model(parent);
    }
    return s_instance;
}

haevn::core::models::Model::Model(QObject *parent) : QObject(parent){
   m_items = new QList<QWidget*>();
}

haevn::core::models::Model::~Model(){
    if(m_items != nullptr){
        delete m_items;
        m_items = nullptr;
    }

}

QList<QWidget*>* haevn::core::models::Model::getScenegraph(){
    return m_items;
}

void haevn::core::models::Model::setResourcePath(QString t_resourcePath){
    m_resourcePath = t_resourcePath;
}

QString haevn::core::models::Model::getResourcePath(){
    return m_resourcePath;
}

void haevn::core::models::Model::removeItem(QWidget* t_item){
    m_items->removeOne(t_item);
}

void haevn::core::models::Model::addItem(QWidget* t_item){
    if(t_item == nullptr){
        return;
    }
    m_items->insert(m_items->size() + 1, t_item);
}
