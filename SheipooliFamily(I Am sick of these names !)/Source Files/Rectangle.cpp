//
// Created by shazi on 5/12/2021.
//

#include "../Header Files/Rectangle.h"
#include <cmath>

double Rectangle::calcPerimeter() const
{
    double side1 = sqrt((_v1._x - _v2._x)*(_v1._x - _v2._x) + (_v1._y - _v2._y)*(_v1._y - _v2._y)) ;
    double side2 = sqrt((_v2._x - _v3._x)*(_v2._x - _v3._x) + (_v2._y - _v3._y)*(_v2._y - _v3._y));

    return 2 * (side1 + side2);
}
double Rectangle::calcArea() const
{
    double side1 = sqrt((_v1._x - _v2._x)*(_v1._x - _v2._x) + (_v1._y - _v2._y)*(_v1._y - _v2._y)) ;
    double side2 = sqrt((_v2._x - _v3._x)*(_v2._x - _v3._x) + (_v2._y - _v3._y)*(_v2._y - _v3._y));

    return side1 * side2;
}
Coordinate Rectangle::calcCenter() const
{
    double x = (_v1._x + _v3._x) /2.;
    double y = (_v1._y + _v3._y) /2.;

    return Coordinate(x , y);

}
