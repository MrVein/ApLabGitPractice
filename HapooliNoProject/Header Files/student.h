//
// Created by learner on 4/7/21.
//

#ifndef HAPOOLINOPROJECT_STUDENT_H
#define HAPOOLINOPROJECT_STUDENT_H
#include <iostream>

using namespace std;

class student
{
    string name;
    string familyName;
    long studentNum;
    float score;
    //for the time that u want to change score
    float lastScore;
    //for sum of scores for average
    static double sumScore;
    //for number of members. and it should be static
    static int members;
    //for student number
    static int core;
    string setStudentNum();

public:
    student(string _name , string _familyName , float _score = 0);
    ~student();
    //setter
    void setName(string _name);
    void setFamilyName(string _familyName);
    void setScore(float _score);

    //getter
    string getName();
    string getFamilyName();
    float getScore();
    long getStudentNum();

    static int getNumOfMembers();
    static float getAverage();
};


#endif //HAPOOLINOPROJECT_STUDENT_H
