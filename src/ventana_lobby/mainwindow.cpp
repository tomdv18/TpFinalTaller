#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow( Lobby *lobby, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , lobby(lobby)
{
    ui->setupUi(this);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_botonSalir_clicked()
{
    qDebug() << "SALIR DEL LOBBY";
    close();
}


void MainWindow::on_botonCrear_clicked()
{

    qDebug() << "JUGADORES " << ui->max_jugadores->text().toInt();

    uint8_t max_jugadores = (uint8_t)ui->max_jugadores->text().toInt();

}


void MainWindow::on_botonUnirse_clicked()
{
    qDebug() << "CODIGO PARTIDA " << ui->codigoPartida->text().toInt();

    uint32_t codigo_partida = (uint32_t)ui->codigoPartida->text().toInt();
}

