#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QDebug>
#include <iostream>
#include <QMouseEvent>
#include <QMainWindow>

#include <QSpinBox>

#include "core/enumerations.h"
#include "core/visual/scene.h"
#include "core/visual/htreeview.h"

namespace Ui {
class MainWindow;
}
namespace haevn {
    namespace view {

        class MainWindow : public QMainWindow
        {
            Q_OBJECT

        // public methods
        public:

            /**
             * @brief MainWindow
             * @param parent
             */
            explicit MainWindow(QWidget *parent = nullptr);

            ~MainWindow();

            /**
             * @brief resizeEvent
             * @param t_event
             */
            void resizeEvent(QResizeEvent* t_event);

        // private variables
        private:

            ///
            haevn::core::visual::HTreeView* tools;

            ///
            haevn::core::visual::Scene* m_scene;

            ///
            Ui::MainWindow *ui;

        signals:

        public slots:

            /**
             * @brief widthChanged
             * @param t_width
             */
            void widthChanged(int t_width);

            /**
             * @brief maxWidthChanged
             * @param t_width
             */
            void maxWidthChanged(int t_width);

            /**
             * @brief minWidthChanged
             * @param t_width
             */
            void minWidthChanged(int t_width);

            /**
             * @brief heightChanged
             * @param t_height
             */
            void heightChanged(int t_height);

            /**
             * @brief maxHeightChanged
             * @param t_height
             */
            void maxHeightChanged(int t_height);

            /**
             * @brief minHeightChanged
             * @param t_height
             */
            void minHeightChanged(int t_height);

            /**
             * @brief positionChanged
             * @param t_x
             * @param t_y
             */
            void positionChanged(int t_x, int t_y);

            /**
             * @brief posXChanged
             * @param t_x
             */
            void posXChanged(int t_x);

            /**
             * @brief posYChanged
             * @param t_y
             */
            void posYChanged(int t_y);

            /**
             * @brief nameChanged
             * @param t_name
             */
            void nameChanged(QString t_name);

            /**
             * @brief contentChanged
             * @param t_content
             */
            void contentChanged(QString t_content);

            /**
             * @brief tooltipChanged
             * @param t_tooltip
             */
            void tooltipChanged(QString t_tooltip);

            /**
             * @brief enabledChanged
             * @param t_visibility
             */
            void enabledChanged(int t_visibility);

            /**
             * @brief selectedWidgetChanged
             * @param widget
             */
            void selectedWidgetChanged(QWidget* widget);

            /**
             * @brief loadTriggered
             * @param checked
             */
            void loadTriggered(bool checked = false);

            /**
             * @brief saveTriggered
             * @param checked
             */
            void saveTriggered(bool checked = false);

        };

    }
}
#endif // MAINWINDOW_H
