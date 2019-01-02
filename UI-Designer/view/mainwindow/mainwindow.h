#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/scene.h"
#include "core/model.h"
#include "core/objects/iabstractobject.h"
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

        public:
            explicit MainWindow(QWidget *parent = nullptr);
            ~MainWindow();
            void resizeEvent(QResizeEvent* t_event);
         //   void mousePressEvent(QMouseEvent* event);
            void link(core::Model* t_model);
        private:
            core::objects::IAbstractObject* selectedItem;

            haevn::core::custom_objects::HTreeView* tools;

            core::Model* m_model;
            core::Scene* m_scene;
            Ui::MainWindow *ui;
        };

    }
}
#endif // MAINWINDOW_H
