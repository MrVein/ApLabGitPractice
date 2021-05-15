//
// Created by shazi on 4/30/2021.
//

#include "../Header Files/polynomial.h"

polynomial::polynomial()
{
    coef.emplace_back(1 ,0);
}
polynomial::polynomial(const polynomial& obj)
{
    coef = obj.coef;
}

polynomial& polynomial::operator-()
{
    for(auto x: coef[0])
        x *= -1;
    return *this;
}
bool polynomial::operator==(const polynomial& obj)
{
    if(obj.coef[1] == this->coef[1] && obj.coef[0] == this->coef[0])
        return true;
    else
        return false;
}
bool polynomial::operator>=(const polynomial& obj)
{
    assert((*this) == obj);
    for(int i = 0 ; i < obj.coef[0].size() ; ++i)
        if(this->coef[0][i] >= obj.coef[0][i])
            return true;

    return false;
}
bool polynomial::operator<=(const polynomial& obj)
{
    assert((*this) == obj);
    for(int i = 0 ; i < obj.coef[0].size() ; ++i)
        if(this->coef[0][i] <= obj.coef[0][i])
            return true;

    return false;
}
bool polynomial::operator<(const polynomial& obj)
{
    assert((*this) == obj);
    for(int i = 0 ; i < obj.coef[0].size() ; ++i)
        if(this->coef[0][i] < obj.coef[0][i])
            return true;

    return false;
}
bool polynomial::operator>(const polynomial& obj)
{
    assert((*this) == obj);
    for(int i = 0 ; i < obj.coef[0].size() ; ++i)
        if(this->coef[0][i] > obj.coef[0][i])
            return true;

    return false;
}

polynomial operator-(const polynomial& obj1 ,const polynomial& obj2 )
{
    polynomial res;

    for(int i = 0 ; i < obj1.coef[1].size() ; i++)
        for(int j = 0 ; j < obj2.coef[1].size() ; j++)
            if(obj1.coef[1][i] ==  obj2.coef[1][j])
            {
                int temp = obj1.coef[0][i] - obj2.coef[0][j];

                if(temp)
                {
                    res.coef[0].emplace_back(temp);
                    res.coef[1].emplace_back(obj2.coef[1][j]);
                }
            }

}
polynomial operator+(const polynomial& obj1 ,const polynomial& obj2 )
{
    polynomial res;

    for(int i = 0 ; i < obj1.coef[1].size() ; i++)
        for(int j = 0 ; j < obj2.coef[1].size() ; j++)
            if(obj1.coef[1][i] ==  obj2.coef[1][j])
            {
                int temp = obj1.coef[0][i] + obj2.coef[0][j];

                if(temp)
                {
                    res.coef[0].emplace_back(temp);
                    res.coef[1].emplace_back(obj2.coef[1][j]);
                }
            }

}
polynomial operator*(const polynomial& obj1 ,const polynomial& obj2)
{
    polynomial res;

    for(int i = 0 ; i < obj1.coef[1].size() ; ++i)
        for(int j = 0 ; j < obj2.coef[1].size() ; ++j)
        {
            res.coef[1].emplace_back(obj1.coef[1][i] * obj1.coef[1][i]);
            res.coef[0].emplace_back(obj1.coef[0][i] * obj1.coef[0][i]);
        }
    return res;
}
