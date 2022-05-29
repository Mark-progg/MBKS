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

void MainWindow::load()
{
    QFile f("access_matrix.csv");
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

void MainWindow::save()
{
    QFile f("access_matrix.csv");
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


void MainWindow::on_pushButtonAdd_clicked()
{
    if(ui->radioButton_User->isChecked())
    {
        int r = ui->tableWidget->rowCount();
        int c = ui->tableWidget->columnCount();
        ui->tableWidget->insertRow(r);
        ui->tableWidget->setItem(r, 0, new QTableWidgetItem(ui->lineEdit->text()));//
        for(int i=1; i<c; i++)
        {
            ui->tableWidget->setItem(r, i, new QTableWidgetItem(" "));
        }
    }else
    {
        int r = ui->tableWidget->rowCount();
        int c = ui->tableWidget->columnCount();
        ui->tableWidget->insertColumn(c);//добавляет колнку
        ui->tableWidget->setItem(0, c, new QTableWidgetItem(ui->lineEdit->text()));
        for(int i=1; i<r; i++)
        {
            ui->tableWidget->setItem(i, c, new QTableWidgetItem(" "));
        }
    }
    save();
}


void MainWindow::on_pushButtonDelete_clicked()
{
    if(ui->radioButton_User->isChecked())
    {
        if(ui->tableWidget->currentColumn() == 0 && ui->tableWidget->currentRow() != 0) //вернуть текущую позицию (клетку)
            ui->tableWidget->removeRow(ui->tableWidget->currentRow()); //удаляет ряд
    }
    else
    {
        if(ui->tableWidget->currentRow() == 0 && ui->tableWidget->currentColumn() != 0)
            ui->tableWidget->removeColumn(ui->tableWidget->currentColumn());
    }
    save();
}

void MainWindow::on_pushButtonCheck_clicked()
{
    QString s;
    for(int i=0; i<ui->lineEditInput->text().length(); i++)
    {
        for(int j=1; j<ui->tableWidget->columnCount(); j++)
        {
            if(ui->lineEditInput->text().at(i) == ui->tableWidget->item(0,j)->text() && ui->tableWidget->item(ui->tableWidget->currentRow(),j)->text() == "+")
            {
                s+=ui->lineEditInput->text().at(i);
            }
        }
    }
    ui->lineEditChecked->setText(s);
}

void MainWindow::on_radioButton_User_toggled(bool checked)
{
    ui->radioButton_Right->setChecked(false);
}


void MainWindow::on_radioButton_Right_toggled(bool checked)
{
    ui->radioButton_User->setChecked(false);
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


