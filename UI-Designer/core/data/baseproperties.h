#ifndef BASEPROPERTIES_H
#define BASEPROPERTIES_H

#include "QString"

namespace core{
    namespace data{

    // TODO THIS CLASS MUST BE IMPLEMENTED IT WILL HOLD DATA OF THE CURRENT PROPERTY WINDOW!
    // INSERT GETTER AND SETTER
        class BaseProperties
        {
        public:
            BaseProperties();
            ~BaseProperties();

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

        private:
            QString m_name;
            QString m_tooltip;
            QString m_action;

            double m_width;
            double m_minWidth;
            double m_maxWidth;

            double m_height;
            double m_minHeight;
            double m_maxHeight;

            bool m_enabled;

            int m_color;
            int m_visibility;
        };
    }
}

#endif // BASEPROPERTIES_H
