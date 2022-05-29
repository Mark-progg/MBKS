#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    flag = false;
    setWindowTitle("Программа нарушитель");

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(updateTime()));
    timer->setInterval(5000);
    timer->start();
    flag = false;
    prot = new QMessageBox(this);
    prot->setWindowTitle("Внимание!");
    prot->setStandardButtons( QMessageBox::Ok );
    prot->setModal( false );
    prot->setIcon(QMessageBox::Warning);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_radioButton_clicked(bool checked)
{

    if(checked)
    {
        prot->setText("Включили прослушку");
        prot->setWindowTitle("Внимание");
        prot->show();

        flag = true;
    }else{
        prot->setText("Выключили прослушку");
        prot->setWindowTitle("Внимание");
        prot->show();
        flag = false;
    }

}


void MainWindow::on_pushButton_stopChech_clicked()
{
    ui->radioButton->setChecked(false);
    flag = false;
}

void MainWindow::updateTime()
{
    qDebug()<<"метка 1";
    if(flag)
    {
        qDebug()<<"метка 2";
        prot->setText("Включили прослушку");
        prot->setWindowTitle("Внимание");
        prot->show();
        qDebug()<<"метка 3";

        flag = true;
        QDir dir = QDir::current();
        dir.cdUp();
        qDebug()<<"метка 4";
        QFileInfo check_file(dir.path());
        if(!dir.exists("Publick") && check_file.exists() && check_file.isFile())
        {
            prot->setText("Общедоступная папка не существует!");
            prot->setWindowTitle("Внимание");
            prot->show();
            qDebug()<<"Общедоступная папка не существует!";
        }else{
            prot->setText("Общедоступная папка и файл существует!");
            {
                QString  path;
                QDir dir = QDir::current();
                dir.cdUp();

                if(!dir.exists("Pirate"))
                    dir.mkdir("Pirate");

                dir.cd("Publick");
                dir.path();
                qDebug()<<dir;
                path = dir.absolutePath() + "/" + "FileCopy.txt";
                qDebug()<<path;

                QFile file(path);
                    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
                    {
                        QMessageBox::warning(this, "Внимание","Ошибка открытия для записи!");
                        qDebug() << "Ошибка открытия для чтения";
                        return;
                    }

                QByteArray buffer = file.readAll();
                qDebug()<<buffer;
                file.close();

                dir.cdUp();
                dir.cd("Pirate");
                dir.path();
                qDebug()<<dir.path();
                QString pathPublick = dir.absolutePath() + "/" + "FileCopy.txt";
                qDebug()<<pathPublick;

                QFile filePubclik(pathPublick);
                    if (!filePubclik.open(QIODevice::WriteOnly | QIODevice::Text))
                    {
                        QMessageBox::warning(this, "Внимание","Ошибка записи в публичный файл!");
                        qDebug() << "Ошибка записи в публичный файл";
                        return;

                    }
                filePubclik.write(buffer);
                filePubclik.close();}

            prot->setWindowTitle("Внимание");
            prot->show();
            qDebug()<<"Общедоступная папка и файл существует!";
        }
    }
}

