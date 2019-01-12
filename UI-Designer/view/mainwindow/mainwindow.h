#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/scene.h"
#include "core/custom_objects/htreeview.h"

namespace Ui {
class MainWindow;
}
namespace haevn {
    namespace view {

        class MainWindow : public QMainWindow
        {
            Q_OBJECT
        signals:

        public slots:
            void widthChanged(int t_width);
            void maxWidthChanged(int t_width);
            void minWidthChanged(int t_width);

            void heightChanged(int t_height);
            void maxHeightChanged(int t_height);
            void minHeightChanged(int t_height);

            void contentChanged(QString t_content);
            void tooltipChanged(QString t_tooltip);
            void nameChanged(QString t_name);
            void posXChanged(int t_x);
            void posYChanged(int t_y);

            void positionChanged(int t_x, int t_y);

            void visibilityChanged(int t_visibility);

            void selectedWidgetChanged(QWidget* widget);

        public:
            explicit MainWindow(QWidget *parent = nullptr);
            ~MainWindow();
            void resizeEvent(QResizeEvent* t_event);
         //   void mousePressEvent(QMouseEvent* event);
        private:

            haevn::core::custom_objects::HTreeView* tools;

            core::Scene* m_scene;
            Ui::MainWindow *ui;
        };

    }
}
#endif // MAINWINDOW_H
