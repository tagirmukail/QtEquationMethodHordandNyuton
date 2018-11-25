/* equation.h */
#include <iostream>
#include <cmath>
#include <vector>
#include <tuple>
#pragma once

using namespace std;

class Equation
{
private:
    double accuracy;
    double leftPointX;
    double rightPointX;

public:
    Equation(double, double, double);
    ~Equation();

    std::vector<double> pointsX;
    std::vector<double> pointsY;

    double findEquation(double);

    double findDerivativeEquation1(double);

    double findDerivativeEquation2(double);

    double initApproximation();

    double findToMethodHord();

    double findToMethodNyutona();

    bool IsIntervalFabs();

    void setPoint(double, double);

    void setLeftPointX(double);
    void setRightPointX(double);
    
    double getLeftPointX();
    double getRightPointX();
};
