#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "ticket.h"

#include <QMainWindow>
#include <QQueue>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_btnGeracaoNormal_clicked();

    void on_btnGeracaoPrioritario_clicked();

    void on_btnAtender_clicked();

private:
    int contadorPrioritario;

    QQueue<Ticket> *filaNormal;
    QQueue<Ticket> *filaPrioritaria;
    Ui::MainWindow *ui;

    void updateListViews();

    void setInfo(QString s);

    void showLastTicketTakenInfo(Ticket t);
};
#endif // MAINWINDOW_H
