#ifndef IABSTRACTOBJECT_H
#define IABSTRACTOBJECT_H

#include <QObject>
#include <QColor>
#include <QString>

namespace haevn{
    namespace core {
        namespace objects {
           class IAbstractObject{
            public:
                explicit IAbstractObject();

            protected:
                double m_height;
                double m_maxHeight;
                double m_minHeight;

                double m_width;
                double m_maxWidth;
                double m_minWidth;

                double m_posX;
                double m_posY;

                bool m_visibility;

                QString m_tooltip;
                QString m_content;

                QColor m_background;
                QColor m_foreground;


             private:
                virtual void overrideMe() = 0;
            };
        }
    }
}
#endif // IABSTRACTOBJECT_H
