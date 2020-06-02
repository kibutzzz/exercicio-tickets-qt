#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "ticket.h"
#include <QQueue>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->setWindowTitle("Sistema de tickets");

    contadorPrioritario = 0;
    filaNormal =  new QQueue<Ticket>();
    filaPrioritaria =  new QQueue<Ticket>();

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_btnGeracaoNormal_clicked()
{
    this->filaNormal->enqueue(*new Ticket());
    updateListViews();
}

void MainWindow::on_btnGeracaoPrioritario_clicked()
{
    this->filaPrioritaria->enqueue(*new Ticket());

    updateListViews();
}

void MainWindow::updateListViews() {

    this->ui->filaAtendimentoPrioritario->clear();
    for(auto item : *this->filaPrioritaria) {
        this->ui->filaAtendimentoPrioritario->addItem(QString("Senha: %1 - %2")
                                                      .arg(item.getId())
                                                      .arg(item.getData().toString()));
    }

    this->ui->filaAtendimentoNormal->clear();
    for(auto item : *this->filaNormal) {
        this->ui->filaAtendimentoNormal->addItem(QString("Senha: %1 - %2")
                                                 .arg(item.getId())
                                                 .arg(item.getData().toString()));
    }
}

void MainWindow::setInfo(QString s)
{
    this->ui->infoLabel->setText(s);
}

void MainWindow::showLastTicketTakenInfo(Ticket t)
{
    setInfo(QString("Ultimo atendido:\n %1 - %2")
            .arg(t.getId())
            .arg(t.getData().toString()));
}

void MainWindow::on_btnAtender_clicked()
{
    setInfo("");

    QQueue<Ticket> *prioritaria = this->filaPrioritaria;
    if(!prioritaria->isEmpty() && (this->contadorPrioritario < 2 || filaNormal->isEmpty())) {
        this->contadorPrioritario ++;

        showLastTicketTakenInfo(prioritaria->dequeue());

        updateListViews();
        return;
    }

    QQueue<Ticket> *normal = this->filaNormal;
    if(!filaNormal->isEmpty()) {
        contadorPrioritario = 0;

        showLastTicketTakenInfo(normal->dequeue());

        updateListViews();
    } else {
        setInfo("Filas Vazias! Não há ninguém para atender");
    }

}
