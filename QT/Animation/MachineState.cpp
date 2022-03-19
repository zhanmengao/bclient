#include"mainwindow.h"

void MainWindow::InitStateMachine()
{
    machine = new QStateMachine();
    QState *state1 = new QState(machine);
    state1->assignProperty(btn,"geometry",QRect(10,50,100,30));
    machine->setInitialState(state1);

    QState *state2 = new QState(machine);
    state2->assignProperty(btn,"geometry",QRect(200,150,100,30));

    QSignalTransition *transtion1 = state1->addTransition(btn,SIGNAL(clicked()),state2);
    transtion1->addAnimation(btn1InElastic);
    QSignalTransition *transtion2 = state2->addTransition(btn,SIGNAL(clicked()),state1);
    transtion2->addAnimation(btn1InElastic);
    machine->start();
}
