#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "core/scene.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void resizeEvent(QResizeEvent* event);
private:

    Scene* m_scene;
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
