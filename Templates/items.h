#ifndef ITEMS_H_INCLUDED
#define ITEMS_H_INCLUDED

#include <iostream>
using namespace std;

template <class T>
class Items {
private:
    T* myArray;                         // dynamic array
    int arraySize;                      // size of array
    int nextIndex;                      // holds the next element
    void selectionSort();               // sorting algorithm

public:
    Items();                            // constructor
    virtual void add(T value);          // adds the value to the array
    virtual void remove(int index);     // removes and item from the appropriate index location
    virtual void print();               // prints item of the array comma separated.
    virtual T get(int index);           // gets item at a particular index.
    virtual T sum();                    // gets the sum of the array
    virtual int size();                 // gets the size of the array

    friend void operator +(Items obj1, Items obj2)
    {

        // new array to hold the union
        int tempArraySize = 0;
        T* tempArray;
        int j = 0;

        // sets the new array's size to the proper amount
        tempArraySize = obj1.size() + obj2.size();
        tempArray = new T[tempArraySize];

        // copies first array to union array
        for (int i = 0; i < obj1.size(); i++)
        {
            tempArray[i] = obj1.get(i);
        }

        // copies second array to union array
        for (int i = obj1.size(); i < tempArraySize; i++)
        {
            tempArray[i] = obj2.get(j);
            j++;
        }

        // outputs the new union array
        for (int i = 0; i < tempArraySize; i++)
        {
            cout << tempArray[i] << " ";
        }
    };

    friend void operator -(Items obj1, Items obj2)
    {
        //counters
        int i = 0;      
        int j = 0;

        while (i < obj1.size() && j < obj2.size())
        {
            if (obj1.get(i) == obj2.get(j))         // if a match is found
            {
                cout << obj1.get(i) << " ";         // prints intersections
                i++;
                j++;
            }
            else if (obj1.get(i) > obj2.get(j))
                j++;                                // i stays the same, j increments
            else
                i++;                                // j stays the same, i increments
        }

    };

    //generates relative complement by searching
    friend void operator /(Items obj1, Items obj2)
    {
        for (int i = 0; i < obj1.size(); i++)       // steps through first array
        {
            bool unique = true;
            for (int j = 0; j < obj2.size(); j++)   // steps through second array
            {
                if (obj2.get(j) == obj1.get(i))
                {
                    unique = false;                 // if not unique break loop
                    break;
                }
            }

            if (unique)
            {
                cout << obj1.get(i);                // if a unique is found, print it
            }
        }
    }

    // calculates cartesian product
    friend void operator *(Items obj1, Items obj2)
    {
        // generates the cartesian product by stepping through each array
        for (int i = 0; i < obj1.size(); i++)
        {
            for (int j = 0; j < obj2.size(); j++)
            {
                cout << "(" << obj1.get(i) << "," << obj2.get(j) << ")" << endl; // outputs the product with proper formatting
            }
        }
    };

    // Prints the two collections
    friend void operator <<(Items obj1, Items obj2)
    {
        // prints first file
        cout << "The first collection is: ";
        for (int i = 0; i < obj1.size(); i++)
        {
            cout << obj1.get(i) << " ";
        }

        // prints second file
        cout << endl << "The second collection is: ";    
        for (int j = 0; j < obj2.size(); j++)
        {
            cout << obj2.get(j) << " ";
        }
    };
};

#endif // ITEMS_H_INCLUDED