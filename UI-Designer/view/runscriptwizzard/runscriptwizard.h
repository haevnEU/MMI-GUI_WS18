#ifndef RUNSCRIPTWIZARD_H
#define RUNSCRIPTWIZARD_H

#include <QWizard>

#include "core/lua/luahandle.h"
#include "core/util/fileutils.h"
#include "core/models/model.h"
#include "core/visual/hlistwidgetitem.h"

#include "view/runscriptwizzard/intropage.h"
#include "view/runscriptwizzard/scriptpage.h"
#include "view/runscriptwizzard/resultpage.h"

namespace haevn{
    namespace view{

        /**
         * @brief This class is a custom implementation of a
         * QWizard. It will contain all wizard pages and data.
         * @author Nils Milewski
         * @version 1.0
         * @date Jan 24, 2019
         */
        class RunScriptWizard : public QWizard{
            Q_OBJECT

        public:

            /**
             * @brief Constructor
             * @details The constructor will create and initialize important data.
             * @param t_appModel - this parameter contains the application model
             * @param parent - default = nullptr, it could be a reference to the parent.
             */
            explicit RunScriptWizard(int width, int height, haevn::core::models::Model* t_appModel, QWidget *parent = nullptr);

            ~RunScriptWizard();

            /**
             * @brief accept, occurres if the wizard is finished
             * @details This event occurred iff this wizzard is finished.
             * This method will handle the everything which should happened if this wizard is finished.
             */
            void accept() override;

        private:

            /**
             * @brief This variable represent the intro page
             */
            haevn::view::wizzard::IntroPage* m_introPage;


            /**
             * @brief This variable represent the result page
             */
            haevn::view::wizzard::ResultPage* m_resultPage;


            /**
             * @brief This variable represent the script page
             */
            haevn::view::wizzard::ScriptPage* m_scriptPage;

        };
    }
}

#endif // RUNSCRIPTWIZARD_H
