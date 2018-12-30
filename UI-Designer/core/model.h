#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <iostream>
#include <list>
#include "objects/iabstractobject.h"

namespace haevn{
    namespace core {
        class Model : public QObject{
            Q_OBJECT
        public:
            explicit Model(QObject *parent = nullptr);

        signals:
            void itemAdded(objects::IAbstractObject* newItem);
        public slots:
            void addItem(objects::IAbstractObject* t_item);
        private:
            std::list<objects::IAbstractObject*>* m_items;
        };
    }
}
#endif // MODEL_H
