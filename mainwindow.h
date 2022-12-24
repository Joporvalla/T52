#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtSql/QSqlDatabase>
#include <QtSql/QSqlError>
#include <QtSql/QSqlTableModel>
#include <QtSql/QSqlQuery>
#include <QtSql/QSqlRelationalTableModel>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:

    void on_allDataViewButton_clicked();

    void on_filterDataButton_clicked();

    void on_filterData2Button_clicked();

    void on_pushButtonAdd_clicked();

    void on_pushButtonRem_clicked();

    void on_pushButtonDima_clicked();

    void on_pushButtonSlava_clicked();

    void on_pushButtonVlad_clicked();

private:
    Ui::MainWindow *ui;
    QSqlDatabase db;
    QSqlTableModel* model;
    QSqlQuery* query;
};
#endif // MAINWINDOW_H
