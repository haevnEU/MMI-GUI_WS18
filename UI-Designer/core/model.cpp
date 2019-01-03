#include "model.h"

using namespace haevn::core;

Model::Model(QObject *parent) : QObject(parent){

}

void Model::addItem(objects::IAbstractObject* t_item){
    m_items->push_back(t_item);
    emit itemAdded(t_item);
}
