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

            int m_color;
            bool m_enabled;
            int m_visibility;
        };
    }
}

#endif // BASEPROPERTIES_H
