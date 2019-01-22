#ifndef RUNSCRIPTWIZARD_H
#define RUNSCRIPTWIZARD_H

#include <QWizard>

#include "core/lua/luahandle.h"
#include "core/export/fileio.h"
#include "core/models/model.h"
#include <QListWIdgetItem>

namespace Ui {
class RunScriptWizard;
}

namespace haevn{
    namespace view{
        class RunScriptWizard : public QWizard
        {
            Q_OBJECT

        public:
            explicit RunScriptWizard(haevn::core::models::Model* t_appModel, QWidget *parent = nullptr);
            ~RunScriptWizard();

        private:
            Ui::RunScriptWizard *ui;
            haevn::core::lua::LuaHandle* m_luaScriptHandler;
            haevn::core::models::Model* m_appModel;

        public slots:
            void itemSelectionChanged();
        };
    }
}

#endif // RUNSCRIPTWIZARD_H
