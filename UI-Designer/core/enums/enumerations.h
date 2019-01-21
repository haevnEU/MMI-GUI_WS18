#ifndef ENUMERATIONS_H
#define ENUMERATIONS_H

namespace haevn{
    namespace core{
        // this namespace contains all enumeration required by the application
        namespace enums{
            /**
             * @brief This class maps all possible widgets to an enum
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
                typedef enum {

                /**
                 * \brief Tool that describes nothing selected
                 */
                uncat_nothing,

                /**
                 * \brief Tool that describes button selected
                 */
                control_Button,

                /**
                 * \brief Tool that describes radiobutton selected
                 */
                control_RadioButton,

                /**
                 * \brief Tool that describes checkbox selected
                 */
                control_CheckBox,

                /**
                 * \brief Tool that describes nothing selected
                 */
                input_ComboBox,

                /**
                 * \brief Tool that describes input field selected
                 */
                input_TextField,

                /**
                 * \brief Tool that describes spinbox selected
                 */
                input_SpinBox,

                /**
                 * \brief Tool that describes date input field selected
                 */
                input_Date,


                /**
                 * \brief Tool that describes time input field selected
                 */
                input_Time,

                /**
                 * \brief Tool that describes slider selected
                 */
                input_Slider,

                /**
                 * \brief Tool that describes label selected
                 */
                display_Label,

                /**
                 * \brief Tool that describes progressbar selected
                 */
                display_ProgressBar,

                /**
                 * \brief Tool that describes webview selected
                 */
                display_WebView,


                    /// Tool that describes a groupbox is selected
                /**
                 * \brief Tool that describes nothing selected
                 */
                grouping_GroupBox,

                /**
                 * \brief Tool that describes radiobutton group selected
                 */
                grouping_RadioButtonGroup,

                /**
                 * \brief Tool that describes listview selected
                 */
                dataVisualization_ListView,

                /**
                 * \brief Tool that describes table view selected
                 */
                dataVisualization_TableView,

                /**
                 * \brief Tool that describes treeview selected
                 */
                dataVisualization_TreeView,

                /**
                 * \brief Tool that describes grid selected
                 */
                layout_Grid,

                /**
                 * \brief Tool that describes canvas selected
                 */
                layout_Canvas,

                /**
                 * \brief Tool that describes horizontal box selected
                 */
                layout_HBox,

                /**
                 * \brief Tool that describes vertical box selected
                 */
                layout_VBox

            } e_widget;
        }
    }
}
#endif // ENUMERATIONS_H
