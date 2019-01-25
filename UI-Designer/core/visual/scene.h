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

#include "core/models/model.h"
#include "core/models/selectionmodel.h"
#include "core/visual/htreeview.h"
#include "core/enums/enumerations.h"
#include "core/util/fileutils.h"


namespace haevn{
    namespace core {
        namespace visual{

            /**
             * @brief This class is a custom implementation of a
             * QGraphicsScene. It is used to enable interaction,
             * drag and drop operation.
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 15, 2019
             */
            class Scene : public QGraphicsScene {
                Q_OBJECT

            // public methods
            public:

                /**
                 * @brief Constructor
                 * @details The constructor will create and initialize important data.
                 * @param parent - default = nullptr, it could be a reference to the parent.
                 */
                explicit Scene(haevn::core::models::Model* t_applicationModel, QObject *parent = nullptr);

                virtual ~Scene();

                /**
                 * @brief Drag enter event occurres if a drag was detected.
                 * @details This event occurred iff a drag operation was detected.
                 * This method will handle all interaction which is aociated
                 * with the drag operation.
                 * @param event - This param contains all information about the drag operation.
                 */
                virtual void dragEnterEvent(QGraphicsSceneDragDropEvent *event);

                /**
                 * @brief Drag move event occurres if a drag move was detected.
                 * @details This event occurred iff a drag move operation was detected.
                 * This method will handle all interaction which is aociated
                 * with the drag operation.
                 * @param event - This param contains all information about the drag operation.
                 */
                virtual void dragMoveEvent(QGraphicsSceneDragDropEvent *event);

                /**
                 * @brief Drag leave event occurres if a mouse left without dropping was detected.
                 * @details This event occurred iff the mouse left the scene without dropping.
                 * This method will handle all interaction which is aociated
                 * with the drag operation.
                 * @param event - This param contains all information about the drag operation.
                 */
                virtual void dragLeaveEvent(QGraphicsSceneDragDropEvent *event);

                /**
                 * @brief Drop event occurres if a drop was detected.
                 * @details This event occurred iff the mouse dropped a previous dragged element.
                 * This method will handle all interaction which is aociated
                 * with the drop operation.
                 * @param event - This param contains all information about the drag operation.
                 */
                virtual void dropEvent(QGraphicsSceneDragDropEvent *event);

                /**
                 * @brief Mouse press event occurres if the mouse is pressed.
                 * @details This event occurred iff the mouse was pressed.
                 * This method will handle all interaction which is aociated
                 * with the mouse.
                 * @param event - This param contains all information about the mouse state.
                 */
                virtual void mousePressEvent(QGraphicsSceneMouseEvent *event);

                /**
                 * @brief Mouse press event occurres if the mouse moves.
                 * @details This event occurred iff the mouse moves.
                 * This method will handle all interaction which is aociated
                 * with the mouse.
                 * @param event - This param contains all information about the mouse state.
                 */
                virtual void mouseMoveEvent(QGraphicsSceneMouseEvent *event);

                /**
                 * @brief Mouse press event occurres if a mousebutton is released.
                 * @details This event occurred iff the mouse was pressed.
                 * This method will handle all interaction which is aociated
                 * with the mouse move.
                 * @param event - This param contains all information about the mouse state.
                 */
                virtual void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);

                /**
                 * @brief Returns the state of the grab variable.
                 * @details This method is used to determine the state of the grab variable.
                 * It returns true iff an object is dragged
                 * @return True iff an object is dragged
                 */
                bool isGrabbed();

                /**
                 * @brief Returns the selection model.
                 * @details This method is used to interact with the selectionmodel.
                 * The selectionmodel contains all base variable for the current selected widget.
                 * @return Selectionmodel
                 */
                haevn::core::models::SelectionModel* getSelectionModel();

                /**
                 * @brief Returns the scenegraph.
                 * @details This method is used to receive the scenegraph.
                 * @return Pointer to the scenegraph.
                 */
                QList<QWidget*>* getScenegraph();

            // private variables
            private:

                /**
                 * @brief  This variable represent the application model
                 */
                haevn::core::models::Model* m_applicationModel;

                /**
                 * @brief  This variable represent the selection model
                 */
                haevn::core::models::SelectionModel* m_selectionModel;

                /**
                 * @brief  This variable determines if an object is grabbed.
                 */
                bool m_grab = false;

                /**
                 * @brief  This variable contains all widgets, it must be synchronize with the model.
                 */
                QList<QWidget*>* m_scenegraph;

                /**
                 * @brief  This variable is used to count the instered buttons.
                 */
                int m_buttonCounter;

                /**
                 * @brief  This variable counts the instered checkbox.
                 */
                int m_checkBoxCounter;

                /**
                 * @brief  This variable counts the instered radionbutton.
                 */
                int m_radioButtonCounter;

                /**
                 * @brief  This variable counts the instered time input widgets.
                 */
                int m_timeCounter;

                /**
                 * @brief  This variable counts the instered date input widgets.
                 */
                int m_dateCounter;

                /**
                 * @brief  This variable counts the instered spinbox.
                 */
                int m_spinBoxCounter;

                /**
                 * @brief  This variable counts the instered slider.
                 */
                int m_sliderCounter;

                /**
                 * @brief  This variable counts the instered combobox.
                 */
                int m_comboBoxCounter;

                /**
                 * @brief  This variable counts the instered inputfield.
                 */
                int m_textFieldCounter;

                /**
                 * @brief  This variable counts the instered label.
                 */
                int m_labelCounter;

                /**
                 * @brief  This variable counts the instered progressbar.
                 */
                int m_progressBarCounter;


                /**
                 * @brief  This variable counts the instered treewidgets.
                 */
                int m_treeWidgetCounter;

                /**
                 * @brief  This variable counts the instered tables.
                 */
                int m_tableWidgetCounter;

                /**
                 * @brief  This variable counts the instered listwidgets.
                 */
                int m_listViewCounter;

            signals:


                /**
                 * @brief Emits the insertion of an element
                 * @details This signal will be emited iff an item was inserted
                 * into the scenegraph.
                 * @param t_item - Pointer to the item was added
                 */
                void itemAdded(QWidget* t_item);

                /**
                 * @brief Emits the change of the selected item
                 * @details This signal will be emitted iff a widget was selected
                 * @param t_item - Pointer to the item which should be added
                 */
                void selectedItemChanged(QWidget* t_item);

            public slots:
            };
        }
    }
}
#endif // SCENE_H
