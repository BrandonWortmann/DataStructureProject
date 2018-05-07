//
//  hashtable.hpp
//  DataStructureProject
//
//  Created by Wortmann, Brandon on 4/27/18.
//  Copyright © 2018 CTEC. All rights reserved.
//

#ifndef hashtable_hpp
#define hashtable_hpp

#include "../Nodes/Hashtable.hpp"
#include <cmath>
#include <assert.h>

template <class Type>
class Hashtable
{
private:
    HashNode<Type> ** internalStorage;
    long size;
    long capacity;
    double loadFactor;
    
    long getNextPrime();
    bool isPrime(long current);
    void resize();
    long findPosition(HashNode<Type>* insertedNode);
    long handleCollision(long currentPosition);
    
public:
    Hashtable();
    ~Hashtable();
    
    void insert(Type data);
    long getSize();
    HashNode<Type> * geet(long index);
    bool contains(HashNode<Type> * value);
    
};

template <class Type>
Hashtable<Type> :: Hashtable()
{
    capacity = 101;
    internalStorage = new HashNode<Type>*[capacity];
    size = 0;
    loadFactor = .80;
}

template <class Type>
Hashtable<Type> :: ~Hashtable()
{
    delete [] internalStorage;
}

template <class Type>
bool Hashtable<Type> :: isPrime(long current)
{
    if(current <= 1)
    {
        return false;
    }
    else if(current == 2 || current == 3)
    {
        return true;
    }
    else if(current % 2 == 0)
    {
        return false;
    }
    else
    {
        for(int next = 3; next <= sqrt(current) +1; next += 2)
        {
            if(current % next == 0)
            {
                return false;
            }
        }
        return true;
    }
}

template <class Type>
long Hashtable<Type> :: findPosition(HashNode<Type> * insert)
{
    long insertPosition = insert->getKey() % this->capacity;
    return insertPosition;
}

template <class Type>
long hashTable<Type> :: handleCollision(long currentPosition)
{
    long shift = 17;
    
    for(long position = currentPosition + shift; position != currentPodition; position += shift)
    {
        if(position >= capacity)
        {
            position = position % capacity;
        }
        if(internalStorage[position] == nullptr)
        {
            return position;
        }
    }
    
    return -1;
    
   
}

template <class Type>
long Hashtable<Type> :: getSize()
{
    return this->size;
}

template <class Type>
long Hashtable<Type> :: getNextPrime()
{
    long nextPrime = (this->capacity * 2) +1;
    
    while(!isPrime(nextPrime))
    {
        nextPrime += 2;
    }
    
    return nextPrime;

template <class Type>
void Hashtable<Type> :: resize()
{
    long updatedCapacity = getNextPrime();
    HashNode<Type> ** tempStorage = new HashNode<Type> * [updatedCapacity];
    
    std :: fill_n(tempStorage, updatedCapacity, nullptr);
    
    long oldCapacity = this->capacity;
    this->capacity = updatedCapacity;
    
    for(long index = 0; index< oldCapacity; index++)
    {
        if(internalStorage[index] != nullptr)
        {
            HashNode<Type> * temp = internalStorage[index];
            
            long position = findPosition(temp);
            if(tempStorage[position] == nullptr)
            {
                tempStorage[position] = temp;
            }
            else
            {
                long updatedPosition = handleCollision(position);
                if(updatedPosition != -1)
                {
                    tempStorage[updatedPosition] = temp;
                }
            }
        }
    }
    
    internalStorage = tempStorage;
}

template <class Type>
void Hashtable<Type> :: insert(Type value)
{
    this->size++;
    if(((this->size * 1.000) / this->capacity) > this->loadFacctor)
    {
        resize();
    }
    
    HashNode<Type> * temp = new HashNode<Type>(value);
    long index = findPosition(temp);
    
    if(internalStorage[index] == nullptr)
    {
        internalStorage[index] = temp;
    }
    else
    {
        long updatedPosition = handleCollision(index);
        if(updatedPosition != -1)
        {
            internal[updatedPosition] = temp;
        }
    }
    
}

template <class Type>
HashNode<Type> * HashTable<Type> :: get(long idex)
{
    assert(index < capacity);
    return internalStorage[index];
}

template <class Type>
bool HashTable<Type> :: contains(HashNode<Type> * value)
{
    if(internalStorage[findPosition(value)]->getData() == value->getData())
    {
        return true;
    }
    
    long other = handleCollision(findPosition(value));
    if(internalStorage[other] ->getData() == value->getData())
    {
        return true;
    }
    
    return false;
}









#endif /* hashtable_hpp */
