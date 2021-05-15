//
// Created by shazi on 5/9/2021.
//

#include "../Header Files/Time.h"

Time::Time(int hour)
{
    setHour(hour);
    setMinute(0);
}
Time::Time(int hour, int minute)
{
    setHour(hour);
    setMinute(minute);
}
void Time::setHour(int hour)
{
    if(hour < 24 && hour >= 0)
    {
        _hour = hour;
        return;
    }
    abort();
}
void Time::setMinute(int minute) {
    if(minute >= 0 && minute < 60)
    {
        _minute = minute;
        return;
    }
    abort();
}
int Time::getHour() const
{
    return _hour;
}
int Time::getMinute() const
{
    return _minute;
}
int Time::compare(Time time)
{
    if (time._hour > _hour || (time._hour == _hour && time._minute > _minute))
        return 1;
    if (time._hour == _hour && time._minute == _minute)
        return 0;
    return -1;

}
string Time::tellTime(int hour , int minute)
{
    if(hour >= 0 && hour <= 11 && minute < 60 && minute >= 0)
        return "Morning";
    if(hour == 12 && minute == 0)
        return "Noon";
    if(hour > 12 && hour <= 16 && minute < 60 && minute >= 0 || (hour == 12 && minute > 0 && minute < 60))
        return "Afternoon";
    if(hour >= 17 && hour <= 19 && minute >= 0 && minute < 60)
        return "Evening";
    if(hour >= 20 && hour < 24 && minute >= 0 && minute < 60)
        return "Night";
    else
        return "Wrong input\n";
}

//operator overloading
istream& operator>>(istream& in , Time& t)
{
    //deliberately used setter functions to avoid improper input
    int hour;
    int minute;

    cout << "Enter Hour: " << endl;
    in >> hour;
    t.setHour(hour);

    cout << "Enter Minute: " << endl;
    in >> minute;
    t.setMinute(minute);

    return in;
}
ostream& operator<<(ostream &out,  const Time &t)
{
    out << t._hour <<":"<< t._minute << endl;
    return out;
}
bool operator<(const Time& t1, const Time& t2)
{
    if((t1._hour < t2._hour) || ((t1._hour == t2._hour) && t1._minute < t2._minute))
        return true;
    else
        return false;
}
bool operator<=(const Time& t1, const Time& t2)
{
    if((t1._hour < t2._hour) || ((t1._hour == t2._hour) && t1._minute <= t2._minute))
        return true;
    else
        return false;
}
bool operator>(const Time& t1, const Time& t2)
{
    if((t1._hour > t2._hour) || ((t1._hour == t2._hour) && t1._minute > t2._minute))
        return true;
    else
        return false;
}
bool operator>=(const Time& t1, const Time& t2)
{
    if((t1._hour > t2._hour) || ((t1._hour == t2._hour) && t1._minute >= t2._minute))
        return true;
    else
        return false;
}
Time Time::operator+(const Time& t) const
{
    int hour = 0;
    int minute  = 0;
    Time temp(0 , 0);

    if((this->getMinute() + t.getMinute()) >= 60)
    {
        minute = (this->getMinute() + t.getMinute()) - 60;
        hour++;
    }
    else
        minute = (this->getMinute() + t.getMinute());
    if((this->getHour()+ t.getHour()) >= 24)
        hour += (this->getHour() + t.getHour()) - 24;
    else
        hour += (this->getHour() + t.getHour());

    temp.setHour(hour);
    temp.setMinute(minute);

    return temp;
}
