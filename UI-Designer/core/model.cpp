#include "model.h"

using namespace haevn::core;

Model* Model::s_instance = nullptr;
Model* Model::getInstance(QObject* parent){
    if(s_instance == nullptr){
        s_instance = new Model(parent);
    }
    return s_instance;
}



Model::Model(QObject *parent) : QObject(parent){
   m_items = new QList<QWidget*>();
}

Model::~Model(){
    if(m_items != nullptr){
        delete m_items;
        m_items = nullptr;
    }

}

void Model::addItem(QWidget* t_item){
    if(t_item == nullptr){
        return;
    }
    m_items->insert(m_items->size() + 1, t_item);
    emit itemAdded(t_item);
}
