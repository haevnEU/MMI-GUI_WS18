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
                class HButton : public QPushButton {
                    Q_OBJECT
                signals:
                   void heightChanged(int height);
                   void maxHeightChanged(int maxHeight);
                   void minHeightChanged(int minHeight);


                   void widthChanged(int width);
                   void maxWidthChanged(int maxWidth);
                   void minWidthChanged(int minWidth);

                   void positionChanged(int x, int y);

                   void visibilityChanged(bool visibility);

               public slots:

                public:
                   explicit HButton(QPushButton *parent = nullptr);

                   virtual ~HButton();
                   /**
                    * @see IAbstractObject#setHeight
                    */
                   void setHeight(int t_height);

                   /**
                    * @see iabstractobject#setMaxHeight
                    */
                   void setMaxHeight(int t_maxHeight);
                   void setMinHeight(int t_minHeight);

                   void setWidth(int t_width);
                   void setMaxWidth(int t_maxWidth);
                   void setMinWidth(int t_minWidth);

                   void setPosition(int t_x, int t_y);

                   void setVisibility(bool t_visibility);

                   IAbstractObject& operator=(const HButton& another);
                };

            }
        }
    }
}
#endif // HBUTTON_H
