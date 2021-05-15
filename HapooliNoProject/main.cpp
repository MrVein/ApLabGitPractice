#include <iostream>
#include "Header Files/student.h"

int main()
{
    student one("hamid" , "azimi" , 20);
    cout << one.getStudentNum() << endl;

    student one2("hasan" , "azimi" ,3);
    cout << one2.getStudentNum() << endl;

    student one3("haripater" , "azimi"  , 10);
    cout << one3.getStudentNum() << endl;
    one3.setScore(12.5);
    cout << one3.getStudentNum() << endl;

    student one4("haamed" , "azimi"  , 13);
    cout << one4.getStudentNum() << endl;

    student one5("halime" , "azimi"  , 5);
    cout << one5.getStudentNum() << endl;

    student* one6 = new student("hormoz" , "azimi" , 19);
    cout << one6->getStudentNum() << endl;



    //cout << student::getAverage() << endl;
    //cout << student::getNumOfMembers() << endl;

    delete one6;
    student one7("halime" , "azimi"  , 5);

    cout << one7.getStudentNum() << endl;

//    cout << student::getAverage() << endl;
//   cout << student::getNumOfMembers() << endl;

    return 0;
}
