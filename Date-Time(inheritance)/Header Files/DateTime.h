//
// Created by shazi on 5/11/2021.
//

#ifndef DATE_TIME_INHERITANCE__DATETIME_H
#define DATE_TIME_INHERITANCE__DATETIME_H
#include "Date.h"
#include "Time.h"
#include <string>

class DateTime : public Time , public Date
{
    static DateTime strToDateTime(string str);

public:
    DateTime(int , int , int , int , int );
    friend istream& operator>>(istream& in , DateTime& obj);
    friend ostream& operator<<(ostream& out , const DateTime& obj);
    DateTime operator+(const DateTime& obj) const;
    operator string();
};


#endif //DATE_TIME_INHERITANCE__DATETIME_H
