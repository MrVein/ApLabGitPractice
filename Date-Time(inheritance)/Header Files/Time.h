//
// Created by shazi on 5/9/2021.
//

#ifndef DATE_TIME_INHERITANCE__TIME_H
#define DATE_TIME_INHERITANCE__TIME_H

#include<iostream>
#include<string>
using namespace std;

class Time{

protected:
    int _hour;
    int _minute;

public:
    Time(int hour , int minute);
    Time(int hour);
    int getHour() const;
    int getMinute() const;
    void setHour(int hour);
    void setMinute(int minute);

    int compare(Time time);
    string tellTime(int hour , int minute);

    Time operator+(const Time& t) const;
    friend istream& operator >> (istream& in ,Time& t);
    friend ostream& operator << (ostream &out ,const  Time &t);
    friend bool operator<(const Time& t1, const Time& t2);
    friend bool operator<=(const Time& t1, const Time& t2);
    friend bool operator>(const Time& t1, const Time& t2);
    friend bool operator>=(const Time& t1, const Time& t2);

    virtual //this could be "explicit"
    operator string()
    {
        string str;
        str = to_string(this->getHour());
        str += ":";
        str += to_string(this->getMinute());
        return str;
    }
};




#endif //DATE_TIME_INHERITANCE__TIME_H
