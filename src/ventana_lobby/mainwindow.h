#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include "../client_src/lobby.h"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Lobby *lobby, QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_botonSalir_clicked();

    void on_botonCrear_clicked();

    void on_botonUnirse_clicked();

private:
    Ui::MainWindow *ui;
    Lobby *lobby;
};
#endif // MAINWINDOW_H
