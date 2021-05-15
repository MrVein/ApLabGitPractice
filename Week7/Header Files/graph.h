//
// Created by shazi on 4/27/2021.
//

#ifndef WEEK7_GRAPH_H
#define WEEK7_GRAPH_H
#include <vector>
#include <cassert>
#include <iostream>
#include <string>
#include "node.h"

using namespace std;

template <typename T , int NUM>
class graph
{
    vector<node<T>> nodes;
    T extract(string _str);

public:
    node<T>* find(T _value);
    void addNode(T , vector<string> _edge);
    void addEdge(T , T);
    void removeEdge(T , T);
    void removeNode(T _value);
    void removeNode(node<T>*);

    friend ostream& operator<<(ostream& , const graph<T , NUM>);
};

template <typename T , int NUM>
ostream& operator<<(ostream& , const graph<T , NUM> gr)
{
    for(auto x : gr.nodes)
    {
        cout << x.getValue() << endl;
        for(auto y : x.connections)
            cout << y << endl;
    }
}

template <typename T , int NUM>
void graph<T , NUM>::addEdge(T n1 , T n2)
{
    assert(!find(n1) && !find(n2));
    find(n1)->addConnection(n2);
    find(n2)->addConnection(n1);
}

template <typename T , int NUM>
void graph<T , NUM>::removeEdge(T n1 , T n2)
{
    assert(!find(n1) && !find(n2));
    find(n1)->removeConnection(n2);
    find(n2)->removeConnection(n1);
}

template <typename T , int NUM>
T graph<T , NUM>::extract(string _str)
{
    string substr = _str.substr(_str.find(":"));
    return substr;
}

template <typename T , int NUM>
node<T>* graph<T , NUM>::find(T _value)
{
    for(auto x : nodes)
        if(x.getValue() == _value)
            return &x;

    return NULL;
}

template <typename T , int NUM>
void graph<T , NUM>::addNode(T _val, vector<string> _edge)
{
    node<T> new_node;
    new_node.setValue(_val);

    for(auto x : _edge)
        new_node.addConnection(extract(x));

}

template <typename T , int NUM>
void graph<T , NUM>::removeNode(T _value)
{
    auto it = nodes.find(nodes.begin() , nodes.end() , _value);
    if(it != nodes.end())
        nodes.erase(it);

    for(auto x : nodes)
        if(x.findCon(_value))
            x.removeConnection(_value);

}

template <typename T , int NUM>
void graph<T , NUM>::removeNode(node<T>* _node)
{
    if(!find(_node->getValue()))
        return;

    removeNode(_node->getValue());
}

#endif //WEEK7_GRAPH_H

