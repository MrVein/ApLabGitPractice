//
// Created by shazi on 5/11/2021.
//

#include "../Header Files/Triangle.h"

Triangle::Triangle() : _v1(0 , 0) ,_v2(0 , 0) , _v3(0 , 0)
{
    _color = "UNDEFINED";
}
Triangle::Triangle(Coordinate v1 , Coordinate v2 , Coordinate v3 , string color)
{
    _v1 = v1;
    _v2 = v2;
    _v3 = v3;

    _color = color;
}

double Triangle::calcPerimeter() const
{
    double side1 = sqrt((_v1._x - _v2._x) * (_v1._x - _v2._x)
                        + (_v1._y - _v2._y) * (_v1._y - _v2._y)) ;
    double side2 = sqrt((_v1._x - _v3._x) * (_v1._x - _v3._x)
                        + (_v1._y - _v3._y) * (_v1._y - _v3._y)) ;
    double side3 = sqrt((_v2._x - _v3._x) * (_v2._x - _v3._x)
                        + (_v2._y - _v3._y) * (_v2._y - _v3._y)) ;

    return side1+side2+side3;
}
double Triangle::calcArea()const
{
    double area = fabs((_v1._x * _v2._y + _v2._x * _v3._y + _v3._x * _v1._y)
                      - (_v2._x * _v1._y - _v3._x * _v2._y - _v1._x * _v3._y )) / 2;
    return area;
}
Coordinate Triangle::calcCenter()const
{
    double x = (_v1._x + _v2._x + _v3._x)/3.0;
    double y = (_v1._y + _v2._y + _v3._y)/3.0;

    return Coordinate(x ,y);
}

