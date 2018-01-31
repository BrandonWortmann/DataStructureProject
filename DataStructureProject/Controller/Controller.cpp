//
//  Controller.cpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "Controller.hpp"

using namespace std;

void Controller :: start()
{
    Timer codeTimer;
    codeTimer.startTimer();
    cout << "Lookcode on the screen" << endl;
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    codeTimer.resetTimer();
    codeTimer.startTimer();
    for(int i = 0; i<50000; i++)
    {
        cout << "Index is " << i << "\t";
    }
    codeTimer.stopTimer();
    codeTimer.displayInformation();
}
