#include "model.h"

using namespace haevn::core;

Model::Model(QObject *parent) : QObject(parent){
   // m_items = new std::list<objects::IAbstractObject*>();
}

Model::~Model(){
   /* if(m_items != nullptr){
        delete m_items;
        m_items = nullptr;
    }*/

}

void Model::addItem(objects::IAbstractObject* t_item){
    if(t_item == nullptr){
        return;
    }
    m_items.push_back(t_item);
    emit itemAdded(t_item);
}
