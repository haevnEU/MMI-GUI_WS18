#include "widgethelper.h"

haevn::core::util::WidgetHelper::WidgetHelper(){

}

haevn::core::enums::e_Widget haevn::core::util::WidgetHelper::getType(QWidget* obj){

    if(QRadioButton* tmp = dynamic_cast<QRadioButton*>(obj)){
        return haevn::core::enums::control_RadioButton;
    } else if(QCheckBox* tmp = dynamic_cast<QCheckBox*>(obj)){
        return haevn::core::enums::control_CheckBox;
    } else if(QPushButton* tmp = dynamic_cast<QPushButton*>(obj)){
            return haevn::core::enums::control_Button;
    }

    else if(QComboBox* tmp = dynamic_cast<QComboBox*>(obj)){
        return haevn::core::enums::input_ComboBox;
    } else if(QLineEdit* tmp = dynamic_cast<QLineEdit*>(obj)){
        return haevn::core::enums::input_TextField;
    } else if(QSpinBox* tmp = dynamic_cast<QSpinBox*>(obj)){
        return haevn::core::enums::input_SpinBox;
    } else if(QDateEdit* tmp = dynamic_cast<QDateEdit*>(obj)){
        return haevn::core::enums::input_Date;
    } else if(QSlider* tmp = dynamic_cast<QSlider*>(obj)){
        return haevn::core::enums::input_Slider;
    }

    else if(QLabel* tmp = dynamic_cast<QLabel*>(obj)){
            return haevn::core::enums::display_Label;
    }else if(QProgressBar* tmp = dynamic_cast<QProgressBar*>(obj)){
        return haevn::core::enums::display_ProgressBar;
    }
    // WEBVIEW

    else if(QGroupBox* tmp = dynamic_cast<QGroupBox*>(obj)){
            return haevn::core::enums::grouping_GroupBox;
    }
    // RadioButton Group

    else if(QListWidget* tmp = dynamic_cast<QListWidget*>(obj)){
            return haevn::core::enums::dataVisualization_ListView;
    }else if(QTableWidget* tmp = dynamic_cast<QTableWidget*>(obj)){
        return haevn::core::enums::dataVisualization_TableView;
    }else if(QTreeWidget* tmp = dynamic_cast<QTreeWidget*>(obj)){
            return haevn::core::enums::dataVisualization_TreeView;
    }

    // LAYOUT

    else{
        return haevn::core::enums::uncat_nothing;
    }
}
