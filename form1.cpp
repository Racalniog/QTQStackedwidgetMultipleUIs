#include "form1.h"
#include "ui_form1.h"

Form1::Form1(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form1)
{
    ui->setupUi(this);
    initBMI();
}

void Form1::initBMI()
{
    int counter = {};
    ui->buttonCopy->setEnabled(false);
    connect(ui->buttonCopy, &QPushButton::clicked, this,
            &Form1::buttonCopy_clicked);
    connect(ui->buttonDelete, &QPushButton::clicked, this,
            &Form1::buttonDelete_clicked);
    connect(ui->lineEdit, &QLineEdit::textChanged, this,
            &Form1::lineEdit_textChanged);
    connect(ui->buttonExit, &QPushButton::clicked, this,
            &Form1::buttonExit_clicked);
    connect(ui->buttonClickCount, &QPushButton::clicked,
            this, &Form1::buttonClickCount_clicked);
    connect(ui->buttonCalculate_BMI_clicked,
            &QPushButton::clicked, this,
            &Form1::buttonCalculate_BMI_clicked);
}

void Form1::buttonCopy_clicked()
{
    QString readLabel = ui->lineEdit->text();
    if(!readLabel.isEmpty())
        ui->copyTarget->setText(readLabel);
    ui->lineEdit->clear();
}

void Form1::buttonDelete_clicked()
{
    ui->copyTarget->clear();
}

void Form1::lineEdit_textChanged(const QString &arg1)
{
    bool grey = ui->lineEdit->text().isEmpty();
    ui->buttonCopy->setEnabled(!grey);
}

void Form1::buttonExit_clicked()
{
    close();
}

void Form1::buttonClickCount_clicked()
{
    counter += 1;
    ui->labelCounter->setText(QString::number(counter));
}

void Form1::buttonCalculate_BMI_clicked()
{
    double bmi = {};
    QString readheight = ui->lineEdit_Height->text();
    QString readweight = ui->lineEdit_Weight->text();
    if(!readheight.isEmpty() && !readweight.isEmpty()){
        bmi = readweight.toDouble()  / (readheight.toDouble() * readheight.toDouble());
        ui->bmiCalculation->setText(QString::number(bmi));
        ui->lineEdit_Height->clear();
        ui->lineEdit_Weight->clear();
    }
}


Form1::~Form1()
{
    delete ui;
}
