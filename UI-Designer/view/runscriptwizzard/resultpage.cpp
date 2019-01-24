#include "resultpage.h"

haevn::view::wizzard::ResultPage::ResultPage(haevn::core::models::Model* t_applicationModel, QWidget* parent) : QWizardPage (parent){
    m_leResult = new QTextEdit();
    m_lbInformation = new QLabel();
    m_applicationModel = t_applicationModel;


    setTitle(tr("Result"));
    m_lbInformation = new QLabel();
    m_lbInformation->setWordWrap(true);

    m_cbExportToFile = new QCheckBox();
    m_cbExportToFile->setText("Export to a txt file");

    QVBoxLayout* layout = new QVBoxLayout();
    layout->addWidget(m_lbInformation);
    layout->addWidget(m_leResult);
    layout->addWidget(m_cbExportToFile);
    setLayout(layout);

    registerField("exportToTxt", m_cbExportToFile);
    registerField("result", m_leResult);
}

QString haevn::view::wizzard::ResultPage::getResult(){
    return m_leResult->toPlainText();
}

bool haevn::view::wizzard::ResultPage::isExportChecked(){
    return m_cbExportToFile->isChecked();
}

void haevn::view::wizzard::ResultPage::showEvent(QShowEvent* event){
    QString scriptPath = field("script").toString();
    haevn::core::lua::LuaHandle handler(m_applicationModel);

    int result = handler.runScript(scriptPath.toStdString().c_str());
    if(result == LUA_OK){
        m_lbInformation->setText("Below you can see the code that is equivalent to the scene graph, you can copy it and paste it into your project.");
        m_leResult->setText(handler.getString("result"));
    }else{
        m_lbInformation->setText("An error has occurred during execution");
        m_leResult->setText(handler.getError());
    }
}

haevn::view::wizzard::ResultPage::~ResultPage(){
    delete m_leResult;
    m_leResult = nullptr;

    delete m_lbInformation;
    m_lbInformation = nullptr;
}

