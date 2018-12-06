#ifndef PROPERTIESVIEW_H
#define PROPERTIESVIEW_H

#include <QDialog>

namespace Ui {
class PropertiesView;
}

class PropertiesView : public QDialog
{
    Q_OBJECT

public:
    explicit PropertiesView(QWidget *parent = nullptr);
    ~PropertiesView();

private:
    Ui::PropertiesView *ui;
};

#endif // PROPERTIESVIEW_H
