#ifndef WIDGETHELPER_H
#define WIDGETHELPER_H

#include <QWidget>
// Control
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>

// Input
#include <QTimeEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QSlider>
#include <QComboBox>
#include <QLineEdit>

// Display
#include <QProgressBar>
#include <QLabel>

// Grouping
#include <QGroupBox>
#include <QRadioButton>

// Items
#include <QTreeWidget>
#include <QTableWidget>
#include <QListWidget>

#include "core/enums/enumerations.h"

namespace haevn{
    namespace core{
        namespace util{

            /**
             * @brief This class is used as a helper class
             * @details This class converts an Qt widget into
             * a haevn::core::enums::e_widget
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
            class WidgetHelper{

            public:
                /**
                 * @brief Constructor
                 * @details Creates a new instance of this class.
                 */
                WidgetHelper();

                /**
                 * @brief Converts an Qt widget into haevn::core::enums::e_widget
                 * @details This method will convert an Qt widget into an
                 * haevn::core::enums::e_widget enum. It uses dynamic_cast to resolve
                 * Polymorphism from QWidget.
                 * @param obj - QWidget which is the widget to convert
                 */
                haevn::core::enums::e_widget getType(QWidget* obj);

            };
        }
    }
}


#endif // WIDGETHELPER_H
