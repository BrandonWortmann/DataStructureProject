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
  
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/bwor0809/Documents/C++/DataStructureProject/DataStructureProject/Data/crime.csv");
    
//    for(int i = 200; i < 215; i ++ )
//    {
//        cout << i << " is " << myData[i] << endl;
//    }
    
    codeTimer.stopTimer();
    codeTimer.displayInformation();
    
    findMaxAndMin();
}

void Controller :: findMaxAndMin()
{
    Timer searchTimer;
    searchTimer.startTimer();
    vector<CrimeData> myData = FileController :: readCrimeDataToVector("/Users/bwor0809/Documents/C++/DataStructureProject/DataStructureProject/Data/crime.csv");
    
    int minIndex = 0;
    int maxIndex = 0;
    
    for(int index = 1; index < myData.size(); index++)
    {
        if(myData [minIndex] > myData[index])
        {
            minIndex = index;
        }
        
        else if(myData [maxIndex] < myData[index])
        {
            maxIndex = index;
        }
    }
    searchTimer.stopTimer();
    cout << "The smallest Crime stat is at " << minIndex << " and it is: " << myData[minIndex] << endl;
    cout << "The large Crime stat is at " << maxIndex << " and it is: " << myData[maxIndex] << endl;
    searchTimer.displayInformation();
    
}
