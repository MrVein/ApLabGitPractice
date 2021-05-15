//
// Created by learner on 4/1/21.
//

#ifndef BTS_BST_H
#define BTS_BST_H
#include <iostream>
#include "node.h"
template<typename T>
class BST
{
    node<T>* root;
    node<T>* search(node<T>* , T);
    node<T>* addNode(node<T>* root , T data);
    node<T>* deleteNode(node<T>* root , T key);
    void inorderPrint(node<T>* root);
    void postorderPrint(node<T>* root);
    void preorderPrint(node<T>* root);

public:
    BST();
    BST(T data);
    ~BST();
    //return nullptr if no node was found .Otherwise returns a pointer to the considered node
    node<T>* search(T key);
    //returns changed BST's root node
    node<T>* addNode(T data);
    //Delete node
    node<T>* deleteNode(T key);
    //Inorder traversal
    void inorderPrint();
    //Postorder traversal
    void postorderPrint();
    //Preorder traversal
    void preorderPrint();
    //Recursively destroys the tree;
    void destroyRecursive(node<T>* root);
};

//
// Created by learner on 4/1/21.
//

//#include "../Header Files/BST.h"

template<typename T>
BST<T>::BST()
{
    root = nullptr;
}

template<typename T>
BST<T>::BST(T data)
{
    root = new node<T>;
    root->setData(data);
    root->setLeft(nullptr);
    root->setRight(nullptr);
}

template<typename T>
BST<T>::~BST()
{
    destroyRecursive(root);
}

template<typename T>
node<T>* BST<T>::search(node<T>* _root , T key)
{
    //base case
    if(_root == nullptr || _root->getData() == key)
        return _root;
    //greater than root data:
    if(_root->getData() < key)
        return search(_root->getRight() , key);
    //smaller than root data:
    if(_root->getData() > key)
        return search(_root->getLeft() , key);
}

template<typename T>
node<T>* BST<T>::search(T key)
{
    return search(root , key);
}

template<typename T>
node<T>* BST<T>::addNode(node<T>* root , T data)
{
    if(!root)
    {
        return new node<T>(data);
    }
    if(root->getData() == data)
        return root;
    if(data > root->getData())
    {
        root->setRight(addNode(root->getRight() , data));
    }
    else
    {
        root->setLeft(addNode(root->getLeft() , data));
    }
    return root;
}

template<typename T>
node<T>* BST<T>::addNode(T data)
{
    root = addNode(root , data);
    return root;
}

template<typename T>
void BST<T>::inorderPrint(node<T>* root)
{
    if(!root)
        return;
    inorderPrint(root->getLeft());
    std::cout << root->getData() << std::endl;
    inorderPrint(root->getRight());

}

template<typename T>
void BST<T>::inorderPrint()
{
    if(!root)
        return;
    inorderPrint(root->getLeft());
    std::cout << root->getData() << std::endl;
    inorderPrint(root->getRight());
}

template<typename T>
void BST<T>::postorderPrint(node<T>* root)
{
    if(!root)
        return;
    inorderPrint(root->getLeft());
    inorderPrint(root->getRight());
    std::cout << root->getData() << std::endl;

}

template<typename T>
void BST<T>::postorderPrint()
{
    postorderPrint(root);
}

template<typename T>
void BST<T>::preorderPrint(node<T>* root)
{
    if(!root)
        return;
    std::cout << root->getData() << std::endl;
    inorderPrint(root->getLeft());
    inorderPrint(root->getRight());

}

template<typename T>
void BST<T>::preorderPrint()
{
    preorderPrint(root);
}

template<typename T>
node<T>* BST<T>::deleteNode(node<T>* root , T key)
{
    //base case
    if(root == nullptr)
        return root;
    if(root->getData() > key)
    {
        root->setLeft( deleteNode(root->getLeft(), key));
        return root;
    }
    else if(root->getData() < key)
    {
        root->setRight(deleteNode(root->getRight() , key));
        return root;
    }

    //here we reached the node to be deleted

    //if the node has only one child :
    if(root->getLeft() == nullptr)
    {
        node<T>* temp = root->getRight();
        delete root;
        return temp;
    }
    else if(root->getRight() == nullptr)
    {
        node<T>* temp = root->getLeft();
        delete root;
        return temp;
    }
        //if has 2 children:
    else
    {
        //reaching the proper node to replace the node to be deleted
        node<T>* successorParent = root;
        node<T>* successor = root->getRight();
        while(successor->getLeft() != nullptr)
        {
            successorParent = successor;
            successor = successor->getLeft();
        }

        if(successorParent != root)
            successorParent->setLeft(successor->getRight());
        else
            successorParent->setRight(successor->getRight());

        root->setData(successor->getData());

        delete successor;
        return root;

    }


}

template<typename T>
node<T>* BST<T>::deleteNode(T key)
{
    return deleteNode(root , key);
}

template<typename T>
void BST<T>::destroyRecursive(node<T>* root)
{
    if (root)
    {
        destroyRecursive(root->getLeft());
        destroyRecursive(root->getRight());
        delete root;
    }
}




#endif //BTS_BST_H
