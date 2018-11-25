#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QVector>
#include <QString>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    MainWindow::ui->leftX->setMinimum(-1000.0);
    MainWindow::ui->leftX->setMaximum(1000.0);
    MainWindow::ui->rightX->setMinimum(-1000.0);
    MainWindow::ui->rightX->setMaximum(1000.0);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete equation;
}

void MainWindow::pushButton_clicked()
{
    equation -> setLeftPointX(ui -> leftX->value());
    equation -> setRightPointX(ui -> rightX->value());

    int size = equation->pointsX.size();
    QVector<double> x(equation->pointsX.size()), y(equation->pointsY.size());
    x.clear();
    y.clear();
    for (int i=0; i< size; ++i)
    {
        x.push_back(equation->pointsX[i]);
        y.push_back(equation->pointsY[i]);
    }

    double startRangeX = MainWindow::equation-> getLeftPointX();
    double endRangeX = MainWindow::equation -> getRightPointX();

    MainWindow::ui->widget ->clearGraphs();

    MainWindow::ui->widget ->addGraph();

    MainWindow::ui->widget->graph(0)->setData(x,y);

    MainWindow::ui -> widget -> xAxis->setLabel("x");
    MainWindow::ui -> widget -> yAxis ->setLabel("y");

    MainWindow::ui -> widget -> xAxis -> setRange(startRangeX, endRangeX);

    double minY = MainWindow::equation->pointsY[0], maxY = MainWindow::equation->pointsY[0];
    for (int i=1; i<size; i++)
    {
        if (MainWindow::equation->pointsY[i]<minY) minY = MainWindow::equation->pointsY[i];
        if (MainWindow::equation->pointsY[i]>maxY) maxY = MainWindow::equation->pointsY[i];
    }
    MainWindow::ui->widget-> yAxis -> setRange(minY, maxY);

    MainWindow::ui->widget -> replot();
}

void MainWindow::on_leftX_valueChanged(double arg1)
{
    MainWindow::equation ->setLeftPointX(arg1);
}

void MainWindow::on_rightX_valueChanged(double arg1)
{
    MainWindow::equation ->setRightPointX(arg1);
}

void MainWindow::on_hordButton_clicked()
{
    MainWindow::setMethodName(MainWindow::METHOD_HORD);
}

void MainWindow::on_nyutonButton_clicked()
{
    MainWindow::setMethodName(MainWindow::METHOD_NYUTON);
}

void MainWindow::on_createButton_clicked()
{
    if (equation->getLeftPointX() !=0.0 || equation -> getRightPointX() != 0.0)
    {
        if (MainWindow::getMethodName() == MainWindow::METHOD_HORD)
        {
            ui-> result->setText(QString("%1").arg(MainWindow::equation ->findToMethodHord()));
            MainWindow::pushButton_clicked();
        } else if (MainWindow::getMethodName() == MainWindow::METHOD_NYUTON)
        {

            ui-> result->setText(QString("%1").arg(MainWindow::equation ->findToMethodNyutona()));
            MainWindow::pushButton_clicked();
        }
    }
}

void MainWindow::setMethodName(string name)
{
    MainWindow::method = name;
}

string MainWindow::getMethodName()
{
    return MainWindow::method;
}
