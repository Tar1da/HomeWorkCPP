#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <QtMath>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    operation = "";
    ui->setupUi(this);
    connect(ui->btn_1, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_2, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_3, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_4, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_5, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_6, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_7, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_8, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_9, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_0, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_per, SIGNAL(clicked()), this, SLOT(getDigit()));
    connect(ui->btn_equal, SIGNAL(clicked()), this, SLOT(getResult()));
    connect(ui->btn_plus, SIGNAL(clicked()), this, SLOT(setOper()));
    connect(ui->btn_minus, SIGNAL(clicked()), this, SLOT(setOper()));
    connect(ui->btn_mult, SIGNAL(clicked()), this, SLOT(setOper()));
    connect(ui->btn_div, SIGNAL(clicked()), this, SLOT(setOper()));
    connect(ui->btn_C, SIGNAL(clicked()), this, SLOT(C()));
    connect(ui->btn_CE, SIGNAL(clicked()), this, SLOT(CE()));
    connect(ui->btn_pow, SIGNAL(clicked()), this, SLOT(setOper()));
    connect(ui->btn_sqrt, SIGNAL(clicked()), this, SLOT(setOper()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::getDigit()
{
    QPushButton* btn = (QPushButton*)sender();
    QString currentText = ui->fieldText->text();
    QString btnText = btn->text();
    if(ui->fieldText->text() == "0" && btnText != ".")
             currentText = "";
    ui->fieldText->setText(currentText + btnText);
}

void MainWindow::setOper()
{
    QPushButton* btn = (QPushButton*)sender();
    operation = btn->text();
    prevNum = ui->fieldText->text();
    ui->fieldText->setText("0");
    if(operation == "sqrt") getResult();
}

void MainWindow::getResult()
{
    float res;
    if(operation == "+"){
        res = prevNum.toFloat() + ui->fieldText->text().toFloat();
    }
    else if(operation == "-"){
        res = prevNum.toFloat() - ui->fieldText->text().toFloat();
    }
    else if(operation == "*"){
        res = prevNum.toFloat() * ui->fieldText->text().toFloat();
    }
    else if(operation == "/"){
        res = prevNum.toFloat() / ui->fieldText->text().toFloat();
    }
    else if(operation == "X^"){
        res = pow(prevNum.toFloat(), ui->fieldText->text().toFloat());
    }
    else if(operation == "sqrt"){
        res = sqrt(prevNum.toFloat());
    }
    ui->fieldText->setText(QString::number(res));
}

void MainWindow::C()
{
    ui->fieldText->setText("0");
    prevNum = "";
}

void MainWindow::CE()
{
    ui->fieldText->setText("0");
}
