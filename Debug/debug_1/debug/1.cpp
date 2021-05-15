#include <iostream>
#include <string>
#include <math.h>
#include <gtest/gtest.h>
using namespace std;

long long *b;

long long int factorial(int n)
{
    return (n == 1 || n == 0) ? 1 : factorial(n - 1) * n;
}

long long int *producingTheFactorialFractions()
{
    long long *b = new long long [10];

    for (int i = 10; i >= 0; i--)
    {
        b[i] = (long long)pow(factorial(10), 2.0) / (i + 1);
        //cout << (long long)pow(factorial(10), 2.0)<< endl;
    }

    return b;
}

void checkZeros(long long *a)
{
    //problem .if a is null ,when we assign a number to it or even saying "a[i]" , we access where we are not allowed to.so SEGMENT FAULT happens.
    //correction : one if should be out side of loop and first check for "a" not being null
    if(a!= nullptr)
        for (int i = 9; i >= 0; i--)
        {
            //here it should be "==" operator else it would not give the answer we want to .(no compilation error though.)
            if (a[i] == 0)
                cout << "Zero Found" << endl;
        }
}

int main()
{

    long long int *a;
    a = producingTheFactorialFractions();
    checkZeros(a);
    //problem: we should first check if a is not nullptr before trying to access its elements
    //correction : an if to check whether its null or not befor entering the loop
    if(a!= nullptr)
        for (int i = 0; i < 10; i++)
        {
            cout << a[i] << endl;
        }
    // delete is not needed for stack allocated variables .
    //delete a;

}