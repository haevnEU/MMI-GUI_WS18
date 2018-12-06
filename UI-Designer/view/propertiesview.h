#ifndef PROPERTIESVIEW_H
#define PROPERTIESVIEW_H

#include <QDialog>
#include "core/data/baseproperties.h"

namespace Ui {
class PropertiesView;
}


class PropertiesView : public QDialog
{
    Q_OBJECT


public slots:
    void accept();
    void reject();

public:
    explicit PropertiesView(QWidget *parent = nullptr);
    ~PropertiesView();

    core::data::BaseProperties getProperties();
private:
    Ui::PropertiesView *ui;
    core::data::BaseProperties m_properties;

};

#endif // PROPERTIESVIEW_H
