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
#include <QList>
#include <QGraphicsItem>
#include "core/models/selectionmodel.h"


#include <QDebug>
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>
#include <QGraphicsItem>
#include <QLabel>
#include <QTreeWidget>

#include "core/visual/htreeview.h"
#include "core/enumerations.h"

#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>

namespace haevn{
    namespace core {
        namespace visual{
            /**
             * @brief The Scene class
             */
            class Scene : public QGraphicsScene {
                Q_OBJECT

            // public methods
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

                bool isGrabbed();

                haevn::core::models::SelectionModel* getSelectionModel();

                QList<QGraphicsItem*> getScenegraph();


            // private variables
            private:

                ///
                haevn::core::models::SelectionModel* m_selectionModel;

                ///
                bool m_grab = false;

            signals:
                void itemAdded(QWidget* t_item);
                void selectedItemChanged(QWidget* widget);

            public slots:

            };
        }
    }
}
#endif // SCENE_H
