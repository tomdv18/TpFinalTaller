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

    if(lobby->crear_partida(max_jugadores)){
        lobby->elegir_personaje(JAZZ);
        close();
    }else{
        qDebug() << "Error al crear";
        // Si no pudo crearse, lanzar el error
        /*
        QString texto = QString("Error al crear la partida");
        ui->textoConfirmacion->setText(texto);
        */
    }

}


void MainWindow::on_botonUnirse_clicked()
{
    qDebug() << "CODIGO PARTIDA " << ui->codigoPartida->text().toInt();

    uint32_t codigo_partida = (uint32_t)ui->codigoPartida->text().toInt();

    if(lobby->unirse_partida(codigo_partida)){
        lobby->elegir_personaje(JAZZ);
        close();
    }else{
        qDebug() << "Error al unirse";
        // Cambiar el texto dependiendo del error
        /* EJ 0x01 id inexistente, 0x02 partida llena
        QString texto = QString("Error al unirse a la partida");
        ui->textoConfirmacion->setText(texto);
        */
    }
}

