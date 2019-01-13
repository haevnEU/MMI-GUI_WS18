#ifndef SELECTIONMODEL_H
#define SELECTIONMODEL_H

#include <QWidget>
#include <QObject>

namespace haevn{
    namespace core{
        namespace models{
            class SelectionModel : public QObject{
                Q_OBJECT
            // public static methods
            public:
                static SelectionModel* getInstance();
            // static variables
            private:
                static SelectionModel* s_instance;

            // public methods
            public:
                virtual ~SelectionModel();

                void selectWidget(QWidget* selection);
                QWidget* getSelectedwidget();

                // private methods
            private:
                explicit SelectionModel();

                // no need for copy ctor
                SelectionModel(SelectionModel& another){}

            // protected variables
            protected:

                ///
                int m_height;

                ///
                int m_maxHeight;

                ///
                int m_minHeight;

                ///
                int m_width;

                ///
                int m_maxWidth;

                ///
                int m_minWidth;

                ///
                int m_posX;

                ///
                int m_posY;

                ///
                bool m_visibility;

                ///
                QString m_tooltip;

                ///
                QString m_content;

                QString m_name;

                ///
                QColor m_background;

                ///
                QColor m_foreground;

                QWidget* selectedWidget;

            signals:
                void selectedWidgetChanged(QWidget* visibility);

                  void heightChanged(int height);
                  void maxHeightChanged(int maxHeight);
                  void minHeightChanged(int minHeight);


                  void widthChanged(int width);
                  void maxWidthChanged(int maxWidth);
                  void minWidthChanged(int minWidth);

                  void positionChanged(int x, int y);
                 // void positionXChanged(int x);
                 // void positionYChanged(int y);

                  void nameChanged(QString name);

                  void visibilityChanged(bool visibility);
                  void tooltipChanged(QString tooltip);

               public slots:

                   /**
                    * @brief setHeight
                    * @param t_height
                    */
                   virtual void setHeight(int t_height) ;

                   /**
                    * @brief setMaxHeight
                    * @param t_maxHeight
                    */
                   virtual void setMaxHeight(int t_maxHeight) ;

                   /**
                    * @brief setMinHeight
                    * @param t_minHeight
                    */
                   virtual void setMinHeight(int t_minHeight) ;

                   /**
                    * @brief setWidth
                    * @param t_width
                    */
                   virtual void setWidth(int t_width) ;

                   /**
                    * @brief setMaxWidth
                    * @param t_maxWidth
                    */
                   virtual void setMaxWidth(int t_maxWidth) ;

                   /**
                    * @brief setMinWidth
                    * @param t_minWidth
                    */
                   virtual void setMinWidth(int t_minWidth) ;


                  virtual void setPosition(int t_x, int t_y);

                  virtual void setName(QString t_name);

                  //virtual void setPositionX(int t_x);

                  //virtual void setPositionY(int t_y);
                   /**
                    * @brief setVisibility
                    * @param t_visibility
                    */
                   virtual void setVisibility(bool t_visibility) ;

                  virtual void setTooltip(QString t_tooltip);



            };
        }
    }
}
#endif // SELECTIONMODEL_H
