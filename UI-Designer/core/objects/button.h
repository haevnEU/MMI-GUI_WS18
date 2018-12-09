#ifndef BUTTON_H
#define BUTTON_H

#include "IBaseElement.h"
#include <QPushButton>

namespace core {
    namespace objects {

        class Button : public IBaseElement, public QPushButton
        {
        public:
            Button(QString t_text);

            void setName(QString t_name);

            void setToolTip(QString t_tooltip);

            void setAction(QString t_action);

            void setWidth(double t_width);

            void setMaxWidth(double t_width);

            void setMinWidth(double t_width);

            void setHeight(double t_width);

            void setMaxHeight(double t_width);

            void setMinHeight(double t_width);

            void setEnabled(bool t_enabled);

            void setColor(int t_color);

            void setVisibility(int t_visibility);

            void setPosition(QPoint t_point);
        };
    } // namespace objects
} // namespace core

#endif // BUTTON_H
