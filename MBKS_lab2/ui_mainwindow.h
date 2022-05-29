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
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QPushButton *pushButtonAdd;
    QPushButton *pushButtonDelete;
    QLineEdit *lineEditInput;
    QLineEdit *lineEditChecked;
    QPushButton *pushButtonCheck;
    QRadioButton *radioButton_User;
    QRadioButton *radioButton_Right;
    QLineEdit *lineEdit;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(473, 416);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(20, 20, 431, 241));
        tableWidget->setStyleSheet(QString::fromUtf8("background-color: rgb(164, 193, 255);"));
        pushButtonAdd = new QPushButton(centralwidget);
        pushButtonAdd->setObjectName(QString::fromUtf8("pushButtonAdd"));
        pushButtonAdd->setGeometry(QRect(30, 290, 80, 51));
        pushButtonAdd->setStyleSheet(QString::fromUtf8("background: rgb(79, 185, 255)"));
        pushButtonDelete = new QPushButton(centralwidget);
        pushButtonDelete->setObjectName(QString::fromUtf8("pushButtonDelete"));
        pushButtonDelete->setGeometry(QRect(120, 290, 80, 51));
        pushButtonDelete->setStyleSheet(QString::fromUtf8("background: rgb(255, 23, 35)"));
        lineEditInput = new QLineEdit(centralwidget);
        lineEditInput->setObjectName(QString::fromUtf8("lineEditInput"));
        lineEditInput->setGeometry(QRect(240, 280, 211, 22));
        lineEditChecked = new QLineEdit(centralwidget);
        lineEditChecked->setObjectName(QString::fromUtf8("lineEditChecked"));
        lineEditChecked->setGeometry(QRect(240, 370, 211, 22));
        lineEditChecked->setReadOnly(true);
        pushButtonCheck = new QPushButton(centralwidget);
        pushButtonCheck->setObjectName(QString::fromUtf8("pushButtonCheck"));
        pushButtonCheck->setGeometry(QRect(240, 310, 211, 51));
        pushButtonCheck->setStyleSheet(QString::fromUtf8("background:rgb(156, 255, 197)"));
        radioButton_User = new QRadioButton(centralwidget);
        radioButton_User->setObjectName(QString::fromUtf8("radioButton_User"));
        radioButton_User->setGeometry(QRect(40, 350, 91, 22));
        radioButton_User->setChecked(true);
        radioButton_Right = new QRadioButton(centralwidget);
        radioButton_Right->setObjectName(QString::fromUtf8("radioButton_Right"));
        radioButton_Right->setGeometry(QRect(120, 350, 91, 22));
        lineEdit = new QLineEdit(centralwidget);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setGeometry(QRect(30, 380, 171, 24));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\202\321\200\320\270\321\206\320\260 \320\264\320\276\321\201\321\202\321\203\320\277\320\260", nullptr));
        pushButtonAdd->setText(QCoreApplication::translate("MainWindow", "Add", nullptr));
        pushButtonDelete->setText(QCoreApplication::translate("MainWindow", "Delete", nullptr));
        lineEditInput->setText(QString());
        pushButtonCheck->setText(QCoreApplication::translate("MainWindow", "Check right", nullptr));
        radioButton_User->setText(QCoreApplication::translate("MainWindow", "User", nullptr));
        radioButton_Right->setText(QCoreApplication::translate("MainWindow", "Right", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
