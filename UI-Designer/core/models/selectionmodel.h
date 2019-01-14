#ifndef SELECTIONMODEL_H
#define SELECTIONMODEL_H

#include <QWidget>
#include <QObject>
#include "core/models/model.h"

namespace haevn{
    namespace core{
        namespace models{
            /**
             * @brief The SelectionModel class
             */
            class SelectionModel : public QObject{
                Q_OBJECT
            // public static methods
            public:

                /**
                 * @brief getInstance
                 * @return
                 */
                static SelectionModel* getInstance();
            // static variables
            private:

                ///
                static SelectionModel* s_instance;

                ///
                static haevn::core::models::Model* s_model;

            // public methods
            public:

                /**
                 * @brief ~SelectionModel
                 */
                virtual ~SelectionModel();

                /**
                 * @brief selectWidget
                 * @param selection
                 */
                void selectWidget(QWidget* selection);

                /**
                 * @brief getSelectedwidget
                 * @return
                 */
                QWidget* getSelectedwidget();

                // private methods
            private:
                /**
                 * @brief SelectionModel
                 */
                explicit SelectionModel();

                /**
                 * @brief SelectionModel
                 * @param another
                 */
                SelectionModel(SelectionModel& another){}

                /**
                 * @brief operator =
                 * @param another
                 * @return
                 */
                SelectionModel& operator=(SelectionModel& another){}

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

                /**
                 * @brief selectedWidgetChanged
                 * @param visibility
                 */
                void selectedWidgetChanged(QWidget* visibility);

                /**
                 * @brief heightChanged
                 * @param height
                 */
                void heightChanged(int height);

                /**
                 * @brief maxHeightChanged
                 * @param maxHeight
                 */
                void maxHeightChanged(int maxHeight);

                /**
                 * @brief minHeightChanged
                 * @param minHeight
                 */
                void minHeightChanged(int minHeight);

                /**
                 * @brief widthChanged
                 * @param width
                 */
                void widthChanged(int width);

                /**
                 * @brief maxWidthChanged
                 * @param maxWidth
                 */
                void maxWidthChanged(int maxWidth);

                /**
                 * @brief minWidthChanged
                 * @param minWidth
                 */
                void minWidthChanged(int minWidth);

                /**
                 * @brief positionChanged
                 * @param x
                 * @param y
                 */
                void positionChanged(int x, int y);

                /**
                 * @brief nameChanged
                 * @param name
                 */
                void nameChanged(QString name);

                /**
                 * @brief enabledChanged
                 * @param visibility
                 */
                void enabledChanged(bool visibility);

                /**
                 * @brief tooltipChanged
                 * @param tooltip
                 */
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

                /**
                 * @brief setPosition
                 * @param t_x
                 * @param t_y
                 */
                virtual void setPosition(int t_x, int t_y);

                /**
                 * @brief setName
                 * @param t_name
                 */
                virtual void setName(QString t_name);

                /**
                 * @brief setVisibility
                 * @param t_visibility
                 */
                virtual void setEnabled(bool t_visibility) ;

                /**
                 * @brief setTooltip
                 * @param t_tooltip
                 */
                virtual void setTooltip(QString t_tooltip);

            };
        }
    }
}
#endif // SELECTIONMODEL_H
