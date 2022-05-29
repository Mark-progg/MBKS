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
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTableWidget *tableWidget;
    QLineEdit *lineEditPath;
    QSpinBox *spinBoxLevel;
    QPushButton *buttonChoose;
    QPushButton *buttonAdd;
    QLabel *label;
    QLineEdit *lineEditPathFrom;
    QLineEdit *lineEditPathTo;
    QPushButton *buttonCopy;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(697, 423);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        tableWidget = new QTableWidget(centralwidget);
        tableWidget->setObjectName(QString::fromUtf8("tableWidget"));
        tableWidget->setGeometry(QRect(30, 20, 641, 271));
        lineEditPath = new QLineEdit(centralwidget);
        lineEditPath->setObjectName(QString::fromUtf8("lineEditPath"));
        lineEditPath->setGeometry(QRect(30, 340, 291, 24));
        lineEditPath->setReadOnly(true);
        spinBoxLevel = new QSpinBox(centralwidget);
        spinBoxLevel->setObjectName(QString::fromUtf8("spinBoxLevel"));
        spinBoxLevel->setGeometry(QRect(130, 370, 42, 25));
        spinBoxLevel->setMinimum(1);
        spinBoxLevel->setMaximum(3);
        buttonChoose = new QPushButton(centralwidget);
        buttonChoose->setObjectName(QString::fromUtf8("buttonChoose"));
        buttonChoose->setGeometry(QRect(30, 310, 291, 24));
        buttonAdd = new QPushButton(centralwidget);
        buttonAdd->setObjectName(QString::fromUtf8("buttonAdd"));
        buttonAdd->setGeometry(QRect(180, 370, 141, 24));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(40, 370, 91, 21));
        QFont font;
        font.setPointSize(9);
        label->setFont(font);
        lineEditPathFrom = new QLineEdit(centralwidget);
        lineEditPathFrom->setObjectName(QString::fromUtf8("lineEditPathFrom"));
        lineEditPathFrom->setGeometry(QRect(380, 310, 291, 24));
        lineEditPathFrom->setReadOnly(false);
        lineEditPathTo = new QLineEdit(centralwidget);
        lineEditPathTo->setObjectName(QString::fromUtf8("lineEditPathTo"));
        lineEditPathTo->setGeometry(QRect(380, 340, 291, 24));
        lineEditPathTo->setReadOnly(false);
        buttonCopy = new QPushButton(centralwidget);
        buttonCopy->setObjectName(QString::fromUtf8("buttonCopy"));
        buttonCopy->setGeometry(QRect(380, 370, 291, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(330, 310, 49, 16));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(330, 340, 49, 16));
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\275\320\264\320\260\321\202\320\275\320\260\321\217 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
        buttonChoose->setText(QCoreApplication::translate("MainWindow", "Choose path", nullptr));
        buttonAdd->setText(QCoreApplication::translate("MainWindow", "Add the directory", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Classification:", nullptr));
        buttonCopy->setText(QCoreApplication::translate("MainWindow", "Copy Files", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "From", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "To", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
