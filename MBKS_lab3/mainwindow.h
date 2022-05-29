#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTableWidget>
#include <QFile>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void save();
    void load();
    QStringList get_rights(int N);
    void AddUser(QString Name);
    void AddRight(QString Right);
    void Grant(int s1, int s2, QStringList l);
    void Remove(int s1, QStringList l);
    void Create(QString s1, QStringList l);


private slots:
    void on_tableWidget_cellClicked(int row, int column);
    void on_pushButton_clicked();
    void on_Grant_clicked();
    void on_Create_clicked();
    void on_Remove_clicked();
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
