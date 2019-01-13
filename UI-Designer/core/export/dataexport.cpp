#include "dataexport.h"
#include <QDebug>

// singleton pattern

haevn::core::exporting::DataExport* haevn::core::exporting::DataExport::s_instance = nullptr;
haevn::core::exporting::DataExport* haevn::core::exporting::DataExport::getInstance(QObject* parent){
    if(s_instance == nullptr){
        s_instance = new DataExport(parent);
    }
    return s_instance;
}

// End singleton pattern

haevn::core::exporting::DataExport::DataExport(QObject *parent) : QObject(parent){
    m_scenegraph = new QList<QWidget*>();
}
haevn::core::exporting::DataExport::~DataExport(){
    delete m_scenegraph;
}

int haevn::core::exporting::DataExport::getWidth(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->width();
}

int haevn::core::exporting::DataExport::getMinWidth(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->minimumWidth();
}

int haevn::core::exporting::DataExport::getMaxWidth(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->maximumWidth();
}

int haevn::core::exporting::DataExport::getHeigth(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->height();
}

int haevn::core::exporting::DataExport::getMinHeight(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->minimumHeight();
}

int haevn::core::exporting::DataExport::getMaxHeight(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->maximumHeight();
}

int haevn::core::exporting::DataExport::getPosX(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->pos().x();
}

int haevn::core::exporting::DataExport::getPosY(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->pos().y();
}

QString haevn::core::exporting::DataExport::getTooltip(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->toolTip();
}

QString haevn::core::exporting::DataExport::getName(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return m_scenegraph->takeAt(id)->whatsThis();
}

QString haevn::core::exporting::DataExport::getContent(int id){
    if(m_scenegraph == nullptr || id > m_scenegraph->size()){
        return 0;
    }
    return "";
}
QString haevn::core::exporting::DataExport::toString(){

    QString str = "";
    for(int i = 0; i < m_scenegraph->size(); i++){
        str.append(toString(i));
    }

}

QString haevn::core::exporting::DataExport::toString(int id){

    return QString("Name: ").append(getName(id)).append("\n")
            .append("Width: ").append(QString::number(getWidth(id))).append("\n")
            .append("MaxWidth: ").append(QString::number(getMaxWidth(id))).append("\n")
            .append("MinWidth: ").append(QString::number(getMinWidth(id))).append("\n")
            .append("Height: ").append(QString::number(getHeigth(id))).append("\n")
            .append("Height: ").append(QString::number(getMaxHeight(id))).append("\n")
            .append("Height: ").append(QString::number(getMinHeight(id))).append("\n")
            .append("Position [x/y]: [").append(QString::number(getPosX((id)))).append("/").append(QString::number(getPosY(id))).append("\n")
            .append("Tooltip: ").append(getTooltip(id)).append("\n")
            .append("Content: ").append(getContent(id)).append("\n");
}

