#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStateMachine>
#include <QHistoryState>
#include <QFileDialog>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    
    //============================================================
    /*auto stateMachine = new QStateMachine(this);     // TODO: Create state machine
                                                     // TODO: Create states
    auto greenState = new QState(stateMachine);      // podpęcie pod maszynę stanów, zamiast pod okno
    auto yellowState = new QState(stateMachine);     // stany
    auto redState = new QState(stateMachine);
    auto logState = new QState(stateMachine);
                                                                        // TODO: Set appropriate 'assignProperty'
    greenState->assignProperty(ui->pbToggle, "text", "GREEN");          // widget, wygląd
    yellowState->assignProperty(ui->pbToggle, "text", "YELLOW");
    redState->assignProperty(ui->pbToggle, "text", "RED");
                                                                            // TODO: Set state transitions including this class events and slots - ustawic odpowiednie przejscia pomiedzy stanami
    greenState->addTransition(ui->pbToggle, SIGNAL(clicked()), redState);   //triggery dla stanów - zmiana przy jakiejś akcji
    redState->addTransition(ui->pbToggle, SIGNAL(clicked()), yellowState); 
    yellowState->addTransition(ui->pbToggle, SIGNAL(clicked()), logState);                                      
    logState->addTransition(this, SIGNAL(done()), greenState);              //TODO: Add last transition
    
    connect(logState, SIGNAL(entered()), this, SLOT(log()));                //podpiece/wywolaniefunkcji log()
                                                                            // TODO: Set initial state
    stateMachine->setInitialState(greenState);
    // TODO: Start state machine
    stateMachine->start();*/

    //============================================================ STATE MACHINE & STATES
    QString fileName;

    auto stateMachine = new QStateMachine(this);


    auto lockedState = new QState(stateMachine);
    auto unlockedState = new QState(stateMachine);

    auto historyState = new QHistoryState(unlockedState);       //history
    auto startupState = new QState(unlockedState);
    auto openState = new QState(unlockedState);
    auto viewState = new QState(unlockedState);
    auto errorState = new QState(unlockedState);
    auto editState = new QState(unlockedState);
    auto saveState = new QState(unlockedState);

    //============================================================= ASSIGN PROPERTY

    unlockedState->assignProperty(ui->pbToggle, "text", "Lock");
    unlockedState->assignProperty(ui->pbOpen, "enabled", true);
    unlockedState->assignProperty(ui->pbSave, "enabled", true);
    unlockedState->assignProperty(ui->teText, "enabled", true);

    lockedState->assignProperty(ui->pbToggle, "text", "Unlock");
    lockedState->assignProperty(ui->pbOpen, "enabled", false);
    lockedState->assignProperty(ui->pbSave, "enabled", false);
    lockedState->assignProperty(ui->teText, "enabled", false);

    startupState->assignProperty(ui->pbOpen, "enabled", true);
    startupState->assignProperty(ui->pbSave, "enabled", false);
    startupState->assignProperty(ui->teText, "enabled", false);
    startupState->assignProperty(ui->teText, "placeholderText", "Open file to start editing...");

    errorState->assignProperty(ui->pbOpen, "enabled", true);
    errorState->assignProperty(ui->pbSave, "enabled", false);
    errorState->assignProperty(ui->teText, "enabled", false);
    errorState->assignProperty(ui->teText, "placeholderText", "Error ocured. Open file to start editing...");

    viewState->assignProperty(ui->pbOpen, "enabled", true);
    viewState->assignProperty(ui->pbSave, "enabled", false);
    viewState->assignProperty(ui->teText, "enabled", true);

    editState->assignProperty(ui->pbOpen, "enabled", false);
    editState->assignProperty(ui->pbSave, "enabled", true);
    editState->assignProperty(ui->teText, "enabled", true);

    //============================================================= TRANSITIONS

     unlockedState->addTransition(ui->pbToggle, SIGNAL(clicked()), lockedState);
     lockedState->addTransition(ui->pbToggle,SIGNAL(clicked()), historyState);

     startupState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);

     openState->addTransition(this, SIGNAL(error()), errorState);
     openState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), viewState);

     errorState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);

     viewState->addTransition(ui->pbOpen, SIGNAL(clicked(bool)), openState);
     viewState->addTransition(ui->teText, SIGNAL(textChanged()), editState);

     editState->addTransition(ui->pbSave, SIGNAL(clicked(bool)), saveState);

     saveState->addTransition(this, SIGNAL(saved()), viewState);
     saveState->addTransition(this, SIGNAL(error()),errorState);

     //============================================================= CONNECT

     connect(openState, SIGNAL(entered()), this, SLOT(open()));
     connect(saveState, SIGNAL(entered()), this, SLOT(save()));

     stateMachine -> setInitialState(unlockedState);
     unlockedState->setInitialState(startupState);

     stateMachine->start();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::open()
{
    fileName = QFileDialog::getOpenFileName(this,                                  // TODO: Show file dialog
        tr("Open file"),"", tr("Text Files (*.cpp *.h *.pro *.md *.txt)"));

    QFile file(fileName);                                                          // TODO: Open selected file // TODO: Emit 'error' if opening failed
    if (!file.open( QIODevice::ReadWrite ))
           emit error();
    else {
            QString line;
            QTextStream stream(&file);
            while (!stream.atEnd())
                line.append(stream.readLine()+"\n");
            ui->teText->setText(line);
            emit opened();                                                         // TODO: Set text and emit 'opened' if suceeded
         }
    // TODO: Save file name in 'fileName'
}

void MainWindow::save()
{
    QFile file(fileName);
    if (!file.open( QIODevice::WriteOnly ))                                       // TODO: Open 'fileName' for writing
           emit error();                                                          // TODO: Emit 'error' if opening failed
    else{                                                                         // TODO: Save file and emit 'saved' if succeeded
         QTextStream stream(&file);
         QString text = ui->teText->toPlainText();
         stream << text;
         emit saved();
    }
}
