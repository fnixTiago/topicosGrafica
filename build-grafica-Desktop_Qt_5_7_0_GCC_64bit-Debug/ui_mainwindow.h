/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSlider>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QLabel *imagen_ini;
    QLabel *histograma;
    QPushButton *Abrir;
    QLabel *imagen_fin;
    QLabel *label;
    QLabel *label_2;
    QPushButton *Restaurar;
    QSlider *Scroll;
    QComboBox *Opcion;
    QWidget *tab_4;
    QLabel *transHisto_ini;
    QLabel *transHisto_fin;
    QPushButton *abrirTransHis;
    QPushButton *Ecualizar;
    QWidget *tab_2;
    QLabel *imagen1;
    QLabel *imagen2;
    QPushButton *abrir1;
    QPushButton *abrir2;
    QLabel *imagen12;
    QComboBox *comboBox;
    QWidget *tab_3;
    QLabel *imagenfc;
    QLabel *imagenfcres;
    QPushButton *Abrirfc;
    QPushButton *pushButton;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(769, 469);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setGeometry(QRect(20, 10, 751, 401));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        imagen_ini = new QLabel(tab);
        imagen_ini->setObjectName(QStringLiteral("imagen_ini"));
        imagen_ini->setGeometry(QRect(30, 30, 311, 221));
        imagen_ini->setFrameShape(QFrame::Panel);
        histograma = new QLabel(tab);
        histograma->setObjectName(QStringLiteral("histograma"));
        histograma->setGeometry(QRect(410, 260, 311, 101));
        histograma->setFrameShape(QFrame::Panel);
        Abrir = new QPushButton(tab);
        Abrir->setObjectName(QStringLiteral("Abrir"));
        Abrir->setGeometry(QRect(70, 260, 91, 23));
        imagen_fin = new QLabel(tab);
        imagen_fin->setObjectName(QStringLiteral("imagen_fin"));
        imagen_fin->setGeometry(QRect(412, 30, 311, 221));
        imagen_fin->setFrameShape(QFrame::Panel);
        label = new QLabel(tab);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 10, 311, 20));
        label->setAlignment(Qt::AlignCenter);
        label_2 = new QLabel(tab);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(410, 10, 311, 20));
        label_2->setAlignment(Qt::AlignCenter);
        Restaurar = new QPushButton(tab);
        Restaurar->setObjectName(QStringLiteral("Restaurar"));
        Restaurar->setGeometry(QRect(210, 260, 91, 23));
        Scroll = new QSlider(tab);
        Scroll->setObjectName(QStringLiteral("Scroll"));
        Scroll->setGeometry(QRect(70, 340, 231, 20));
        Scroll->setOrientation(Qt::Horizontal);
        Opcion = new QComboBox(tab);
        Opcion->setObjectName(QStringLiteral("Opcion"));
        Opcion->setGeometry(QRect(140, 300, 79, 23));
        tabWidget->addTab(tab, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QStringLiteral("tab_4"));
        transHisto_ini = new QLabel(tab_4);
        transHisto_ini->setObjectName(QStringLiteral("transHisto_ini"));
        transHisto_ini->setGeometry(QRect(30, 40, 291, 231));
        transHisto_ini->setFrameShape(QFrame::Panel);
        transHisto_fin = new QLabel(tab_4);
        transHisto_fin->setObjectName(QStringLiteral("transHisto_fin"));
        transHisto_fin->setGeometry(QRect(410, 40, 291, 231));
        transHisto_fin->setFrameShape(QFrame::Panel);
        abrirTransHis = new QPushButton(tab_4);
        abrirTransHis->setObjectName(QStringLiteral("abrirTransHis"));
        abrirTransHis->setGeometry(QRect(100, 280, 141, 23));
        Ecualizar = new QPushButton(tab_4);
        Ecualizar->setObjectName(QStringLiteral("Ecualizar"));
        Ecualizar->setGeometry(QRect(30, 320, 80, 23));
        tabWidget->addTab(tab_4, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        imagen1 = new QLabel(tab_2);
        imagen1->setObjectName(QStringLiteral("imagen1"));
        imagen1->setGeometry(QRect(70, 20, 211, 141));
        imagen1->setFrameShape(QFrame::Panel);
        imagen2 = new QLabel(tab_2);
        imagen2->setObjectName(QStringLiteral("imagen2"));
        imagen2->setGeometry(QRect(70, 200, 211, 141));
        imagen2->setFrameShape(QFrame::Panel);
        abrir1 = new QPushButton(tab_2);
        abrir1->setObjectName(QStringLiteral("abrir1"));
        abrir1->setGeometry(QRect(130, 170, 80, 23));
        abrir2 = new QPushButton(tab_2);
        abrir2->setObjectName(QStringLiteral("abrir2"));
        abrir2->setGeometry(QRect(130, 350, 80, 23));
        imagen12 = new QLabel(tab_2);
        imagen12->setObjectName(QStringLiteral("imagen12"));
        imagen12->setGeometry(QRect(350, 20, 351, 201));
        imagen12->setFrameShape(QFrame::Panel);
        comboBox = new QComboBox(tab_2);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setGeometry(QRect(480, 260, 79, 23));
        tabWidget->addTab(tab_2, QString());
        tab_3 = new QWidget();
        tab_3->setObjectName(QStringLiteral("tab_3"));
        imagenfc = new QLabel(tab_3);
        imagenfc->setObjectName(QStringLiteral("imagenfc"));
        imagenfc->setGeometry(QRect(20, 20, 321, 251));
        imagenfc->setFrameShape(QFrame::Panel);
        imagenfcres = new QLabel(tab_3);
        imagenfcres->setObjectName(QStringLiteral("imagenfcres"));
        imagenfcres->setGeometry(QRect(400, 20, 321, 251));
        imagenfcres->setFrameShape(QFrame::Panel);
        Abrirfc = new QPushButton(tab_3);
        Abrirfc->setObjectName(QStringLiteral("Abrirfc"));
        Abrirfc->setGeometry(QRect(140, 280, 80, 23));
        pushButton = new QPushButton(tab_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(510, 280, 80, 23));
        tabWidget->addTab(tab_3, QString());
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 769, 20));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(3);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        imagen_ini->setText(QString());
        histograma->setText(QString());
        Abrir->setText(QApplication::translate("MainWindow", "Abrir Imagen", 0));
        imagen_fin->setText(QString());
        label->setText(QApplication::translate("MainWindow", "Original", 0));
        label_2->setText(QApplication::translate("MainWindow", "Alterado", 0));
        Restaurar->setText(QApplication::translate("MainWindow", "Restaurar", 0));
        Opcion->clear();
        Opcion->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sumar", 0)
         << QApplication::translate("MainWindow", "Restar", 0)
         << QApplication::translate("MainWindow", "Multiplicar", 0)
         << QApplication::translate("MainWindow", "Dividir", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "Op. Elementales", 0));
        transHisto_ini->setText(QString());
        transHisto_fin->setText(QString());
        abrirTransHis->setText(QApplication::translate("MainWindow", "Abrir Imagen", 0));
        Ecualizar->setText(QApplication::translate("MainWindow", "Ecualizar", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_4), QApplication::translate("MainWindow", "Trans. histograma", 0));
        imagen1->setText(QString());
        imagen2->setText(QString());
        abrir1->setText(QApplication::translate("MainWindow", "Abrir", 0));
        abrir2->setText(QApplication::translate("MainWindow", "Abrir", 0));
        imagen12->setText(QString());
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Sumar", 0)
         << QApplication::translate("MainWindow", "Restar", 0)
         << QApplication::translate("MainWindow", "Multiplicar", 0)
         << QApplication::translate("MainWindow", "Dividir", 0)
        );
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "Comb. Imagenes", 0));
        imagenfc->setText(QString());
        imagenfcres->setText(QString());
        Abrirfc->setText(QApplication::translate("MainWindow", "Abrir", 0));
        pushButton->setText(QApplication::translate("MainWindow", "calcular", 0));
        tabWidget->setTabText(tabWidget->indexOf(tab_3), QApplication::translate("MainWindow", "Filtros y Conv.", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
