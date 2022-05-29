#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    QFile f("data.csv");
    if(f.open(QFile::WriteOnly))
    {
        QTextStream out(&f);
        QStringList strList;
        for(int r=0; r<ui->tableWidget->rowCount(); ++r)
        {
            strList.clear();
            for(int c=0; c<ui->tableWidget->columnCount(); ++c)
            {
                strList << ui->tableWidget->item(r, c)->text();
            }
            out << strList.join(";")+"\n";
        }
        f.close();
    }
}

void MainWindow::load()
{
    QFile f("data.csv");
    if(f.open(QFile::ReadOnly))
    {
        QTextStream in(&f);
        QStringList strList;
        int r = 1;
        while(!in.atEnd())
        {
            strList = in.readLine().split(";");
            ui->tableWidget->setRowCount(r);
            ui->tableWidget->setColumnCount(strList.size());
            for(int c = 0; c < strList.size(); ++c)
            {
                QTableWidgetItem *items= new QTableWidgetItem(strList.at(c));
                ui->tableWidget->setItem((r - 1), c, items);
            }
            r++;
        }
    }
}

void MainWindow::on_tableWidget_cellClicked(int r, int c)
{
    if(ui->tableWidget->item(r, c)->text() == "+")
    {
        ui->tableWidget->setItem(r, c, new QTableWidgetItem(" "));
        save();
        return;
    }
    else
    {
        if(ui->tableWidget->item(r, c)->text() == " ")
        {
            ui->tableWidget->setItem(r, c, new QTableWidgetItem("+"));
            save();
            return;
        }
    }
}


void MainWindow::AddUser(QString Name)
{
    int r = ui->tableWidget->rowCount();
    int c = ui->tableWidget->columnCount();
    ui->tableWidget->insertRow(r);
    ui->tableWidget->setItem(r, 0, new QTableWidgetItem(Name));
    for(int i=1; i<c; i++)
    {
        ui->tableWidget->setItem(r, i, new QTableWidgetItem(" "));
    }
    save();
}

void MainWindow::AddRight(QString Right)
{
    int r = ui->tableWidget->rowCount();
    int c = ui->tableWidget->columnCount();
    ui->tableWidget->insertColumn(c);
    ui->tableWidget->setItem(0, c, new QTableWidgetItem(Right));
    for(int i=1; i<r; i++)
    {
        ui->tableWidget->setItem(i, c, new QTableWidgetItem(" "));
    }
    save();
}

void MainWindow::on_pushButton_clicked()
{
    QString s;
    for(int i=0; i<ui->lineEdit->text().length(); i++)
    {
        for(int j=1; j<ui->tableWidget->columnCount(); j++)
        {
            if(ui->lineEdit->text().at(i) == ui->tableWidget->item(0,j)->text() && ui->tableWidget->item(ui->tableWidget->currentRow(),j)->text() == "+")
            {
                s+=ui->lineEdit->text().at(i);
            }
        }
    }
    ui->lineEdit_2->setText(s);
}

QStringList MainWindow::get_rights(int N)
{
    QStringList L;
    for(int i=1; i<ui->tableWidget->columnCount(); i++)
    {
        if(ui->tableWidget->item(N, i)->text() == "+")
        {
            L << ui->tableWidget->item(0, i)->text();
        }
    }
    return L;
}

void MainWindow::Grant(int s1, int s2, QStringList l)
{
    for(int i=1; i<ui->tableWidget->columnCount(); i++)
    {
        if(l.isEmpty()) break;
        if(l.first() == ui->tableWidget->item(0, i)->text())
        {
            if(ui->tableWidget->item(s1, i)->text() == "+")
                ui->tableWidget->setItem(s2, i, new QTableWidgetItem("+"));
            l.pop_front();
        }
    }
    save();
}

void MainWindow::on_Grant_clicked()
{
    QStringList l = ui->LineEdit_rights->text().split(QString());
    l.pop_back();
    l.pop_front();
    int i, j;
    for(i=1; i<ui->tableWidget->rowCount(); i++)
    {
        if(ui->tableWidget->item(i, 0)->text() == ui->LineEdit_s1->text())
            break;
    }
    for(j=1; j<ui->tableWidget->rowCount(); j++)
    {
        if(ui->tableWidget->item(j, 0)->text() == ui->LineEdit_s2->text())
            break;
    }
    Grant(i, j, l);
    ui->LineEdit_s1->clear();
    ui->LineEdit_s2->clear();
    ui->LineEdit_rights->clear();
}

void MainWindow::Create(QString s1, QStringList l)
{
    AddUser(s1);
    for(int i=1; i<ui->tableWidget->columnCount(); i++)
    {
        if(l.isEmpty()) break;
        if(l.first() == ui->tableWidget->item(0, i)->text())
        {
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, i, new QTableWidgetItem("+"));
            l.pop_front();
        }
    }
    if(!l.isEmpty())
    {
        int lcount = l.count();
        for(int i = 0; i<lcount; i++)
        {
            AddRight(l.first());
            ui->tableWidget->setItem(ui->tableWidget->rowCount()-1, ui->tableWidget->columnCount()-1, new QTableWidgetItem("+"));
            l.pop_front();
        }
    }
    save();
}

void MainWindow::on_Create_clicked()
{
    QStringList l = ui->LineEdit_rights->text().split(QString());
    l.pop_back();
    l.pop_front();
    Create(ui->LineEdit_s1->text(), l);
    ui->LineEdit_rights->clear();
    ui->LineEdit_s1->clear();
}

void MainWindow::Remove(int s1, QStringList l)
{
    for(int i=1; i<ui->tableWidget->columnCount(); i++)
    {
        if(l.isEmpty()) break;
        if(l.first() == ui->tableWidget->item(0, i)->text())
        {
            if(ui->tableWidget->item(s1, i)->text() == "+")
                ui->tableWidget->setItem(s1, i, new QTableWidgetItem(" "));
            l.pop_front();
        }
    }
    save();
}

void MainWindow::on_Remove_clicked()
{
    QStringList l = ui->LineEdit_rights->text().split(QString());
    l.pop_back();
    l.pop_front();
    int i;
    for(i=1; i<ui->tableWidget->rowCount(); i++)
    {
        if(ui->tableWidget->item(i, 0)->text() == ui->LineEdit_s1->text())
            break;
    }
    Remove(i, l);
    ui->LineEdit_rights->clear();
    ui->LineEdit_s1->clear();
}

