#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->pbChangeVisibleGroupBox, SIGNAL(clicked()), this, SLOT(on_pbIsGroupBoxVisible_clicked()));
    connect(ui->pbChangeVisibleGroupBox, SIGNAL(clicked()), this, SLOT(on_pbIsLineEditVisible_clicked()));
    connect(ui->pbChangeVisibleLineEdit, SIGNAL(clicked()), this, SLOT(on_pbIsLineEditVisible_clicked()));

    emit ui->pbIsGroupBoxVisible->clicked();
    emit ui->pbIsLineEditVisible->clicked();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pbChangeVisibleGroupBox_clicked()
{
    static bool visible = true;
    visible = !visible;
    ui->eGroupBox->setVisible(visible);
}


void MainWindow::on_pbChangeVisibleLineEdit_clicked()
{
    static bool visible = true;
    visible = !visible;
    ui->eLineEdit->setVisible(visible);
}


void MainWindow::on_pbIsGroupBoxVisible_clicked()
{
    bool visible = ui->eGroupBox->IsVisibleOnTab();
    QString str = visible ? "visible" : "not visible";
    ui->leIsGroupBoxVisible->setText(str);
}


void MainWindow::on_pbIsLineEditVisible_clicked()
{
    bool visible = ui->eLineEdit->IsVisibleOnTab();
    QString str = visible ? "visible" : "not visible";
    ui->leIsLineEditVisible->setText(str);
}
