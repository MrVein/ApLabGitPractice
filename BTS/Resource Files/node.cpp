//moved to node.h
//#include "../Header Files/node.h"

template<typename T>
node<T>::node()
{
    data = 0;
    left = nullptr;
    right = nullptr;
}
template<typename T>
node<T>::node(T _data)
{
    data = _data;
    right = nullptr;
    left = nullptr;
}
template<typename T>
node<T>::node(const node& _node)
{
    data = _node.data;
    if(_node.left)
        *left = *_node.left;
    if(_node.right)
        *right = *_node.right;
}

template<typename T>
T node<T>::getData()
{
    return data;
}
template<typename T>
node<T>* node<T>::getLeft()
{
    return left;
}
template<typename T>
node<T>* node<T>::getRight()
{
    return right;
}
template<typename T>
void node<T>::setData(T _data)
{
    data = _data;
}
template<typename T>
void node<T>::setLeft(node<T>* _node)
{
    left = _node;
}
template<typename T>
void node<T>::setRight(node<T>* _node)
{
    right = _node;
}
template<typename T>
node<T>::~node<T>()
{}
template class node<int>;
