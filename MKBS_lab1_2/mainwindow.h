#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMessageBox>
#include <QTimer>
#include <QDir>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_radioButton_clicked(bool checked);

    void on_pushButton_copyData_clicked();

    void on_pushButton_stopChech_clicked();

    void updateTime();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
    QMessageBox *prot;
    bool flag;
};
#endif // MAINWINDOW_H
