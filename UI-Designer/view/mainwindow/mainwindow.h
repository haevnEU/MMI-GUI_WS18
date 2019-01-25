#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <iostream>
#include <QMouseEvent>
#include <QMainWindow>
#include <QDesktopServices>
#include <QFileDialog>


#include "view/runscriptwizzard/runscriptwizard.h"

#include "core/enums/enumerations.h"
#include "core/visual/scene.h"
#include "core/visual/htreeview.h"
#include "core/lua/luahandle.h"
#include "core/models/model.h"
#include "core/util/fileutils.h"

namespace Ui {
class MainWindow;
}

namespace haevn {
    namespace view {

        /**
         * @brief This class is the main window, which is the root
         * for every other window/widget.
         * @author Nils Milewski
         * @version 1.0
         * @date Jan 15, 2019
         */
        class MainWindow : public QMainWindow
        {
            Q_OBJECT

        // public methods
        public:

            /**
             * @brief Constructor
             * @details The constructor will create and initialize important data.
             * @param parent - default = nullptr, it could be a reference to the parent.
             */
            explicit MainWindow(QWidget *parent = nullptr);

            ~MainWindow();

            /**
             * @brief reisze event occurres if the window was resized.
             * @details This event occurred iff the window was resized.
             * This method will handle all interaction which is aociated
             * with the resize event,e specially reposition the UI.
             * @param event - This param contains all information about the resize event.
             */
            void resizeEvent(QResizeEvent* t_event);

        // private variables
        private:

            /// This element contains all tools
            haevn::core::visual::HTreeView* tools;

            /// This element contains the scene
            haevn::core::visual::Scene* m_scene;


            haevn::core::models::Model* m_applicationModel;

            /// Qt variable
            Ui::MainWindow *ui;

        signals:

        public slots:

            /**
             * @brief Sets the width of the selected widget.
             * @details This method will set the width of the selected widget.
             * Nothing will change or emitted if t_width == m_Scene->getSelectionModel()->getWidth().
             * @param t_widtht - New width of the selected widget
             */
            void widthChanged(int t_width);

            /**
             * @brief Sets the maximum width of the selected widget.
             * @details This method will set the maximum width of the selected widget.
             * Nothing will change or emitted if t_width == m_Scene->getSelectionModel()->getMaxWidth().
             * @param t_width - New maximum width of the selected widget
             */
            void maxWidthChanged(int t_width);

            /**
             * @brief Sets the minimum width of the selected widget.
             * @details This method will set the minimum width of the selected widget.
             * Nothing will change or emitted if t_width == m_Scene->getSelectionModel()->getMinWidth().
             * @param t_width - New minimum width of the selected widget
             */
            void minWidthChanged(int t_width);

            /**
             * @brief Sets the height of the selected widget.
             * @details This method will set the height of the selected widget.
             * Nothing will change or emitted if t_height == m_Scene->getSelectionModel()->getHeight().
             * @param t_height - New height of the selected widget
             */
            void heightChanged(int t_height);

            /**
             * @brief Sets the maximum height of the selected widget.
             * @details This method will set the maximum height of the selected widget.
             * Nothing will change or emitted if t_height == m_Scene->getSelectionModel()->getMaxHeight().
             * @param t_height - New maximum height of the selected widget
             */
            void maxHeightChanged(int t_height);

            /**
             * @brief Sets the minimum height of the selected widget.
             * @details This method will set the minimum height of the selected widget.
             * Nothing will change or emitted if t_height == m_Scene->getSelectionModel()->getMinHeight().
             * @param t_height - New minimum height of the selected widget
             */
            void minHeightChanged(int t_height);

            /**
             * @brief Sets the position of the selected widget.
             * @details This method will set the position of the selected widget.
             * Nothing will change or emitted if
             * t_x == m_Scene->getSelectionModel()->getPosX() && t_Y == m_scene->getSelectionModel()-getPosY().
             * @param t_x - New x coordinate of the selected widget
             * @param t_y - New y coordinate of the selected widget
             */
            void positionChanged(int t_x, int t_y);

            /**
             * @brief Sets the x coordinate of the selected widget.
             * @details This method will set the x coordinate of the selected widget.
             * Nothing will change or emitted if t_x == m_Scene->getSelectionModel()->getPosX().
             * @param t_x - New x coordinate of the selected widget
             */
            void posXChanged(int t_x);

            /**
             * @brief Sets the y coordinate of the selected widget.
             * @details This method will set the y coordinate of the selected widget.
             * Nothing will change or emitted if t_y == m_Scene->getSelectionModel()->getPosY().
             * @param t_y - New y coordinate of the selected widget
             */
            void posYChanged(int t_y);

            /**
             * @brief Sets the name of the selected widget.
             * @details This method will set the name of the selected widget.
             * Nothing will change or emitted if t_name == m_Scene->getSelectionModel()->getName().
             * @param t_name - New name of the selected widget
             */
            void nameChanged(QString t_name);

            /**
             * @brief Sets the tooltip of the selected widget.
             * @details This method will set the tooltip of the selected widget.
             * Nothing will change or emitted if t_tooltip == m_Scene->getSelectionModel()->getTooltip().
             * @param t_tooltip - New tooltip of the selected widget
             */
            void tooltipChanged(QString t_tooltip);

            /**
             * @brief Sets the state of the selected widget.
             * @details This method will set the state of the selected widget.
             * Nothing will change or emitted if t_state == m_Scene->getSelectionModel()->gettState().
             * @param t_state - New tooltip of the selected widget
             */
            void enabledChanged(int t_state);

            /**
             * @brief Sets the seleected widget.
             * @details This method will set the selected widget.
             * Nothing will change or emitted if widget == m_Scene->getSelectionModel()->getSelectedWidget().
             * @param widget - New selected widget
             */
            void selectedWidgetChanged(QWidget* widget);            

            /**
             * @brief This slot is triggered when the menu build was clicked.
             * @details This method will handle the translation process into a specific lnaguage
             * It will use a default lua script.
             * @param checked - Qt internal.
             */
            void buildTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu new scene was clicked.
             * @details This method will create a new scene
             * @param checked - Qt internal.
             */
            void newSceneTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu reload script library was clicked.
             * @details This method will read again the build.toc
             * @param checked - Qt internal.
             */
            void reloadScriptLibrary(bool checked = false);

            /**
             * @brief This slot is triggered when the menu repair was clicked.
             * @details This method will repair the application files.
             * @param checked - Qt internal.
             */
            void repairTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu reset was clicked.
             * @details This method will deletes all data inside data folder,
             * it also resets the build.toc file.
             * @param checked - Qt internal.
             */
            void resetTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu help was clicked.
             * @details This method will show the help file
             * @param checked - Qt internal.
             */
            void helpTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu about was clicked.
             * @details This method will show information and credits about the app
             * @param checked - Qt internal.
             */
            void aboutTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu aboutQt was clicked.
             * @details This method will show information about the Qt library
             * @param checked - Qt internal.
             */
            void aboutQtTriggered(bool checked = false);

            /**
             * @brief This slot is triggered when the menu aboutLUA was clicked.
             * @details This method will open the webbrowser with the lua website.
             * @param checked - Qt internal.
             */
            void aboutLuaTriggered(bool checked = false);

        };

    }
}
#endif // MAINWINDOW_H
