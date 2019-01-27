#include "hlistwidgetitem.h"

haevn::visual::HListWidgetItem::HListWidgetItem(QString t_key, QString t_data) : m_key(t_key), m_data(t_data){
    setText(t_key);
}

QString haevn::visual::HListWidgetItem::getKey(){
    return m_key;
}

QString haevn::visual::HListWidgetItem::getData(){
    return m_data;
}
