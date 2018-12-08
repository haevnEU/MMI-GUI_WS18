#ifndef PROPERTIESVIEW_H
#define PROPERTIESVIEW_H

#include <QDialog>

#include "core/objects/IBaseElement.h"

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
    explicit PropertiesView(core::objects::IBaseElement* t_properties, QWidget *parent = nullptr);
    ~PropertiesView();

    void load();

private:

    Ui::PropertiesView *ui;
    core::objects::IBaseElement* m_baseElement;
    core::objects::IBaseElement* m_properties;
};

#endif // PROPERTIESVIEW_H
