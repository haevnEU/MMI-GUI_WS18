#ifndef RESULTPAGE_H
#define RESULTPAGE_H

#include <QWizardPage>
#include <QLabel>
#include <QLineEdit>
#include <QTextEdit>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QProgressBar>
#include <QThread>

#include "core/util/fileutils.h"
#include "core/lua/luahandle.h"
#include "core/models/model.h"

namespace haevn{
    namespace view{
        namespace wizzard{

            /**
             * @brief This class is a custom implementation of a
             * QWizardPage. It is used to implement a simple wizzard
             * @author Nils Milewski
             * @version 1.0
             * @date Jan 24, 2019
             */
            class ResultPage : public QWizardPage{
                Q_OBJECT

            private:
                /**
                 * @brief This is an ui element which represent basic information about the current page
                 */
                QLabel* m_lbInformation;

                /**
                 * @brief This is an ui element which represent the result, it is possible to copy the content.
                 */
                QTextEdit* m_leResult;

                /**
                 * @brief This is an ui element which enables/disables file export
                 */
                QCheckBox* m_cbExportToFile;

                /**
                 * @brief This variable is an ui element which indicates large operation endurance
                 */
                QProgressBar* m_progressBar;

                /**
                 * @brief This variable represent the application model
                 */
                haevn::core::models::Model* m_applicationModel;

            public:
                /**
                 * @brief Constructor
                 * @details The constructor will create and initialize important data.
                 * @param t_appModel - this parameter contains the application model
                 * @param parent - default = nullptr, it could be a reference to the parent.
                 */
                explicit ResultPage(haevn::core::models::Model* t_applicationModel, QWidget* parent = nullptr);

                ~ResultPage();

                /**
                 * @brief Returns the result of the lua script.
                 * @details This method will return the result wich was produced by the lua script.
                 * It will display the code which is importable or an error message
                 * @return Result of the lua script
                 */
                QString getResult();

                /**
                 * @brief Returns the state of the export checkbox.
                 * @details This method is used to determine the state of the export checkbox.
                 * It returns true iff the checkbox is checked, which means the result of the script
                 * should be exported to a txt file.
                 * @return True iff the checkbox is checked
                 */
                bool isExportChecked();

            private:
                /**
                 * @brief ShowEvent, occurres if the page is visible
                 * @details This event occurred iff this page is activated.
                 * This method will handle the everything which should happened if this page is shown.
                 * @param event - This param contains all information about the show operation.
                 */
                void showEvent(QShowEvent* event);

                /**
                 * @brief ShowEvent, occurres if the page left
                 * @details This event occurred iff this page is left.
                 * This method will handle the everything which should happened if this page is shown.
                 * @param event - This param contains all information about the show operation.
                 */
                void leaveEvent(QEvent *event);

            };
        }
    }
}
#endif // RESULTPAGE_H
