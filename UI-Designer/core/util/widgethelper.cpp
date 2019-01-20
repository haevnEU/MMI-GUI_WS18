#include "widgethelper.h"

haevn::core::util::WidgetHelper::WidgetHelper(){

}

haevn::core::enums::e_Widget haevn::core::util::WidgetHelper::getType(QWidget* obj){

    if(QPushButton* tmp = static_cast<QPushButton*>(obj)){
        return haevn::core::enums::control_Button;
    } else if(QRadioButton* tmp = static_cast<QRadioButton*>(obj)){
            return haevn::core::enums::control_RadioButton;
    } else if(QCheckBox* tmp = static_cast<QCheckBox*>(obj)){
        return haevn::core::enums::control_CheckBox;
    }

    else if(QComboBox* tmp = static_cast<QComboBox*>(obj)){
        return haevn::core::enums::input_ComboBox;
    } else if(QLineEdit* tmp = static_cast<QLineEdit*>(obj)){
        return haevn::core::enums::input_TextField;
    } else if(QSpinBox* tmp = static_cast<QSpinBox*>(obj)){
        return haevn::core::enums::input_SpinBox;
    } else if(QDateEdit* tmp = static_cast<QDateEdit*>(obj)){
        return haevn::core::enums::input_Date;
    } else if(QSlider* tmp = static_cast<QSlider*>(obj)){
        return haevn::core::enums::input_Slider;
    }

    else if(QLabel* tmp = static_cast<QLabel*>(obj)){
            return haevn::core::enums::display_Label;
    }else if(QProgressBar* tmp = static_cast<QProgressBar*>(obj)){
        return haevn::core::enums::display_ProgressBar;
    }
    // WEBVIEW

    else if(QGroupBox* tmp = static_cast<QGroupBox*>(obj)){
            return haevn::core::enums::grouping_GroupBox;
    }
    // RadioButton Group

    else if(QListWidget* tmp = static_cast<QListWidget*>(obj)){
            return haevn::core::enums::dataVisualization_ListView;
    }else if(QTableWidget* tmp = static_cast<QTableWidget*>(obj)){
        return haevn::core::enums::dataVisualization_TableView;
    }else if(QTreeWidget* tmp = static_cast<QTreeWidget*>(obj)){
            return haevn::core::enums::dataVisualization_TreeView;
    }

    // LAYOUT

    else{
        return haevn::core::enums::uncat_nothing;
    }
}
