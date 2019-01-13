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
            explicit MainWindow(QWidget *parent = nullptr);
            ~MainWindow();
            void resizeEvent(QResizeEvent* t_event);

        // private variables
        private:

            haevn::core::visual::HTreeView* tools;
            haevn::core::visual::Scene* m_scene;
            Ui::MainWindow *ui;

        signals:

        public slots:
            void widthChanged(int t_width);
            void maxWidthChanged(int t_width);
            void minWidthChanged(int t_width);

            void heightChanged(int t_height);
            void maxHeightChanged(int t_height);
            void minHeightChanged(int t_height);

            void positionChanged(int t_x, int t_y);
            void posXChanged(int t_x);
            void posYChanged(int t_y);

            void nameChanged(QString t_name);
            void contentChanged(QString t_content);
            void tooltipChanged(QString t_tooltip);

            void visibilityChanged(int t_visibility);

            void selectedWidgetChanged(QWidget* widget);

            void loadTriggered(bool checked = false);
            void saveTriggered(bool checked = false);

        };

    }
}
#endif // MAINWINDOW_H
