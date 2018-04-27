#include <iostream>
#include "collection.h"

using namespace std;
#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

class Items: public collection{
private:
    int *myArray;  //dynamic array
    int arraySize; //size of array
    int nextIndex; //holds the next element
    void selectionSort(); //sorting algorithm

public:
	Items();//constructor
	virtual void add(int value); //adds the value to the array
	virtual void remove(int index); //removes and item from the appropriate index location
	virtual void print(); //prints item of the array comma separated.
	virtual int get(int index); //gets item at a particular index.
	virtual int sum(); //gets the sum of the array
	virtual int size(); //gets the size of the array

    friend void operator +(Items obj1, Items obj2);
    friend void operator -(Items obj1, Items obj2);
    friend void operator /(Items obj1, Items obj2);
    friend void operator *(Items obj1, Items obj2);
    friend void operator <<(Items obj1, Items obj2);
};

#endif // ITEMS_H_INCLUDED
