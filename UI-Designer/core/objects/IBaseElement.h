#ifndef BASEPROPERTIES_H
#define BASEPROPERTIES_H

#include "QString"

#include <iostream>
namespace core{
    namespace objects{

        /**
         * @file IBaseElement.h
         * @brief This header file will contain base information about an UI object
         *
         * @author Nils Mielwski (nils.milewski@stud.hs-ruhrwest.de)
         *
         * @version 1.0
         * @date 12/06/2018
         */
        class IBaseElement{

        private:
            /// This variable describes the UI element name
            QString m_name;

            /// This variables contains the tooltip
            QString m_tooltip;

            /// This variable contains an action which the UI element should execute
            QString m_action;

            /// Current width of the UI element
            double m_width;


            /// Minimum width of the UI element
            double m_minWidth;

            /// Maximum width of the UI element
            double m_maxWidth;

            /// current height vof the UI element
            double m_height;

            /// Minimum height vof the UI element
            double m_minHeight;

            /// Maximum height vof the UI element
            double m_maxHeight;

            /// This variable contians information if the UI element is interactable
            bool m_enabled;

            /// Color of the UI element
            int m_color;

            /// Visibility of the UI element
            int m_visibility;

        public:

            /**
             * This method will be used to construct a base element
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/06/2018
             */
            IBaseElement();

            /**
             * This method will be used to detruct a base element of the application
             * @author Nils Milewski (nils.milewski@stud.hs-ruhrwest.de)
             * @date 12/06/2018
             */
            virtual ~IBaseElement();

            QString getName();
            void setName(QString t_name);

            QString getToolTip();
            void setToolTip(QString t_tooltip);

            QString getAction();
            void setAction(QString t_action);

            double getWidth();
            void setWidth(double t_width);

            double getMaxWidth();
            void setMaxWidth(double t_width);

            double getMinWidth();
            void setMinWidth(double t_width);

            double getHeight();
            void setHeight(double t_width);

            double getMaxHeight();
            void setMaxHeight(double t_width);

            double getMinHeight();
            void setMinHeight(double t_width);

            bool getEnabled();
            void setEnabled(bool t_enabled);

            int getColor();
            void setColor(int t_color);

            int getVisibility();
            void setVisibility(int t_visibility);

            void clear();

            friend std::ostream& operator<< (std::ostream& os, const IBaseElement& input)
            {
                os << "[Name] " << input.m_name.toStdString() << std::endl
                   << "[ToolTip] " << input.m_tooltip.toStdString() << std::endl
                   << "[Action] " << input.m_action.toStdString() << std::endl
                   << "[Width] " << input.m_width << std::endl
                   << "[MinWidth] " << input.m_minWidth << std::endl
                   << "[MaxWidth] " << input.m_maxWidth << std::endl
                   << "[Height] " << input.m_height << std::endl
                   << "[MinHeight] " << input.m_minHeight << std::endl
                   << "[MaxHeight] " << input.m_maxHeight << std::endl
                   << "[Enabled] " << input.m_enabled << std::endl
                   << "[Visibility] " << input.m_visibility << std::endl
                   << "[Color] " << input.m_color << std::endl;
                return os;
            }

        private:
            virtual void onlyUseToCreateAnAbstractClass() = 0;
        };
    }
}

#endif // BASEPROPERTIES_H
