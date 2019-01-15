#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

namespace haevn{
    namespace core{
        // this namespace contains all enumeration required by the application
        namespace enums{
            typedef enum {

                /// Tool that describes nothing selected
                uncat_nothing,


                /// Tool that describes a button is selected
                control_Button,


                /// Tool that describes a radiobutton is selected
                control_RadioButton,


                /// Tool that describes a checkbox is selected
                control_CheckBox,


                /// Tool that describes a combobox is selected
                input_ComboBox,


                /// Tool that describes a text input field is selected
                input_TextField,


                /// Tool that describes a spinbox is selected
                input_SpinBox,


                /// Tool that describes a date input field is selected
                input_Date,


                /// Tool that describes a time input field is selected
                input_Time,


                /// Tool that describes a slider is selected
                input_Slider,



                /// Tool that describes a label is selected
                display_Label,


                /// Tool that describes a progressbar is selected
                display_ProgressBar,


                /// Tool that describes webview is selected
                display_WebView,


                /// Tool that describes a groupbox is selected
                grouping_GroupBox,

                /// Tool that describes a radiobutton group is selected
                grouping_RadioButtonGroup,



                /// Tool that describes a listview is selected
                dataVisualization_ListView,


                /// Tool that describes a table view is selected
                dataVisualization_TableView,


                /// Tool that describes a treeview is selected
                dataVisualization_TreeView,



                /// Tool that describes a grid layout is selected
                layout_Grid,


                /// Tool that describes a canvas layout is selected
                layout_Canvas,


                /// Tool that describes Horizontal box layout is selected
                layout_HBox,


                /// Tool that describes a vertical box layout is selected
                layout_VBox
            }e_Widget;
        }
    }
}
#endif // ENUMERATIONS_H
