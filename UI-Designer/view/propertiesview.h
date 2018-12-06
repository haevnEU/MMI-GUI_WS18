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
    explicit PropertiesView(QWidget *parent = nullptr);
    ~PropertiesView();

    void load(core::objects::IBaseElement* baseElement);
private:
    Ui::PropertiesView *ui;
    core::objects::IBaseElement* m_baseElement;

};

#endif // PROPERTIESVIEW_H
