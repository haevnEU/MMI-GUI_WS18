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
        mimeData->setProperty("type", currentItem()->data(0, Qt::ItemDataRole::UserRole));
        drag->setMimeData(mimeData);
        Qt::DropAction dropAction = drag->exec();
    }


}

void HTreeView::addRootHeader(QString name){

    QTreeWidgetItem* treeItemButton = new QTreeWidgetItem();
    treeItemButton->setText(0, name);
    addTopLevelItem(treeItemButton);

}

void HTreeView::insertData(int level, e_haevn_objects t_type){

    if(level >= getTopLevelCount()){
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem();
    QString tooltip;
    // Used to set different UI types as tree view data
    switch(t_type){
        // Control part
        case e_haevn_objects::control_Button:
          tooltip = "Button";
          item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::control_Button);
          break;
        case e_haevn_objects::control_CheckBox:
          tooltip = "CheckBox";
          item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::control_CheckBox);
          break;
        case e_haevn_objects::control_RadioButton:
          tooltip = "RadioButton";
          item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::control_RadioButton);
          break;

        // input part
        case e_haevn_objects::input_Date:
          tooltip = "Date";
          item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::input_Date);
          break;
        case e_haevn_objects::input_Time:
          tooltip = "Time";
          item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::input_Time);
          break;
        case e_haevn_objects::input_Slider:
            tooltip = "Slider";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::input_Slider);
            break;
        case e_haevn_objects::input_SpinBox:
            tooltip = "SpinBox";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::input_SpinBox);
            break;
        case e_haevn_objects::input_ComboBox:
            tooltip = "ComboBox";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::input_ComboBox);
            break;
        case e_haevn_objects::input_TextField:
            tooltip = "TextField";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::input_TextField);
            break;

        // Display part
        case e_haevn_objects::display_Label:
            tooltip = "Label";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::display_Label);
            break;
        case e_haevn_objects::display_WebView:
            tooltip = "WebView";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::display_WebView);
            break;
        case e_haevn_objects::display_ProgressBar:
            tooltip = "ProgressBar";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::display_ProgressBar);
            break;

        // Layout part
        case e_haevn_objects::layout_Grid:
            tooltip = "Grid";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::layout_Grid);
            break;
        case e_haevn_objects::layout_Canvas:
            tooltip = "Canvas";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::layout_Canvas);
            break;
        case e_haevn_objects::layout_HBox:
            tooltip = "HBox";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::layout_HBox);
            break;
        case e_haevn_objects::layout_VBox:
            tooltip = "VBox";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::layout_VBox);
            break;

        // Grouping part
        case e_haevn_objects::grouping_GroupBox:
            tooltip = "GroupBox";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::grouping_GroupBox);
            break;
        case e_haevn_objects::grouping_RadioButtonGroup:
            tooltip = "RadioButtonGroup";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::grouping_RadioButtonGroup);
            break;
        // Items part
        case e_haevn_objects::dataVisualization_ListView:
            tooltip = "ListView";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::dataVisualization_ListView);
            break;
        case e_haevn_objects::dataVisualization_TreeView:
            tooltip = "TreeView";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::dataVisualization_TreeView);
            break;
        case e_haevn_objects::dataVisualization_TableView:
            tooltip = "TableView";
            item->setData(0, Qt::ItemDataRole::UserRole, e_haevn_objects::dataVisualization_TableView);
            break;
    }

    item->setToolTip(0, "Insert a " + tooltip);
    item->setText(0, tooltip);
    for(int i = 0; i < topLevelItemCount(); i++){
        if(i == level){
            topLevelItem(i)->insertChild(0, item);
            break;
        }
    }
}

int HTreeView::getTopLevelCount(){
    return topLevelItemCount();
}

