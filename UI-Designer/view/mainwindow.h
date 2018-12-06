#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "propertiesview.h"
#include "app/app.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void handlePropertiesClicked();
    void onPropertiesViewClosed();
    void handleButtonAddClicked();
public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    app::App* m_app;
};

#endif // MAINWINDOW_H
