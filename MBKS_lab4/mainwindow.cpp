#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    load();
    ui->tableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::save()
{
    if(ui->tableWidget->rowCount() == 0) return;
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
            ui->tableWidget->blockSignals(true);
            for(int c = 0; c < strList.size(); ++c)
            {
                QTableWidgetItem *items= new QTableWidgetItem(strList.at(c));
                ui->tableWidget->setItem((r - 1), c, items);
            }
            ui->tableWidget->blockSignals(false);
            r++;
        }
    }
}

void MainWindow::on_buttonChoose_clicked()
{
    ui->lineEditPath->setText(QFileDialog::getExistingDirectory());
}


void MainWindow::on_buttonAdd_clicked()
{
    if(ui->lineEditPath->text() == "") return;
    int r = ui->tableWidget->rowCount();
    if(r == 0)
    {
        ui->tableWidget->setRowCount(1);
        ui->tableWidget->setColumnCount(2);
        ui->tableWidget->blockSignals(true);
        ui->tableWidget->setItem(0, 0, new QTableWidgetItem(ui->lineEditPath->text()));
        ui->tableWidget->setItem(0, 1, new QTableWidgetItem(ui->spinBoxLevel->text()));
        ui->tableWidget->blockSignals(false);
        return;
    }
    for(int i=0; i<r; i++)
        if(ui->lineEditPath->text() == ui->tableWidget->item(i, 0)->text())
            return;
    if(ui->lineEditPath->text() == "") return;
    ui->tableWidget->insertRow(r);
    ui->tableWidget->blockSignals(true);
    ui->tableWidget->setItem(r, 0, new QTableWidgetItem(ui->lineEditPath->text()));
    ui->tableWidget->setItem(r, 1, new QTableWidgetItem(ui->spinBoxLevel->text()));
    ui->tableWidget->blockSignals(false);
    save();
}

void MainWindow::on_buttonCopy_clicked()
{
    for(qsizetype i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        if(ui->tableWidget->item(i, 0)->text() == ui->lineEditPathFrom->text())
        {
            From = ui->tableWidget->item(i, 1)->text().toInt();
        }

    }

    for(qsizetype i = 0; i < ui->tableWidget->rowCount(); i++)
    {
        if(ui->tableWidget->item(i, 0)->text() == ui->lineEditPathTo->text())
        {
            To = ui->tableWidget->item(i, 1)->text().toInt();
        }

    }
    qDebug() << From;
    qDebug() << To;

    if(From <= To)
    {
        QDir dir1(ui->lineEditPathFrom->text());
        QDir dir2(ui->lineEditPathTo->text());
        QStringList tmp = dir1.entryList(QDir::Files);
        qDebug() << tmp;
        for(qsizetype i=0; i<tmp.length(); i++)
        {
               QFile::copy(dir1.absolutePath() + "//" + tmp[i], dir2.absolutePath() + "//" + tmp[i]);
        }
        QMessageBox::information(this, "Success", "Копирование прошло успешно");

    }
    else QMessageBox::warning(this, "Error", "Уровни доступа не являются разрешимыми");
}


void MainWindow::on_tableWidget_itemChanged(QTableWidgetItem *item)
{
    save();
}
