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
            class WidgetHelper
            {
            public:
                WidgetHelper();

                haevn::core::enums::e_Widget getType(QWidget* obj);

            };
        }
    }
}


#endif // WIDGETHELPER_H
