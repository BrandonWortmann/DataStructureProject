//
//  Header.h
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 2/2/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef Header_h
#define Header_h

#include <assert.h>
#include <iostream>

using namespace std;

template <class Type>
class Aarray
{
private:
    Type * internalArray;
    int size;
    
public:
    Array<Type>(int size);
    
    array<Type>(const Array<Type> & toCopy);
    
    ~Array<Type>();
    
    Array<Type & operator = (const Array<Type> & toReplace);
    Type& operator [] (int index);
    Type operator [] (int index) const;
    
    int getSize() const;
    Type getFromIndex(int index);
    void setAtIndex(int index, Type data);
    
}
template <class Type>
Array<Type> :: Array(int size)
{
    assert(size > 0);
    this -> size = size;
    
    internalArray = new Type[size]
        
}

template <class Type>
Array<Type> :: Array(const Array<Type> & toCopy)
{
    this->size = toCopy.getSize();
    
    internalArray = new Type[size];
    
    for(int index = 0; index < size; index++)
    {
        internalArray[index] = toCopy[index];
    }
    
}
    
template <class Type>
Array<Type> :: ~Array()
{
    delete[] internalArray;
}
    
template <class Type>
Array<Type> & Array<Type> :: operator = (const Array<Type> & toAssign)
{
    if(&toAssign != this)
    {
        if(size != toAssign.getSize())
        {
            delete [] internalAray;
            size = toAssign.getSize();
            internalArray + new Type [size];
        }
        
        for(int i = 0; index < size; i++)
        {
            internalArray[i] = toAssign[i];
        }
    }
    return * this;
        
}
    
template <class Type>
Type & Array<Type> :: operator [] (int index)
{
    assert(index >= 0 && index < size);
    return internalArray[index];
}
    
template <class Type>
Type Array<Type> :: operator [] (int index) const
{
    assert(index >= 0 && index < size);
    return internalArray[index];
}

template <class Type>
int Array<Type :: getSize() const
{
    return size;
}
    
template <class Type>
Type Array<Type> :: getFromIndex(int index)
{
    assert(index >= 0 && index < size);
    
    Type value = internalArray[index];
    
    return value;
}
    
template <class Type>
void Array<Type> :: setAtIndex(int pos, Type item)
{
    assert(pos >= 0 && pos < size);
    internalArray[pos] = item;
}

#endif /* Header_h */
