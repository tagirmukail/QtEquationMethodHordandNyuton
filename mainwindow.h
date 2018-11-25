#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <string>
#include <QMainWindow>
#include "equation.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    Equation *equation = new Equation(0.01,0.0,0.0);

private slots:
    void pushButton_clicked();

    void on_leftX_valueChanged(double arg1);

    void on_rightX_valueChanged(double arg1);

    void on_hordButton_clicked();

    void on_nyutonButton_clicked();

    void on_createButton_clicked();

    void setMethodName(string);

    string getMethodName();

private:
    Ui::MainWindow *ui;
    string method;
    const string METHOD_HORD = "hord";
    const string METHOD_NYUTON = "nyuton";
};

#endif // MAINWINDOW_H
