#include <iostream>
#include <vector>
#include "Header Files/test.h"

using namespace std;

int main()
{
    vector<int> vec;
     vec.emplace_back(2);
     vec.emplace_back(3);
     vec.emplace_back(1);
vector<int> vec2;
     vec2.emplace_back(1);
     vec2.emplace_back(3);
     vec2.emplace_back(2);


    cout << (vec2 == vec);


}