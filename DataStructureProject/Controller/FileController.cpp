//
//  FileController.cpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 1/31/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#include "FileController.hpp"

vector<CrimeData> FileController :: readCrimeDataToVector(string filename)
{
    
    std :: vector<CrimeData> crimeVector;
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(filename);
    
    if(dataFile.is_open())
    {
        while (!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\n');
            
            if(rowCount != 0)
            {
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimeVector.push_back(row);
                }
                
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "NO FILE" << endl;
    }
    return crimeVector;
}

LinkedList<CrimeData> FileController :: readDataToList(string fileName)
{
    LinkedList<CrimeData> crimes;
    
    string currentCSVLine;
    int rowCount = 0;
    
    ifstream dataFile(fileName);
    
    if (dataFile.is_open())
    {
        while (!dataFile.eof())
        {
            getline(dataFile, currentCSVLine, '\n');
            
            if(rowCount != 0)
            {
                if(currentCSVLine.length() != 0)
                {
                    CrimeData row(currentCSVLine);
                    crimes.add(row);
                }
            }
            rowCount++;
        }
        dataFile.close();
    }
    else
    {
        cerr << "No File" << endl;
    }
    
    return crimes;
}
