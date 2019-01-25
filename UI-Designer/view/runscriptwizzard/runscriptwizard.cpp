#include "runscriptwizard.h"

haevn::view::RunScriptWizard::RunScriptWizard(int width, int height, haevn::core::models::Model* t_appModel, QWidget *parent) : QWizard(parent){

    setMinimumSize(width, height);
    setMaximumSize(width, height);
    resize(width, height);

    m_introPage = new haevn::view::wizzard::IntroPage();
    m_scriptPage = new haevn::view::wizzard::ScriptPage(t_appModel);
    m_resultPage = new haevn::view::wizzard::ResultPage(t_appModel);

    addPage(m_introPage);
    addPage(m_scriptPage);
    addPage(m_resultPage);

    setWindowTitle("Export scenegraph");
}

haevn::view::RunScriptWizard::~RunScriptWizard(){
    delete m_introPage;
    m_introPage = nullptr;

    delete m_scriptPage;
    m_scriptPage = nullptr;

    delete m_resultPage;
    m_resultPage = nullptr;
}

void haevn::view::RunScriptWizard::accept(){

    if(m_resultPage->isExportChecked()){
        haevn::core::util::FileUtils().write(m_resultPage->getResult().toStdString().c_str());
    }
    QDialog::accept();
}
