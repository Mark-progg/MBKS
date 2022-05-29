/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.2.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLineEdit *InputTextToFile;
    QPushButton *pushButtonToPrivate;
    QPushButton *pushButtonToPublick;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(335, 190);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        InputTextToFile = new QLineEdit(centralwidget);
        InputTextToFile->setObjectName(QString::fromUtf8("InputTextToFile"));
        InputTextToFile->setGeometry(QRect(20, 120, 131, 22));
        pushButtonToPrivate = new QPushButton(centralwidget);
        pushButtonToPrivate->setObjectName(QString::fromUtf8("pushButtonToPrivate"));
        pushButtonToPrivate->setGeometry(QRect(20, 40, 131, 61));
        pushButtonToPublick = new QPushButton(centralwidget);
        pushButtonToPublick->setObjectName(QString::fromUtf8("pushButtonToPublick"));
        pushButtonToPublick->setGeometry(QRect(160, 40, 141, 61));
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\276\320\263\321\200\320\260\320\274\320\274\320\260 \320\264\320\273\321\217 \320\267\320\260\320\277\320\270\321\201\320\270 \321\204\320\260\320\271\320\273\320\260 \320\262 \320\277\321\200\320\270\320\262\320\260\321\202\320\275\321\203\321\216 \320\277\320\260\320\277\320\272\321\203 \320\270 \320\264\320\273\321\217 \320\272\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\321\217 \321\204\320\260\320\271\320\273\320\260 \320\262 \320\276\320\261\321\211\320\265\320\264\320\276\321\201\321\202\321\203\320\277\320\275\321\203\321\216 \320\277\320\260\320\277\320\272\321\203", nullptr));
        pushButtonToPrivate->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\277\320\270\321\201\320\260\321\202\321\214 \320\262 \320\277\321\200\320\270\320\262\320\260\321\202\320\275\321\203\321\216", nullptr));
        pushButtonToPublick->setText(QCoreApplication::translate("MainWindow", "\320\232\320\276\320\277\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265 \320\262 \320\276\320\261\321\211\321\203\321\216", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
