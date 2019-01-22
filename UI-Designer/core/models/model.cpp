#include "model.h"

haevn::core::models::Model::Model() : QObject(){
    m_scenegraph = new QList<QWidget*>();
    m_scripts = new QMap<QString, QString>();
}

haevn::core::models::Model::~Model(){
    if(m_scenegraph != nullptr){
        delete m_scenegraph;
        m_scenegraph = nullptr;
    }
    if(m_scripts != nullptr){
        delete m_scripts;
        m_scripts = nullptr;
    }
}

void haevn::core::models::Model::insertScript(QString name, QString path){
    m_scripts->insert(name, path);
}

QMap<QString, QString>* haevn::core::models::Model::getScripts(){
    return m_scripts;
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
