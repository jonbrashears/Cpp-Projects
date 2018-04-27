#include <iostream>

using namespace std;

#ifndef COLLECTION_H_INCLUDED
#define COLLECTION_H_INCLUDED

class collection{

public:
	collection();//constructor
	virtual void add(int value) = 0; //adds the value to the array
	virtual void remove(int index) = 0; //removes and item from the appropriate index location
	virtual void print() = 0; //prints item of the array comma separated.
	virtual int get(int index) = 0; //gets item at a particular index.
	virtual int sum() = 0; //gets the sum of the array
	virtual int size() = 0; //gets the size of the array

};

#endif // COLLECTION_H_INCLUDED
