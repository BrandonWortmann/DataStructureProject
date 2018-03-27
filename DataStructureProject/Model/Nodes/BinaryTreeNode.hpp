//
//  BinaryTreeNode.hpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef BinaryTreeNode_hpp
#define BinaryTreeNode_hpp

#include <Node.hpp>
template <class Type>
class BinaryTreeNode<Type> : public Node<Type>
{
private:
    BinaryTreeNode<Type> * root;
    BinaryTreeNode<Type> * left;
    BinatyTreeNode<Type> * right;
    
public:
    BinaryTreeNode();
    BinaryTreeNode(Type data);
    
    BinaryNode<Type> * getRoot();
    BinaryNode<Type> * getLeft();
    BinaryNode<Type> * getRight();
    
    void setRootNode(BinaryTreeNode<Type> * root);
    void setLeftNode(BinayTreeNode<Type> * left);
    void setRightNode(BinaryTreeNode<Type> * right);
    
    
    
};

template<class Type>
BinaryTreeNode<Type> :: BinaryTreeNode() : Node<Type>()
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
}

template<class Type>
BinaryTreeNode<Type> :: BinaryTreeNode(Type data) : Node<Type>(data)
{
    root = nullptr;
    left = nullptr;
    right = nullptr;
}

template<class Type>
void BinaryTree<Type> :: setRoot(DoubleNode<Type> * Root)
{
    this->root = root;
}

template<class Type>
void BinaryTree<Type> :: setLeft(DoubleNode<Type> * left)
{
    this->root = left;
}

template<class Type>
void BinaryTree<Type> :: setRight(DoubleNode<Type> * right)
{
    this->root = right;
}

template <class Type>
BinaryTree<Type> * BinaryTree<Type> :: getRoot()
{
    return root;
}

template <class Type>
BinaryTree<Type> * BinaryTree<Type> :: getLeft()
{
    return left;
}

template <class Type>
BinaryTree<Type> * BinaryTree<Type> :: getRight()
{
    return right;
}

#endif /* BinaryTreeNode_hpp */
