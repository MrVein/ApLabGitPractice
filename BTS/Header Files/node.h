//
// Created by learner on 4/3/21.
//

//#ifndef BTS_NODE_H
//#define BTS_NODE_H
#include <iostream>

template<typename T>
class node
{
    T data;
    node* left , *right;

public:
    node();
    node(T  data);
    node(const node &);
    ~node();


    //getter
    T getData();
    node* getLeft();
    node* getRight();
    //setter
    void setData(T _data);
    void setLeft(node*);
    void setRight(node*);
};

//
// Created by learner on 4/3/21.
//

//#endif //BTS_NODE_H
