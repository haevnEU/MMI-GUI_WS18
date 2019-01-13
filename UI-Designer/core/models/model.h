#ifndef MODEL_H
#define MODEL_H

#include <QObject>
#include <QListWidget>

namespace haevn{
    namespace core {
        namespace models{
            /**
             * @brief The Model class
             */
            class Model : public QObject{
                Q_OBJECT

            // public static methods
            public:
                static Model* getInstance(QObject* parent = nullptr);

            // static variables
            private:
                static Model* s_instance;

             // public methods
             public:

                virtual ~Model();

                QList<QWidget*>* getScenegraph();

            // private methods
            private:
                ///
                explicit Model(QObject *parent = nullptr);
                // No need for copy ctor
                explicit Model(Model& another){}

            // private variables
            private:

                ///
                QList<QWidget*>* m_items;

            signals:


            public slots:

                /**
                 * @brief addItem
                 * @param t_item
                 */
                void addItem(QWidget* t_item);
                void removeItem(QWidget* t_item);
            };
        }
    }
}
#endif // MODEL_H
