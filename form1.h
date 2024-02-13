#ifndef FORM1_H
#define FORM1_H

#include <QWidget>

namespace Ui {
class Form1;
}

class Form1 : public QWidget
{
    Q_OBJECT

public:
    explicit Form1(QWidget *parent = nullptr);
    ~Form1();

private slots:
    void initBMI();
    void buttonCopy_clicked();
    void buttonDelete_clicked();
    void lineEdit_textChanged(const QString &arg1);
    void buttonExit_clicked();
    void buttonClickCount_clicked();
    void buttonCalculate_BMI_clicked();

private:
    Ui::Form1 *ui;
    int counter;
};

#endif // FORM1_H
