#ifndef SELECTIONMODEL_H
#define SELECTIONMODEL_H

#include <QWidget>
#include <QObject>
#include "core/models/model.h"

namespace haevn{
    namespace core{
        namespace models{

            /**
             * @brief This class represent the current selection data
             * @details The Model class is a singleton object and
             * will contain data and operation which handles the
             * current selection.
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
            class SelectionModel : public QObject{
                Q_OBJECT
            // public static methods
            public:

                /**
                 * @brief Gets the instance
                 * @details GetInstance returns the existing instance,
                 * new one is created iff theres no existing one.
                 * @return SelectionModel - Only existing instance
                 */
                static SelectionModel* getInstance();
            // static variables
            private:

                /// Only allowed instance
                static SelectionModel* s_instance;

                /// Application model
                static haevn::core::models::Model* s_model;

            // public methods
            public:

                virtual ~SelectionModel();

                /**
                 * @brief Selects a widther
                 * @details This method will select a widget which should be represent
                 * by this class
                 * @param t_selection - Pointer to a widget which represent represent
                 * the current selected widget
                 */
                void selectWidget(QWidget* t_selection);

                /**
                 * @brief gets the current selected widget
                 * @details This method will return the current selected widget
                 * @return QWidget pointer to the current widget.
                 */
                QWidget* getSelectedwidget();

                // private methods
            private:

                /**
                 * @brief Constructor
                 * @details The constructor isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param parent
                 */
                explicit SelectionModel();                

                /**
                 * @brief Coppy constructor
                 * @details The copy constructor isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param another - Reference to another instance
                 */
                explicit SelectionModel(SelectionModel& another){}

                /**
                 * @brief Assignement operator.
                 * @details The assignement operator isnt available public.
                 * It isnt public available due to singleton pattern.
                 * @param another - Reference to another instance
                 */
                SelectionModel& operator=(SelectionModel& another){}

            // protected variables
            protected:

                /// This variable represents the height.
                int m_height;

                /// This variable represents the maximum height.
                int m_maxHeight;

                /// This variable represents the minimum height.
                int m_minHeight;

                /// This variable represents the width.
                int m_width;

                /// This variable represents the maixmum width.
                int m_maxWidth;

                /// This variable represents the minimum width.
                int m_minWidth;

                /// This variable represents the x coordinate.
                int m_posX;

                /// This variable represents the y coordinate.
                int m_posY;

                /// Iff this variable is true the object will be interactable.
                bool m_visibility;

                /// This variable represents the tooltip.
                QString m_tooltip;

                /// This variable represents the content.
                QString m_content;

                /// This variable represents the name of the object.
                QString m_name;

                /// This variable represents the background color.
                QColor m_background;

                /// This variable represents the foreground color.
                QColor m_foreground;

                /// This variable represent the current widget.
                QWidget* selectedWidget;

            signals:

                /**
                 * @brief Should be emited iff the current widget changed.
                 * @details This signal will be emited iff the current widget was changed.
                 * @param QWidget - pointer to the new selected widget.
                 */
                void selectedWidgetChanged(QWidget* t_widget);

                /**
                 * @brief Should be emited iff the height changed.
                 * @details This signal will be emited iff the height of the widget changed.
                 * @param t_height - New height of the widget.
                 */
                void heightChanged(int height);

                /**
                 * @brief Should be emited iff the maximum height changed.
                 * @details This signal will be emited iff the maximum height of the widget changed.
                 * @param maxHeight - New maximum height of the widget.
                 */
                void maxHeightChanged(int maxHeight);

                /**
                 * @brief Should be emited iff the minimum height changed.
                 * @details This signal will be emited iff the minimum height of the widget changed.
                 * @param minHeight - New minimum height of the widget.
                 */
                void minHeightChanged(int minHeight);                

                /**
                 * @brief Should be emited iff the width changed.
                 * @details This signal will be emited iff the width of the widget changed.
                 * @param width - New width of the widget.
                 */
                void widthChanged(int width);

                /**
                 * @brief Should be emited iff the maximum width changed.
                 * @details This signal will be emited iff the maximum width of the widget changed.
                 * @param maxWidth - New maximum width of the widget.
                 */
                void maxWidthChanged(int maxWidth);

