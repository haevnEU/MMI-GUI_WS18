#include "resultpage.h"

haevn::view::wizzard::ResultPage::ResultPage(haevn::core::models::Model* t_applicationModel, QWidget* parent) : QWizardPage (parent){
    // Create ui elements
    m_leResult = new QTextEdit();
    m_lbInformation = new QLabel();
    m_lbInformation = new QLabel();
    m_progressBar = new QProgressBar();
    m_cbExportToFile = new QCheckBox();
    QVBoxLayout* layout = new QVBoxLayout();

    m_applicationModel = t_applicationModel;

    // Set the progress bar to a flaoting bar
    m_progressBar->setMaximum(0);
    m_progressBar->setMinimum(0);

    setTitle(tr("Result"));

    // Enable word wrap for long content
    m_lbInformation->setWordWrap(true);
    m_lbInformation->setText("Below you can see the code that is equivalent to the scene graph, you can copy it and paste it into your project.");

    // Set text for export checkbox
    m_cbExportToFile->setText("Export to a txt file");

    // Add ui
    layout->addWidget(m_lbInformation);
    layout->addWidget(m_progressBar);
    layout->addWidget(m_leResult);
    layout->addWidget(m_cbExportToFile);
    setLayout(layout);

    // Register wizard fields
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
    // Get the script path
    QString scriptPath = field("script").toString();
    QString resultText;
    // Create a scripthandler
    haevn::core::lua::LuaHandle handler(m_applicationModel);
    // Execute script
    int result = handler.runScript(scriptPath.toStdString().c_str());
    if(result == LUA_OK){
        resultText = handler.getString("result");
    }else{
        resultText = handler.getError();
    }

    // Set the text from the result box
    m_leResult->setText(resultText);

    // Set the progressbar to finished state
    m_progressBar->setMaximum(1);
    m_progressBar->setValue(1);
}

haevn::view::wizzard::ResultPage::~ResultPage(){
    delete m_leResult;
    delete m_lbInformation;
    delete m_cbExportToFile;
    delete m_progressBar;
}

void haevn::view::wizzard::ResultPage::leaveEvent(QEvent *event){
}
