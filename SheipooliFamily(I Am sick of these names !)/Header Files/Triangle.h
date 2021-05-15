//
// Created by shazi on 5/11/2021.
//

#ifndef SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____TRIANGLE_H
#define SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____TRIANGLE_H
#include <iostream>
#include <cmath>
#include "Coordinate.h"
using namespace std;

class Triangle
{
    Coordinate _v1 , _v2 , _v3;
    string _color;

public:
    Triangle();
    Triangle(Coordinate v1 , Coordinate v2 , Coordinate v3 , string color);

    double calcPerimeter() const;
    double calcArea() const;
    Coordinate calcCenter() const;

};


#endif //SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____TRIANGLE_H
