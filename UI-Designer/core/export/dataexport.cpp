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

haevn::core::exporting::DataExport::~DataExport(){}

void haevn::core::exporting::DataExport::setScenegraph(QList<QGraphicsItem*>* t_scenegraph){
    m_scenegraph = t_scenegraph;
}

int haevn::core::exporting::DataExport::getWidth(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->width();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getMinWidth(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->minimumWidth();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getMaxWidth(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->maximumWidth();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getHeigth(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->height();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getMinHeight(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->minimumHeight();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getMaxHeight(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->maximumHeight();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getPosX(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->pos().x();
    }
    return -1;
}

int haevn::core::exporting::DataExport::getPosY(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->pos().y();
    }
    return -1;
}

QString haevn::core::exporting::DataExport::getTooltip(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->toolTip();
    }
    return nullptr;
}

QString haevn::core::exporting::DataExport::getName(int id){
    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return proxyWidget->widget()->whatsThis();
    }
    return nullptr;
}

QString haevn::core::exporting::DataExport::getContent(int id){
    if(m_scenegraph != nullptr && id > m_scenegraph->size()){
        return 0;
    }

    QGraphicsItem* tmp = m_scenegraph->takeAt(id);
    if(QGraphicsProxyWidget* proxyWidget = static_cast<QGraphicsProxyWidget*>(tmp)){
        return "";
    }
    return nullptr;
}

