/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.15.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QFormLayout *formLayout;
    QPushButton *botonInicio;
    QLabel *labelJugadores;
    QSpinBox *cantidadJugadores;
    QHBoxLayout *horizontalLayout;
    QPushButton *botonSpaz;
    QTableWidget *listaPartidas;
    QPushButton *botonJazz;
    QPushButton *botonLori;
    QPushButton *botonEmpezar;
    QVBoxLayout *verticalLayout;
    QPushButton *botonCrear;
    QPushButton *botonUnirse;
    QPushButton *botonSalir;
    QPushButton *botonUnirseEmpezar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(594, 876);
        MainWindow->setLayoutDirection(Qt::LeftToRight);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        centralwidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralwidget->sizePolicy().hasHeightForWidth());
        centralwidget->setSizePolicy(sizePolicy);
        formLayout = new QFormLayout(centralwidget);
        formLayout->setObjectName(QString::fromUtf8("formLayout"));
        formLayout->setSizeConstraint(QLayout::SetDefaultConstraint);
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setRowWrapPolicy(QFormLayout::DontWrapRows);
        formLayout->setFormAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        formLayout->setHorizontalSpacing(0);
        formLayout->setVerticalSpacing(5);
        formLayout->setContentsMargins(-1, 150, -1, 0);
        botonInicio = new QPushButton(centralwidget);
        botonInicio->setObjectName(QString::fromUtf8("botonInicio"));
        QSizePolicy sizePolicy1(QSizePolicy::Preferred, QSizePolicy::Maximum);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(botonInicio->sizePolicy().hasHeightForWidth());
        botonInicio->setSizePolicy(sizePolicy1);
        botonInicio->setMinimumSize(QSize(50, 40));
        botonInicio->setCursor(QCursor(Qt::PointingHandCursor));
        botonInicio->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));

        formLayout->setWidget(0, QFormLayout::FieldRole, botonInicio);

        labelJugadores = new QLabel(centralwidget);
        labelJugadores->setObjectName(QString::fromUtf8("labelJugadores"));
        QSizePolicy sizePolicy2(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy2.setHorizontalStretch(0);
        sizePolicy2.setVerticalStretch(0);
        sizePolicy2.setHeightForWidth(labelJugadores->sizePolicy().hasHeightForWidth());
        labelJugadores->setSizePolicy(sizePolicy2);
        labelJugadores->setMinimumSize(QSize(40, 40));
        labelJugadores->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));
        labelJugadores->setAlignment(Qt::AlignCenter);

        formLayout->setWidget(1, QFormLayout::FieldRole, labelJugadores);

        cantidadJugadores = new QSpinBox(centralwidget);
        cantidadJugadores->setObjectName(QString::fromUtf8("cantidadJugadores"));
        cantidadJugadores->setCursor(QCursor(Qt::PointingHandCursor));
        cantidadJugadores->setLayoutDirection(Qt::LeftToRight);
        cantidadJugadores->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));
        cantidadJugadores->setAlignment(Qt::AlignCenter);
        cantidadJugadores->setMinimum(2);
        cantidadJugadores->setMaximum(30);

        formLayout->setWidget(2, QFormLayout::FieldRole, cantidadJugadores);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(20);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setSizeConstraint(QLayout::SetMaximumSize);
        horizontalLayout->setContentsMargins(-1, 5, -1, 10);
        botonSpaz = new QPushButton(centralwidget);
        botonSpaz->setObjectName(QString::fromUtf8("botonSpaz"));
        sizePolicy2.setHeightForWidth(botonSpaz->sizePolicy().hasHeightForWidth());
        botonSpaz->setSizePolicy(sizePolicy2);
        botonSpaz->setMinimumSize(QSize(0, 250));
        botonSpaz->setCursor(QCursor(Qt::PointingHandCursor));
        botonSpaz->setStyleSheet(QString::fromUtf8("border-image: url(:/res/images/Spaz_no_seleccionado.png);\n"
""));

        horizontalLayout->addWidget(botonSpaz);

        listaPartidas = new QTableWidget(centralwidget);
        listaPartidas->setObjectName(QString::fromUtf8("listaPartidas"));
        listaPartidas->setStyleSheet(QString::fromUtf8("background-color: qconicalgradient(cx:0, cy:0, angle:135, stop:0 rgba(255, 255, 0, 69), stop:0.375 rgba(255, 255, 0, 69), stop:0.423533 rgba(251, 255, 0, 145), stop:0.45 rgba(247, 255, 0, 208), stop:0.477581 rgba(255, 244, 71, 130), stop:0.518717 rgba(255, 218, 71, 130), stop:0.55 rgba(255, 255, 0, 255), stop:0.57754 rgba(255, 203, 0, 130), stop:0.625 rgba(255, 255, 0, 69), stop:1 rgba(255, 255, 0, 69));\n"
"font: 700 italic 15pt \"Z003\";"));
        listaPartidas->setEditTriggers(QAbstractItemView::NoEditTriggers);
        listaPartidas->setTabKeyNavigation(false);
        listaPartidas->setProperty("showDropIndicator", QVariant(false));
        listaPartidas->setSelectionMode(QAbstractItemView::SingleSelection);
        listaPartidas->setSelectionBehavior(QAbstractItemView::SelectRows);

        horizontalLayout->addWidget(listaPartidas);

        botonJazz = new QPushButton(centralwidget);
        botonJazz->setObjectName(QString::fromUtf8("botonJazz"));
        sizePolicy2.setHeightForWidth(botonJazz->sizePolicy().hasHeightForWidth());
        botonJazz->setSizePolicy(sizePolicy2);
        botonJazz->setCursor(QCursor(Qt::PointingHandCursor));
        botonJazz->setFocusPolicy(Qt::StrongFocus);
        botonJazz->setStyleSheet(QString::fromUtf8("border-image: url(:/res/images/Jazz_no_seleccionado.png);\n"
"\n"
""));

        horizontalLayout->addWidget(botonJazz);

        botonLori = new QPushButton(centralwidget);
        botonLori->setObjectName(QString::fromUtf8("botonLori"));
        sizePolicy2.setHeightForWidth(botonLori->sizePolicy().hasHeightForWidth());
        botonLori->setSizePolicy(sizePolicy2);
        botonLori->setCursor(QCursor(Qt::PointingHandCursor));
        botonLori->setStyleSheet(QString::fromUtf8("border-image: url(:/res/images/Lori_no_seleccionado.png);\n"
""));

        horizontalLayout->addWidget(botonLori);


        formLayout->setLayout(3, QFormLayout::FieldRole, horizontalLayout);

        botonEmpezar = new QPushButton(centralwidget);
        botonEmpezar->setObjectName(QString::fromUtf8("botonEmpezar"));
        sizePolicy2.setHeightForWidth(botonEmpezar->sizePolicy().hasHeightForWidth());
        botonEmpezar->setSizePolicy(sizePolicy2);
        botonEmpezar->setMinimumSize(QSize(50, 100));
        botonEmpezar->setCursor(QCursor(Qt::PointingHandCursor));
        botonEmpezar->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));

        formLayout->setWidget(4, QFormLayout::FieldRole, botonEmpezar);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(10);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout->setContentsMargins(-1, -1, -1, 0);
        botonCrear = new QPushButton(centralwidget);
        botonCrear->setObjectName(QString::fromUtf8("botonCrear"));
        QSizePolicy sizePolicy3(QSizePolicy::Minimum, QSizePolicy::Fixed);
        sizePolicy3.setHorizontalStretch(0);
        sizePolicy3.setVerticalStretch(0);
        sizePolicy3.setHeightForWidth(botonCrear->sizePolicy().hasHeightForWidth());
        botonCrear->setSizePolicy(sizePolicy3);
        botonCrear->setMinimumSize(QSize(0, 50));
        QFont font;
        font.setFamily(QString::fromUtf8("Z003"));
        font.setPointSize(25);
        font.setBold(true);
        font.setItalic(true);
        botonCrear->setFont(font);
        botonCrear->setCursor(QCursor(Qt::PointingHandCursor));
        botonCrear->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));

        verticalLayout->addWidget(botonCrear);

        botonUnirse = new QPushButton(centralwidget);
        botonUnirse->setObjectName(QString::fromUtf8("botonUnirse"));
        sizePolicy3.setHeightForWidth(botonUnirse->sizePolicy().hasHeightForWidth());
        botonUnirse->setSizePolicy(sizePolicy3);
        botonUnirse->setMinimumSize(QSize(0, 50));
        botonUnirse->setFont(font);
        botonUnirse->setCursor(QCursor(Qt::PointingHandCursor));
        botonUnirse->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));

        verticalLayout->addWidget(botonUnirse);

        botonSalir = new QPushButton(centralwidget);
        botonSalir->setObjectName(QString::fromUtf8("botonSalir"));
        botonSalir->setFont(font);
        botonSalir->setCursor(QCursor(Qt::PointingHandCursor));
        botonSalir->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));

        verticalLayout->addWidget(botonSalir);


        formLayout->setLayout(6, QFormLayout::FieldRole, verticalLayout);

        botonUnirseEmpezar = new QPushButton(centralwidget);
        botonUnirseEmpezar->setObjectName(QString::fromUtf8("botonUnirseEmpezar"));
        botonUnirseEmpezar->setMinimumSize(QSize(50, 100));
        botonUnirseEmpezar->setStyleSheet(QString::fromUtf8("background-color: qlineargradient(spread:pad, x1:0, y1:0, x2:1, y2:0, stop:0 rgba(255, 178, 102, 255), stop:0.55 rgba(235, 148, 61, 255), stop:0.98 rgba(0, 0, 0, 255), stop:1 rgba(0, 0, 0, 0));\n"
"font: 700 italic 25pt \"Z003\";"));

        formLayout->setWidget(5, QFormLayout::FieldRole, botonUnirseEmpezar);

        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        botonInicio->setText(QCoreApplication::translate("MainWindow", "VOLVER AL INICIO", nullptr));
        labelJugadores->setText(QCoreApplication::translate("MainWindow", "CANTIDAD DE JUGADORES", nullptr));
        botonSpaz->setText(QString());
        botonJazz->setText(QString());
        botonLori->setText(QString());
        botonEmpezar->setText(QCoreApplication::translate("MainWindow", "EMPEZAR PARTIDA", nullptr));
        botonCrear->setText(QCoreApplication::translate("MainWindow", "CREAR", nullptr));
        botonUnirse->setText(QCoreApplication::translate("MainWindow", "UNIRSE", nullptr));
        botonSalir->setText(QCoreApplication::translate("MainWindow", "SALIR", nullptr));
        botonUnirseEmpezar->setText(QCoreApplication::translate("MainWindow", "UNIRSE A LA PARTIDA", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
