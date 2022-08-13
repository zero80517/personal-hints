#include "MainWindow.h"
#include "./ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->pbChangeVisibleLineEdit, SIGNAL(clicked()), this, SLOT(on_pbIsVisibleLineEdit_clicked()));
    connect(ui->pbChangeVisibleGroupBox, SIGNAL(clicked()), this, SLOT(on_pbIsVisibleLineEdit_clicked()));

    emit ui->pbChangeVisibleLineEdit->click();
    emit ui->pbChangeVisibleGroupBox->click();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pbChangeVisibleLineEdit_clicked()
{
    static bool visible = false;
    visible = !visible;
    ui->lineEdit->setVisible(visible);
}

void MainWindow::on_pbChangeVisibleGroupBox_clicked()
{
    static bool visible = false;
    visible = !visible;
    ui->groupBox->setVisible(visible);
    QString str = ui->groupBox->isVisibleTo(ui->tab_2) == true ? "visible" : "not visible";
    ui->leChangeVisibleGroupBox->clear();
    ui->leChangeVisibleGroupBox->setText(QString("groupBox is %1").arg(str));
}

void MainWindow::on_pbIsVisibleLineEdit_clicked()
{
    QString str = ui->lineEdit->isVisibleTo(ui->tab_2) == true ? "visible" : "not visible";
    ui->leIsVisibleLineEdit->clear();
    ui->leIsVisibleLineEdit->setText(QString("lineEdit is %1").arg(str));
}
