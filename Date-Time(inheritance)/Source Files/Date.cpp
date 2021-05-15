//
// Created by shazi on 5/10/2021.
//

#include "../Header Files/Date.h"

Date::Date()
{
    _day = -1;
    _month = -1;
    _year = -1;
}
Date::Date(int year, int month, int day)
{
    _year = year;
    _month = month;
    _day = day;
}

Date Date::strToDate(string _str)
{

    return Date();
}

//operator overloading
ostream& operator<<(ostream& out ,const Date& date)
{
    out << date._year << "/" << date._month << ":" << date._day << endl;
    return out;
}
istream& operator>>(istream& in , Date& date)
{
    string input;
    in >> input;
    date = Date::strToDate(input);

    return in;
}
Date Date::operator+(const Date& obj) const
{
    Date res;
    res._year = this->_year + obj._year;
    res._month = this->_month + obj._month;
    res._day = this->_day + obj._day;

    return res;
}
bool Date::operator>(const Date& obj) const
{
    if((this->_year > obj._year )|| ((this->_year == obj._year) &&(this->_month > obj._month))
    ||((this->_year == obj._year) &&(this->_month == obj._month) && (this->_day > obj._day)))
        return true;
    else
        return false;
}
bool Date::operator>=(const Date& obj) const
{
    if((this->_year > obj._year )|| ((this->_year == obj._year) &&(this->_month > obj._month))
       ||((this->_year == obj._year) &&(this->_month == obj._month) && (this->_day >= obj._day)))
        return true;
    else
        return false;
}
bool Date::operator<(const Date& obj) const
{
    if((this->_year < obj._year )|| ((this->_year == obj._year) &&(this->_month < obj._month))
       ||((this->_year == obj._year) &&(this->_month == obj._month) && (this->_day < obj._day)))
        return true;
    else
        return false;
}
bool Date::operator<=(const Date& obj) const
{
    if((this->_year < obj._year )|| ((this->_year == obj._year) &&(this->_month < obj._month))
       ||((this->_year == obj._year) &&(this->_month == obj._month) && (this->_day <= obj._day)))
        return true;
    else
        return false;
}
Date::operator string() const
{
    string str;
    str = to_string(this->_year) + "/" + to_string(this->_month) + "/" + to_string(this->_day);
    return str;
}

