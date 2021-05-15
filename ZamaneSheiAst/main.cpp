#include<iostream>
#include<string>
using namespace std;

class Time{
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

    //this could be "explicit"
    operator string()
    {
        string str;
        str = to_string(this->getHour());
        str += ":";
        str += to_string(this->getMinute());
        return str;
    }

private:
    int _hour;
    int _minute;
};

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

//operator overloading :
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


int main()
{
//    Time t1(4);
//    Time t2(23 , 5);
//    //t2.setHour(3);
//    //t2.setMinute(59);
//    cout << t1.compare(t2) << endl;
//    cout << t2.getHour() << endl;
//    cout << t2.getMinute() << endl;
//    //cout << t2.tellTime(20, 0) << endl;
    Time t1(5 , 38);
    Time t2(0 , 46);
//    cout << t1;
//    cin >> t1;
//    cout << t1;

//    cout << (t1 <= t2) <<endl;
//    cout << (t1 < t2) <<endl;
//    cout << (t1 >= t2) <<endl;
//    cout << (t1 > t2) <<endl;
//
//    cout << t1 + t2 << endl;

    cout << (string) t1;

    return 0;
}

