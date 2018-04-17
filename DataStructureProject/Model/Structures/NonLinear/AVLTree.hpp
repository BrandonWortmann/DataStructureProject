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


#endif /* AVLTree_hpp */

