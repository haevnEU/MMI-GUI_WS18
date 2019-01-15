#include "model.h"

#include <QDebug>

haevn::core::models::Model* haevn::core::models::Model::s_instance = nullptr;
haevn::core::models::Model* haevn::core::models::Model::getInstance(){
    if(s_instance == nullptr){
        s_instance = new Model();
    }
    return s_instance;
}

haevn::core::models::Model::Model() : QObject(){
   m_scenegraph = new QList<QWidget*>();

}

haevn::core::models::Model::~Model(){
    if(m_scenegraph != nullptr){
        delete m_scenegraph;
        m_scenegraph = nullptr;
    }
}

QList<QWidget*>* haevn::core::models::Model::getScenegraph(){
    return m_scenegraph;
}

void haevn::core::models::Model::setResourcePath(QString t_resourcePath){
    m_resourcePath = t_resourcePath;
}

QString haevn::core::models::Model::getResourcePath(){
    return m_resourcePath;
}

void haevn::core::models::Model::removeItem(QWidget* t_item){
    m_scenegraph->removeOne(t_item);
}

void haevn::core::models::Model::addItem(QWidget* t_item){
    if(t_item == nullptr){
        return;
    }
    m_scenegraph->insert(m_scenegraph->size() + 1, t_item);
}
