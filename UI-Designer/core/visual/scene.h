#ifndef SCENE_H
#define SCENE_H

#include <iostream>

#include <QDebug>

#include <QObject>
#include <QList>
#include <QMimeData>

#include <QKeyEvent>
#include <QMouseEvent>
#include <QGraphicsSceneMouseEvent>
#include <QFocusEvent>

#include <QGraphicsItem>
#include <QGraphicsScene>

#include <QGraphicsSceneContextMenuEvent>
#include <QGraphicsSceneDragDropEvent>

#include <QWidget>
#include <QGraphicsWidget>
#include <QGraphicsProxyWidget>
#include <QGraphicsItem>
#include <QTreeWidget>

// Control
#include <QPushButton>
#include <QCheckBox>
#include <QRadioButton>

// Input
#include <QTimeEdit>
#include <QDateEdit>
#include <QSpinBox>
#include <QSlider>
#include <QComboBox>
#include <QLineEdit>

// Display
#include <QProgressBar>
#include <QLabel>

// Grouping
#include <QGroupBox>
#include <QRadioButton>

// Items
#include <QTreeWidget>
#include <QTableWidget>
#include <QListWidget>

#include "core/models/selectionmodel.h"
#include "core/visual/htreeview.h"
#include "core/enumerations.h"


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

                QList<QWidget*>* getScenegraph();


            // private variables
            private:

                ///
                haevn::core::models::SelectionModel* m_selectionModel;

                ///
                bool m_grab = false;

                QList<QWidget*>* m_scenegraph;

                int m_buttonCounter;
                int m_checkBoxCounter;
                int m_radioButtonCounter;
                int m_timeCounter;
                int m_dateCounter;
                int m_spinBoxCounter;
                int m_sliderCounter;
                int m_comboBoxCounter;
                int m_textFieldCounter;

                int m_labelCounter;
                int m_progressBarCounter;

                int m_treeWidgetCounter;
                int m_tableWidgetCounter;
                int m_listViewCounter;

            signals:
                void itemAdded(QWidget* t_item);
                void selectedItemChanged(QWidget* widget);

            public slots:

            };
        }
    }
}
#endif // SCENE_H
