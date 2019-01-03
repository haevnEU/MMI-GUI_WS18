#ifndef IABSTRACTOBJECT_H
#define IABSTRACTOBJECT_H

#include <QObject>
#include <QColor>
#include <QString>
#include <QWidget>
namespace haevn{
    namespace core {
        namespace objects {

           /**
            * @brief The IAbstractObject class
            */
           class IAbstractObject : virtual QWidget{


            public:

                /**
                 * @brief IAbstractObject//
                 */
                explicit IAbstractObject();

           public:

               /**
                * @brief setHeight
                * @param t_height
                */
               virtual void setHeight(double t_height) = 0;

               /**
                * @brief setMaxHeight
                * @param t_maxHeight
                */
               virtual void setMaxHeight(double t_maxHeight) = 0;

               /**
                * @brief setMinHeight
                * @param t_minHeight
                */
               virtual void setMinHeight(double t_minHeight) = 0;

               /**
                * @brief setWidth
                * @param t_width
                */
               virtual void setWidth(double t_width) = 0;

               /**
                * @brief setMaxWidth
                * @param t_maxWidth
                */
               virtual void setMaxWidth(double t_maxWidth) = 0;

               /**
                * @brief setMinWidth
                * @param t_minWidth
                */
               virtual void setMinWidth(double t_minWidth) = 0;

               /**
                * @brief setPosition
                * @param t_x
                * @param t_y
                */
               virtual void setPosition(double t_x, double t_y) = 0;

               /**
                * @brief setVisibility
                * @param t_visibility
                */
               virtual void setVisibility(bool t_visibility) = 0;

            protected:

                ///
                double m_height;

                ///
                double m_maxHeight;

                ///
                double m_minHeight;

                ///
                double m_width;

                ///
                double m_maxWidth;

                ///
                double m_minWidth;

                ///
                double m_posX;

                ///
                double m_posY;

                ///
                bool m_visibility;

                ///
                QString m_tooltip;

                ///
                QString m_content;

                ///
                QColor m_background;

                ///
                QColor m_foreground;

            };

        }
    }
}
#endif // IABSTRACTOBJECT_H
