#include "htreeview.h"

haevn::core::visual::HTreeView::HTreeView(QWidget *parent) : QTreeWidget(parent){
    setHeaderHidden(true);
}

void haevn::core::visual::HTreeView::startDrag(Qt::DropActions supportedActions){
    // Start of drag detected. The drag operation need some data
    // Create new drag object an QMimedata
    QDrag* drag = new QDrag(this);
    QMimeData* mimeData = new QMimeData();

    mimeData->setText(currentItem()->text(0));

    // One property is the type, a type is an enum which describes current selected item
    mimeData->setProperty("type", currentItem()->data(0, Qt::ItemDataRole::UserRole));
    drag->setMimeData(mimeData);
    Qt::DropAction dropAction = drag->exec();
}

void haevn::core::visual::HTreeView::addRootHeader(QString name){
    QTreeWidgetItem* treeItemButton = new QTreeWidgetItem();
    treeItemButton->setText(0, name);
    addTopLevelItem(treeItemButton);
}

void haevn::core::visual::HTreeView::insertData(int level, haevn::core::enums::e_widget t_type){
    // The item deepth shouldnt exceed the amount of top level header
    if(level >= getTopLevelCount()){
        return;
    }

    QTreeWidgetItem* item = new QTreeWidgetItem();
    QString tooltip;
    // Used to set different UI types as tree view data
    // The tooltip is the object type name, eg button, label ,etc.
    // The data is a customized enum, which represent all available ui elements
    switch(t_type){
        // Control part
        case haevn::core::enums::e_widget::control_Button:
          tooltip = "Button";
          item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::control_Button);
          break;
        case haevn::core::enums::e_widget::control_CheckBox:
          tooltip = "CheckBox";
          item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::control_CheckBox);
          break;
        case haevn::core::enums::e_widget::control_RadioButton:
          tooltip = "RadioButton";
          item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::control_RadioButton);
          break;

        // input part
        case haevn::core::enums::e_widget::input_Date:
          tooltip = "Date";
          item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::input_Date);
          break;
        case haevn::core::enums::e_widget::input_Time:
          tooltip = "Time";
          item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::input_Time);
          break;
        case haevn::core::enums::e_widget::input_Slider:
            tooltip = "Slider";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::input_Slider);
            break;
        case haevn::core::enums::e_widget::input_SpinBox:
            tooltip = "SpinBox";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::input_SpinBox);
            break;
        case haevn::core::enums::e_widget::input_ComboBox:
            tooltip = "ComboBox";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::input_ComboBox);
            break;
        case haevn::core::enums::e_widget::input_TextField:
            tooltip = "TextField";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::input_TextField);
            break;

        // Display part
        case haevn::core::enums::e_widget::display_Label:
            tooltip = "Label";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::display_Label);
            break;
        case haevn::core::enums::e_widget::display_WebView:
            tooltip = "WebView";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::display_WebView);
            break;
        case haevn::core::enums::e_widget::display_ProgressBar:
            tooltip = "ProgressBar";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::display_ProgressBar);
            break;

        // Layout part
        case haevn::core::enums::e_widget::layout_Grid:
            tooltip = "Grid";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::layout_Grid);
            break;
        case haevn::core::enums::e_widget::layout_Canvas:
            tooltip = "Canvas";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::layout_Canvas);
            break;
        case haevn::core::enums::e_widget::layout_HBox:
            tooltip = "HBox";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::layout_HBox);
            break;
        case haevn::core::enums::e_widget::layout_VBox:
            tooltip = "VBox";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::layout_VBox);
            break;

        // Grouping part
        case haevn::core::enums::e_widget::grouping_GroupBox:
            tooltip = "GroupBox";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::grouping_GroupBox);
            break;
        case haevn::core::enums::e_widget::grouping_RadioButtonGroup:
            tooltip = "RadioButtonGroup";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::grouping_RadioButtonGroup);
            break;
        // Items part
        case haevn::core::enums::e_widget::dataVisualization_ListView:
            tooltip = "ListView";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::dataVisualization_ListView);
            break;
        case haevn::core::enums::e_widget::dataVisualization_TreeView:
            tooltip = "TreeView";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::dataVisualization_TreeView);
            break;
        case haevn::core::enums::e_widget::dataVisualization_TableView:
            tooltip = "TableView";
            item->setData(0, Qt::ItemDataRole::UserRole, haevn::core::enums::e_widget::dataVisualization_TableView);
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

int haevn::core::visual::HTreeView::getTopLevelCount(){
    return topLevelItemCount();
}

