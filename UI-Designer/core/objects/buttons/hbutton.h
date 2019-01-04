#ifndef HBUTTON_H
#define HBUTTON_H

#include <QObject>
#include <QWidget>
#include <QPushButton>

#include "core/objects/iabstractobject.h"
namespace haevn{
    namespace core{
        namespace objects{
            namespace buttons{

            // TODO
                class HButton : public QPushButton, public IAbstractObject{
                    Q_OBJECT
                signals:
                   void heightChanged(double height);
                   void maxHeightChanged(double maxHeight);
                   void minHeightChanged(double minHeight);


                   void widthChanged(double width);
                   void maxWidthChanged(double maxWidth);
                   void minWidthChanged(double minWidth);

                   void positionChanged(double x, double y);

                   void visibilityChanged(bool visibility);

               public slots:

                public:
                   explicit HButton(QPushButton *parent = nullptr);

                   /**
                    * @see IAbstractObject#setHeight
                    */
                   void setHeight(double t_height);

                   /**
                    * @see iabstractobject#setMaxHeight
                    */
                   void setMaxHeight(double t_maxHeight);
                   void setMinHeight(double t_minHeight);

                   void setWidth(double t_width);
                   void setMaxWidth(double t_maxWidth);
                   void setMinWidth(double t_minWidth);

                   void setPosition(double t_x, double t_y);

                   void setVisibility(bool t_visibility);

                };

            }
        }
    }
}
#endif // HBUTTON_H
