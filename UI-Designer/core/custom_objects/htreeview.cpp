#include "htreeview.h"

using namespace haevn::core::custom_objects;


HTreeView::HTreeView(QWidget *parent) : QTreeWidget(parent){
    setHeaderHidden(true);
}

void HTreeView::mousePressEvent(QMouseEvent *event){

    QTreeView::mousePressEvent(event);
    if(event->button() == Qt::RightButton){
        QDrag* drag = new QDrag(this);
        QMimeData* mimeData = new QMimeData();

        mimeData->setText(currentItem()->text(0));
        drag->setMimeData(mimeData);
        Qt::DropAction dropAction = drag->exec();
    }


}

void HTreeView::addRootHeader(QString name){

    QTreeWidgetItem* treeItemButton = new QTreeWidgetItem();
    treeItemButton->setText(0, name);
    addTopLevelItem(treeItemButton);

}

void HTreeView::insertData(int level, QString tooltip){

    if(level >= getTopLevelCount()){
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem();
    item->setToolTip(0, "Insert a " + tooltip);
    item->setText(0, tooltip);
    for(int i = 0; i < topLevelItemCount(); i++){
        if(i == level){
            topLevelItem(i)->insertChild(0, item);
            break;
        }
    }
    // setItemWidget(item, 0, widget);
}

int HTreeView::getTopLevelCount(){
    return topLevelItemCount();
}

