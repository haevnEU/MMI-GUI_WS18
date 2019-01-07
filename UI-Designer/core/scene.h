#ifndef SCENE_H
#define SCENE_H

#include <iostream>

#include <QObject>
#include <QGraphicsScene>
#include <QMouseEvent>
#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneDragDropEvent>
#include <QFocusEvent>
#include <QKeyEvent>
#include <QGraphicsSceneMouseEvent>
#include <QMimeData>

#include "core/objects/iabstractobject.h"
#include "core/model.h"

namespace haevn{
    namespace core {

        /**
         * @brief The Scene class
         */
        class Scene : public QGraphicsScene {
            Q_OBJECT
        public:
            /**
             * @brief Scene
             * @param parent
             */
            explicit Scene(QObject *parent = nullptr);

            /**
             * @brief dragEnterEvent
             * @param event
             */
            virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);

            /**
             * @brief dragMoveEvent
             * @param event
             */
            virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);

            /**
             * @brief dragLeaveEvent
             * @param event
             */
            virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);

            /**
             * @brief dropEvent
             * @param event
             */
            virtual void dropEvent(QGraphicsSceneDragDropEvent *event);

            /**
             * @brief mousePressEvent
             * @param event
             */
            virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

            /**
             * @brief mouseMoveEvent
             * @param event
             */
            virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

            /**
             * @brief mouseReleaseEvent
             * @param event
             */
            virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);


            QWidget* getSelectedWidget();

        signals:
            void itemAdded(QWidget* t_item);
            void selectedItemChanged(QWidget* widget);
        public slots:

            /**
             * @brief AddItem
             * @param t_item
             */
            void AddItem(QWidget* t_item);


        private:

            ///
            Model* m_model;

            ///
            QWidget* selectedItem;

            ///
            bool m_grab = false;
        };
    }
}
#endif // SCENE_H
