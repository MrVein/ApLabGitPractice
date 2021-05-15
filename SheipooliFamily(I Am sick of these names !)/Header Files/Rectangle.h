//
// Created by shazi on 5/12/2021.
//

#ifndef SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____RECTANGLE_H
#define SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____RECTANGLE_H
#include "Coordinate.h"

class Rectangle
{
    Coordinate _v1 , _v2 , _v3 , _v4;

public:
    double calcPerimeter() const;
    double calcArea() const;
    Coordinate calcCenter() const;
};


#endif //SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____RECTANGLE_H