                /**
                 * @brief Should be emited iff the mimium width changed.
                 * @details This signal will be emited iff the minimum width of the widget changed.
                 * @param minWidth - New minimum width of the widget.
                 */
                void minWidthChanged(int minWidth);

                /**
                 * @brief Should be emited iff the oordinates changed.
                 * @details This signal will be emited iff the coordinates of the widget changed.
                 * @param x - New coordinates x of the widget.
                 * @param y - New coordinates y of the widget.
                 */
                void positionChanged(int x, int y);

                /**
                 * @brief Should be emited iff the name changed.
                 * @details This signal will be emited iff the name of the widget changed.
                 * @param name - New name of the widget.
                 */
                void nameChanged(QString name);

                /**
                 * @brief Should be emited iff the enabled state changed.
                 * @details This signal will be emited iff the enabled state of the widget changed.
                 * @param enabled - New state of the widget.
                 */
                void enabledChanged(bool enabled);

                /**
                 * @brief Should be emited iff the tooltip changed.
                 * @details This signal will be emited iff the tooltip of the widget changed.
                 * @param tooltip - New tooltip of the widget.
                 */
                void tooltipChanged(QString tooltip);

              public slots:

                /**
                 * @brief Sets the height of the selected widget.
                 * @details This method will set the height of the selected widget.
                 * Nothin will change or emitted if t_height = m_height.
                 * @param t_height - New height of the selected widget
                 */
                virtual void setHeight(int t_height);

                /**
                 * @brief Sets the maximum height of the selected widget.
                 * @details This method will set the maximum height of the selected widget.
                 * Nothin will change or emitted if t_maxHeight = m_maxHeight.
                 * @param t_maxHeight - New maximum height of the selected widget
                 */
                virtual void setMaxHeight(int t_maxHeight);

                /**
                 * @brief Sets the minimum height of the selected widget.
                 * @details This method will set the minimum height of the selected widget.
                 * Nothin will change or emitted if t_minHeight = m_minHeight.
                 * @param t_minHeight - New minimum height of the selected widget
                 */
                virtual void setMinHeight(int t_minHeight);

                /**
                 * @brief Sets the width of the selected widget.
                 * @details This method will set the width of the selected widget.
                 * Nothin will change or emitted if t_width = m_width.
                 * @param t_width - New width of the selected widget
                 */
                virtual void setWidth(int t_width);

                /**
                 * @brief Sets the maximum width of the selected widget.
                 * @details This method will set the maximum width of the selected widget.
                 * Nothin will change or emitted if t_maxWidth = m_maxWidth.
                 * @param t_maxWidth - New maximum width of the selected widget
                 */
                virtual void setMaxWidth(int t_maxWidth);

                /**
                 * @brief Sets the minimum width of the selected widget.
                 * @details This method will set the minimum width of the selected widget.
                 * Nothin will change or emitted if t_minWidth = m_minWidth.
                 * @param t_width - New minimum width of the selected widget
                 */
                virtual void setMinWidth(int t_minWidth);

                /**
                 * @brief Sets the psotion the selected widget.
                 * @details This method will set the position of the selected widget. of the selected widget.
                 * Nothing will change or emitted if t_X = m_x and t_y == m_y.
                 * @param t_x - New x coordinate of the selected widget
                 * @param t_y - New y coordinate of the selected widget
                 */
                virtual void setPosition(int t_x, int t_y);

                /**
                 * @brief Sets the name the selected widget.
                 * @details This method will set the name of the selected widget.
                 * Nothing will change or emitted if t_name = m_name.
                 * @param t_name - New name of the selected widget
                 */
                virtual void setName(QString t_name);

                /**
                 * @brief Sets the state of the selected widget.
                 * @details This method will set the state of the selected widget.
                 * Nothing will change or emitted if t_interactable = m_interactable.
                 * @param t_interactable - New state of the selected widget
                 */
                virtual void setEnabled(bool t_interactable);

                /**
                 * @brief Sets the tooltip the selected widget.
                 * @details This method will set the tooltip of the selected widget.
                 * Nothing will change or emitted if t_tooltip = m_tooltip.
                 * @param t_tooltip - New tooltip of the selected widget
                 */
                virtual void setTooltip(QString t_tooltip);

            };
        }
    }
}
#endif // SELECTIONMODEL_H
