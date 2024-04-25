#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <QRegularExpression>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->lineEdit, &QLineEdit::textEdited, [this](QString currentText){
        //QRegularExpression exp ("\\d+"); все цифры
        //QRegularExpression exp ("\\d\\d\\w+"); два числа и слово
        //QRegularExpression exp ("^(\\d\\d)\\.(\\d\\d)\\.(\\d\\d\\d\\d)$"); // дата
         // QRegularExpression exp ("^(.+)@(.+)$"); корректность email
        QRegularExpression exp ("^\\+\\d[0-9]{11}$");
        if(exp.match(currentText).hasMatch())
            setOkLabel();
        else
            setNonOkLabel();
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setOkLabel()
{
    ui->label->setText("Ok");
    ui->label->setStyleSheet("color: rgb(29, 182, 39)");
}

void MainWindow::setNonOkLabel()
{
    ui->label->setText("Fail");
    ui->label->setStyleSheet("color: rgb(237, 51, 59)");
}

