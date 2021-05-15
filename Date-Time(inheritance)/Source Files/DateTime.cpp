//
// Created by shazi on 5/11/2021.
//

#include "../Header Files/DateTime.h"
DateTime::DateTime(int year, int month, int day, int hour, int minute): Time(hour , minute)
{

}

DateTime DateTime::strToDateTime(string str)
{
    //input form : 1399/12/15 5:14
    string token;
    string delimiter = "/";
    size_t pos = 0;
    vector<int> res;
    while((pos = str.find(delimiter)) != string::npos)
    {
        token = str.substr(0 , pos);
        res.emplace_back(stoi(token));
        str.erase(0 , pos + delimiter.length());
    }

    pos = str.find(' ');
    token = str.substr(0 , pos);
    res.emplace_back(stoi(token));
    str.erase(0 , pos + delimiter.length());

    pos = str.find(':');
    token = str.substr(0 , pos);
    res.emplace_back(stoi(token));
    str.erase(0 , pos + delimiter.length());

    res.emplace_back(stoi(str));

    return DateTime(res[0] , res[1] , res[2] , res[3] , res[4]);
}

//operator overloading
istream& operator>>(istream& in , DateTime& obj)
{
    string input;
    in >> input;
    obj = DateTime::strToDateTime(input);
    return in;
}
ostream& operator<<(ostream& out , const DateTime& obj)
{
    out  << obj._year << "/" << obj._month << "/" << obj._day << " and "
    <<  obj._hour << ":" << obj._minute << endl;

    return out;
}
DateTime DateTime::operator+(const DateTime& obj) const
{
    DateTime res(0 , 0 , 0 , 0 , 0);
    res._year = this->_year + obj._year;
    res._month = this->_month + obj._month;
    res._day = this->_day + obj._day;

    res._hour = this->_hour + obj._hour;
    res._minute = this->_minute + obj._minute;

    return res;

}
DateTime::operator string()
{
    string str;
    str = to_string(this->_year) + "/" + to_string(this->_month) + "/" + to_string(this->_day)
            + " and " + to_string(this->_hour) + ":" + to_string(this->_minute);
    return str;
}

