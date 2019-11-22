#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    label1 = new QLabel("Text", this);
    label1->setGeometry(100, 100, 300, 100);
    label1->setStyleSheet("background-color:red; border-radius: 10px; ");
    label1->setAlignment(Qt::AlignCenter);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_clicked()
{
    DropletAppearAnimation::startAnimation(this, Qt::blue, label1, 0, 10);
}
