#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <iostream>
#include <list>
#include "objects/iabstractobject.h"

namespace haevn{
    namespace core {

        /**
         * @brief The Model class
         */
        class Model : public QObject{
            Q_OBJECT
        public:

            ///
            explicit Model(QObject *parent = nullptr);

        signals:

            /**
             * @brief itemAdded
             * @param newItem
             */
            void itemAdded(objects::IAbstractObject* newItem);

        public slots:

            /**
             * @brief addItem
             * @param t_item
             */
            void addItem(objects::IAbstractObject* t_item);
        private:

            ///
            std::list<objects::IAbstractObject*>* m_items;
        };
    }
}
#endif // MODEL_H
