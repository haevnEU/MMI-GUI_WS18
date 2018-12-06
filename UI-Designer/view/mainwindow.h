#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "propertiesview.h"


namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public slots:
    void handlePropertiesClicked();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private:
    Ui::MainWindow *ui;
    PropertiesView* pv;
};

#endif // MAINWINDOW_H
