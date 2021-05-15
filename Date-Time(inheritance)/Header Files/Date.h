//
// Created by shazi on 5/10/2021.
//

#ifndef DATE_TIME_INHERITANCE__DATE_H
#define DATE_TIME_INHERITANCE__DATE_H
#include <iostream>
#include <regex>

using namespace std;

class Date
{
protected:
    int _year , _month , _day;

    //private methods :
    static Date strToDate(string _str);

public:
    Date();
    Date(int year , int month , int day);

    //operator overloading :
    friend ostream& operator<<(ostream& out ,const Date& date);
    friend istream& operator>>(istream& in , Date& date);
    Date operator+(const Date& obj) const;
    bool operator>(const Date& obj1) const;
    bool operator>=(const Date& obj1) const;
    bool operator<(const Date& obj1) const;
    bool operator<=(const Date& obj1) const;
    operator string() const;

};


#endif //DATE_TIME_INHERITANCE__DATE_H
