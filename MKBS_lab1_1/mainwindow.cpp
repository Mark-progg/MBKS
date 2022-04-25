#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QFile>
#include <QTextStream>
#include <QDir>
#include <QMessageBox>



MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButtonToPrivate_clicked()
{
    QString buffer, path;

    QDir dir = QDir::current();
    dir.cdUp();
    if(!dir.exists("Private"))
        dir.mkdir("Private");

    dir.cd("Private");
    dir.path();
    qDebug()<<dir;
    path = dir.absolutePath() + "/" + "File.txt";
    qDebug()<<path;

    QFile file(path);
        if (!file.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "Внимание","Ошибка открытия для записи!");
            qDebug() << "Ошибка открытия для записи";
            return;
        }

    buffer = ui->InputTextToFile->text();
    qDebug()<<buffer;

    file.write(buffer.toUtf8());
    file.close();
}


void MainWindow::on_pushButtonToPublick_clicked()
{
    QDir dir = QDir::current();
    dir.cdUp();

    if(!dir.exists("Private"))
    {
        QMessageBox::warning(this, "Внимание","Приватная папка не существует!");
        qDebug()<<"Приватная папка не существует!";
        return;
    }

    QString  path;

    dir.cd("Private");
    dir.path();
    qDebug()<<dir;
    path = dir.absolutePath() + "/" + "File.txt";
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
//
    QString pathPublick;

    dir.cdUp();
    if(!dir.exists("Publick"))
      dir.mkdir("Publick");

    dir.cd("Publick");
    dir.path();
    qDebug()<<dir.path();
    pathPublick = dir.absolutePath() + "/" + "FileCopy.txt";
    qDebug()<<pathPublick;

    QFile filePubclik(pathPublick);
        if (!filePubclik.open(QIODevice::WriteOnly | QIODevice::Text))
        {
            QMessageBox::warning(this, "Внимание","Ошибка записи в публичный файл!");
            qDebug() << "Ошибка записи в публичный файл";
            return;
        }
    qDebug() << "метка 1";
    filePubclik.write(buffer);
    qDebug() << "метка 2";
    filePubclik.close();
}

