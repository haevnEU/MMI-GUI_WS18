#ifndef HLISTWIDGETITEM_H
#define HLISTWIDGETITEM_H

#include <QObject>
#include <QWidget>
#include <QListWidgetItem>

namespace haevn{
    namespace visual{

        /**
         * @brief This class is a custom implementation of a
         * QListWidgetItem. It is used to add additional information to the
         * QListWidgetItem. Especially a key and the data which the key represent.
         * @author Nils Milewski
         * @version 1.0
         * @date Jan 24 2019
         */
        class HListWidgetItem : public QListWidgetItem{

        private:
            /**
             * @brief Key of the item, it is also the name and should be contained in a map
             */
            QString m_key;

            /**
             * @brief Data of the item, it should be contained as a value inside a map
             */
            QString m_data;

        public:
            /**
             * @brief Constructor
             * @details The constructor will create and initialize important data.
             * @param parent - default = nullptr, it could be a reference to the parent.
             */
            explicit HListWidgetItem(QString t_key, QString t_data);

            /**
             * @brief Returns the key of this item
             * @details This method will return the key of the item.
             * The key is the same as a name and it should be contained in a map
             * @return Key of this item
             */
            QString getKey();

            /**
             * @brief Returns the data of this item
             * @details This method will return the data of the item.
             * The data is the same as a value which should be contained in a map
             * @return Key of this item
             */
            QString getData();
        };

    }
}
#endif // HLISTWIDGETITEM_H
