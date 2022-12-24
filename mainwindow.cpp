#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent) :
QMainWindow(parent),
ui(new Ui::MainWindow)
{ ui->setupUi(this);
    db = QSqlDatabase::addDatabase("QSQLITE");

db.setDatabaseName("contacts");
query = new QSqlQuery(db);

if(!db.open())
throw "can't open database";
if(!db.tables().contains("Person"))
{
    query->clear();
    query->exec("CREATE TABLE Person(ID INTEGER PRIMARY KEY,Predmet VARCHAR, Familia VARCHAR, Ocenka INTEGER, Hours INTEGER);");
    query->clear();
    query->exec("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (1,'AiP','Likar', 5, 108);");
    query->clear();
    query->exec("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (2,'VishMAT','Kabardov', 5, 216);");
    query->clear();
    query->exec("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (3,'DelRUS','Sokolova', 5, 72);"); }
model = new QSqlTableModel(this,db);

model->setTable("Person");
model->select();
model->setEditStrategy(QSqlTableModel::OnFieldChange);
ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{ delete ui; delete query; delete model; }


void MainWindow::on_allDataViewButton_clicked()
{
model->setFilter("");
model->select();
ui->tableView->setModel(model);
QMessageBox::information(0,tr("Action"),tr("All data"));
}

void MainWindow::on_filterDataButton_clicked()
{
model->setFilter("Ocenka>4");
model->select();
ui->tableView->setModel(model);
QMessageBox::information(0,"Action","Filter");
}

void MainWindow::on_filterData2Button_clicked()
{
model->setFilter("Ocenka<4");
model->select();
ui->tableView->setModel(model);
}

void MainWindow::on_pushButtonAdd_clicked()
{
if(ui->lineEditName->text().isEmpty()||ui->lineEditYear->text().isEmpty()||ui->lineEditID->text().isEmpty()||ui->lineEditPredmet->text().isEmpty()||ui->lineEditHours->text().isEmpty())
return;
QString id = ui->lineEditID->text();
QString Predmet = ui->lineEditPredmet->text();
QString name = ui->lineEditName->text();
QString year = ui->lineEditYear->text();
QString Hours = ui->lineEditHours->text();

QString buf = tr("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (")+id+tr(",'")+Predmet+tr("','")+name+tr("',")+year+(",")+Hours+tr(");");
query->clear();
query->exec(buf);
model->select();
}

void MainWindow::on_pushButtonRem_clicked()
{
if(ui->lineEditID->text().isEmpty())
return;
QString id = ui->lineEditID->text();
query->clear();
query->exec(tr("DELETE FROM Person WHERE ID=")+id);
model->select();
}

void MainWindow::on_pushButtonDima_clicked()
{
    QString id = "55";
    QString Predmet = "TRPO";
    QString name = "MAKSIMOW";
    QString year = "5";
    QString Hours = "999";
    QString buf = tr("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (")+id+tr(",'")+Predmet+tr("','")+name+tr("',")+year+(",")+Hours+tr(");");
    query->clear();
    query->exec(buf);
    model->select();
}


void MainWindow::on_pushButtonVlad_clicked()
{
    QString id = "54";
    QString Predmet = "TRPO";
    QString name = "MENSHIKOV";
    QString year = "2";
    QString Hours = "10";
    QString buf = tr("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (")+id+tr(",'")+Predmet+tr("','")+name+tr("',")+year+(",")+Hours+tr(");");
    query->clear();
    query->exec(buf);
    model->select();
}


void MainWindow::on_pushButtonSlava_clicked()
{
    QString id = "35";
    QString Predmet = "TRPO";
    QString name = "GERTSYK";
    QString year = "5";
    QString Hours = "999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999999";
    QString buf = tr("INSERT INTO Person (ID,Predmet,Familia,Ocenka,Hours) VALUES (")+id+tr(",'")+Predmet+tr("','")+name+tr("',")+year+(",")+Hours+tr(");");
    query->clear();
    query->exec(buf);
    model->select();
}

