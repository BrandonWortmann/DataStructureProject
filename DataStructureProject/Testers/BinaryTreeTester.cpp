//
//  BinaryTreeTester.cpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 3/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "BinaryTreeTester.hpp"

void BinaryTreeTester :: doTreeStuff()
{
    testTree.insert("hi");
    testTree.insert("hello");
    testTree.insert("how are you");
    testTree.insert("I am good");
    testTree.insert("fries");
    testTree.insert("Burger");
    
    testTree.inOrderTraversal();
    testTree.postOrderTraversal();
    testTree.preOrderTraversal();
    
    
    
}
