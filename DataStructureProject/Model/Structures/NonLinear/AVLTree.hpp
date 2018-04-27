//
//  AVLTree.hpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 4/17/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef AVLTree_hpp
#define AVLTree_hpp

#include "BianrySearchTree.hpp"

template <class Type>
class AVLTree : public BinarySearchTree<Type>
{
private:
    BinaryTreeNode<Type> * leftRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * leftRightRotation(BinaryTreeNode<Type> * parent);
    BinaryTreeNode<Type> * rightLeftRotation(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * balanceSubTree(BinaryTreeNode<Type> * parent);
    
    BinaryTreeNode<Type> * insertNode(BinaryTreeNode<Type> * parent, Type value);
    BinaryTreeNode<Type> * removeNode(BinaryTreeNode<Type> * parent, Type value);
    
    int heightDifference(BinaryTreeNode<Type>* parent);
    
public:
    AVLTree();
    
    void insert(Type itemToInsert);
    void remove (Type value);
    
    
    
    
};

template <class Type>
AVLTree<Type> :: AVLTree() : BinarySearchTree<Type>()
{
    this->root = nullptr;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: removeNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        return parent;
    }
    if(inserted < parent->getNodeData())
    {
        parent->setLeftChild(removeNode(parent->getLeftNode(), inserted));
    }
    else if(inserted > parent ->getNodeData())
    {
        parent->setRightChild(removeNode(parent->getRightNode(), inserted));
    }
    else
    {
        BinaryTreeNode<Type> * temp;
        if(parent->getLefttNode() == nullptr  && parent->getRightNode() == nullptr)
        {
            temp = parent;
            delete temp;
        }
        else if(parent ->getLeftNode() == nullptr)
        {
            *parent = *parent->getRightNode();
        }
        else if(parent->getLeftNode() == nullptr)
        {
            *parent = *parent->getLeftNode();
        }
        else
        {
            BinaryTreeNode<Type> * leftMost = this->getLeftMostChild(parent->getRightNode());
            parent->setNodedata(leftMost->getNodeData());
            parent->setRightChild(removeNode(parent->getRihtNode(), leftMost->getNodeData()));
        }
    }
    if(parent == nullptr)
    {
        return parent;
    }
    
    return balancecdSubTree(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: insertNode(BinaryTreeNode<Type> * parent, Type inserted)
{
    if(parent == nullptr)
    {
        parent = new BinaryTreeNode<Type>(inserted);
        return parent;
    }
    else if (inserted < parent ->getNodeData())
    {
        parent->setLeftChild(inserteNode(parent->getLeftNode(), inserted));
        parent = balancedSubTreee(parent);
    }
    else if(inserted > parent->getNodeData())
    {
        parent->setRightChild(insertNode(parent->getRightNode(), inserted));
        parent = balanceSubTree(parent);
    }
    return parent;
}

template <class Type>
int AVLTree<Type> :: heightDifference(BinaryTreeNode<Type> * node)
{
    int balance;
    int leftHeigth = this->calculateHeight(node->getLeftNode());
    int rightHeight = this->calclateHeight(node->getRightNode());
    balance = leftHeigth - rightHeigth;
    return balance;

}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRotation(BianryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getLeftNode();
    
    parent->setLeftChild(changedNode->getRightNode());
    
    changedNode->setRightChild(paarent);
    
    return changeedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rigthRotation(BianryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent->getRightNode();
    
    parent->setLeftChild(changedNode->getLeftNode());
    
    changedNode->setLeftChild(paarent);
    
    return changeedNode;
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: rightLeftRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent -> getRightNode();
    
    parent->setRightChild(leftRotation(changedNode));
    
    return rightRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: leftRightRotation(BinaryTreeNode<Type> * parent)
{
    BinaryTreeNode<Type> * changedNode;
    changedNode = parent -> getLeftNode();
    
    parent->setLeftChild(RightRotation(changedNode));
    
    return leftRotation(parent);
}

template <class Type>
BinaryTreeNode<Type> * AVLTree<Type> :: balanceSubTree(BinaryTreeNode<Type> * parent)
{
    int balanceFactor = heightDifference(parent);
    
    if(balanceFactor > 1)
    {
        if(heigthDifference(parent->getLeftNode()) > 0)
        {
            parent = leftRotation(parent);
        }
        else
        {
            parent = leftRightRotatiom(parent);
        }
    }
    else if(balanceFactor < -1)
    {
        if(heightDifference(parent->getRightNode()) > 0)
        {
            parent = rightLeftRotation(parent);
        }
        else
        {
            parent = rightRotation(parent);
        }
    }
    
    return parent;
}

template <class Type>
void AVLTree<Type> :: insert(Type item)
{
    insertNode(this ->getRoot(), item);
}

template <class Type>
void AVLTree<Type> :: remove(Type item)
{
    remoeNode(this->getRoot(), item);
}




#endif /* AVLTree_hpp */

