//
// Created by shazi on 4/30/2021.
//

#ifndef MATHWITHOOP_POLYNOMIAL_H
#define MATHWITHOOP_POLYNOMIAL_H

#include <vector>
#include <iostream>
#include <cassert>

using namespace std;

class polynomial
{
    vector<vector<int>> coef;

public:
    polynomial();
    polynomial(const polynomial&);

    //operators
    polynomial& operator-();
    bool operator==(const polynomial& obj);
    bool operator>=(const polynomial& obj);
    bool operator<=(const polynomial& obj);
    bool operator<(const polynomial& obj);
    bool operator>(const polynomial& obj);
    friend polynomial operator-(const polynomial& ,const polynomial& );
    friend polynomial operator+(const polynomial& ,const polynomial& );
    friend polynomial operator*(const polynomial& ,const polynomial& );

};


#endif //MATHWITHOOP_POLYNOMIAL_H
