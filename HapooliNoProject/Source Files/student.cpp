//
// Created by learner on 4/7/21.
//

#include "../Header Files/student.h"
#include <cmath>
#include <cstring>

int student::members;
double student::sumScore;
int student::core;

student::student(string _name ,string _familyName , float _score)
{
    name = _name;
    familyName = _familyName;
    lastScore = 0;
    studentNum = stoi(setStudentNum());
    setScore(_score);
    members++;
    core++;
}
student::~student()
{
    members--;
    score -= lastScore;
}
//setter
void student::setName(std::string _name)
{
    name = _name;
}
void student::setFamilyName(string _familyName)
{
    familyName = _familyName;
}
void student::setScore(float _score)
{
       sumScore -= lastScore;
       sumScore += _score;
       lastScore = _score;
}

//getter
string student::getName()
{
    return name;
}
string student::getFamilyName()
{
    return familyName;
}
float student::getScore()
{
    return score;
}
long student::getStudentNum()
{
    return studentNum;
}

int student::getNumOfMembers()
{
    return members;
}
float student::getAverage()
{
    return sumScore/members;
}
string student::setStudentNum()
{
    string t1 = "99";
    string t2 = to_string(core);
    string t3 = "3";
    return t1+t2+t3;
}
