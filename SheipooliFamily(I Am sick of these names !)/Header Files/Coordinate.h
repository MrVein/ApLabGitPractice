//
// Created by shazi on 5/12/2021.
//

#ifndef SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____COORDINATE_H
#define SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____COORDINATE_H



class Coordinate
{
protected:
    int _y;
    int _x;

public:
    Coordinate(double x = 0  , double y = 0);

    friend class Triangle;
    friend class Rectangle;
};


#endif //SHEIPOOLIFAMILY_I_AM_SICK_OF_THESE_NAMES____COORDINATE_H
