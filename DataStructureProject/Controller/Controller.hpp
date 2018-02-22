//
//  Controller.hpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Controller_hpp
#define Controller_hpp

#include <iostream>
#include <vector>
#include "FileController.hpp"
#include "Tools/Timer.hpp"
#include "../Model/Structures/Linear/Array.h"
#include "../Testers/ArrayTester.hpp"
#include "../Testers/LinkedListTester.hpp"

class Controller
{
private:
    void findMaxAndMin();
    void testArray();
    
public:
    void start();
};

#endif /* Controller_hpp */
