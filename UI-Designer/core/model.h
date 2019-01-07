#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QListWidget>

namespace haevn{
    namespace core {

        /**
         * @brief The Model class
         */
        class Model : public QObject{
            Q_OBJECT

            // singleton
        private:
            static Model* s_instance;
        public:
            static Model* getInstance(QObject* parent = nullptr);

        private:
            ///
            explicit Model(QObject *parent = nullptr);
            Model(Model& another){}
            // end singleton
        public:

            virtual ~Model();
        signals:

            /**
             * @brief itemAdded
             * @param newItem
             */
            void itemAdded(QWidget* newItem);

        public slots:

            /**
             * @brief addItem
             * @param t_item
             */
            void addItem(QWidget* t_item);
        private:

            ///
            QList<QWidget*>* m_items;
        };
    }
}
#endif // MODEL_H
