//
// Created by shazi on 4/27/2021.
//

#ifndef WEEK7_NODE_H
#define WEEK7_NODE_H
#include<iostream>
#include<vector>

using namespace std;

template <typename T>
class node
{
    T value;
    vector<T> connection;
public:
    //getter
    T getValue();
    vector<T> getConnection();

    //setter
    void setValue(T _value);
    void addConnection(T _value);

    void removeConnection(T _value);
    bool findCon(T _value);

};

template <typename T>
bool node<T>::findCon(T _value)
{
    if(connection.find(connection.begin() , connection.end() , _value))
        return true;
    else
        return false;
}

template <typename T>
T node<T>::getValue()
{
    return value;
}

template <typename T>
vector<T> node<T>::getConnection()
{
    return connection;
}

template <typename T>
void node<T>::setValue(T _value)
{
    value = _value;
}

template <typename T>
void node<T>::addConnection(T _value)
{
    connection.push_back(_value);
}

template <typename T>
void node<T>::removeConnection(T _value)
{
    auto it = std::find(connection.begin() , connection.end() , _value);
    if(it != connection.end())
        connection.erase(it);
}


#endif //WEEK7_NODE_H
