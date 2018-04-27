#include <iostream>
#include "items.h"
#include "collection.h"

using namespace std;

Items::Items()
{
    //initializes the values
    myArray = new int[1];
    myArray[0] = 0;
    arraySize = 1;
    nextIndex = 0;
}

//adds a value to the array
void Items::add(int value)
{
    int *newArray; //new array of pointers
    if (nextIndex == arraySize)
    {
        arraySize = arraySize + 1; //updates array size if there is another value
        newArray = new int[arraySize]; //creates a new array with the updated size
        for (int i = 0; i < nextIndex; i++)
            newArray[i] = myArray[i]; //copies the values of the old array to the newly created one
        for (int j = nextIndex; j < arraySize; j++)
            newArray[j] = 0;  //newArray holds a zero in the new spot to update the size of the original array
        delete [] myArray; //deletes original array
        myArray = newArray; //copies values of newArray to the original array
    }
    myArray[nextIndex++] = value;
    selectionSort();
}

//removes a value from the array
void Items::remove(int index)
{
    //starts at the user given element and moves each element back one spot in the array
    for(int i = index; i < arraySize; i++)
    {
        myArray[i] = myArray[i+1];
    }
    arraySize = arraySize-1; //updates the array size
    int *newArray; //new array to hold values while updating size
    newArray = new int[arraySize];
    //Sets the new array to the values of the original array
    for (int i = 0; i < arraySize; i++)
    {
        newArray[i] = myArray[i];
    }
    delete [] myArray;  //deletes original array
    myArray = newArray; //original array of updated size copies values from new array
}


//prints values of array separated by commas
void Items::print()
{
    cout << endl;
    for (int i = 0; i < (arraySize-1); i++)
    {
        cout << myArray[i] << ", ";
    }
    cout << myArray[arraySize-1];  //doesn't print comma for last value
}

//returns value at user given index
int Items::get(int index)
{
    return myArray[index];
}

//sums the values of the array
int Items::sum()
{
    int sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum+=myArray[i];
    }
    return sum;
}

//returns the size of the array
int Items::size()
{
    return arraySize;
}

void Items::selectionSort()
{
    int minIndex;
    int *temp;
    for (int i = 0; i < arraySize - 1; i++) {
            minIndex = i;
            for (int j = i + 1; j < arraySize; j++)
                  if (myArray[j] < myArray[minIndex])
                        minIndex = j;
            if (minIndex != i) {
                  *temp = myArray[i];
                  myArray[i] = myArray[minIndex];
                  myArray[minIndex] = *temp;
            }
      }
}


//calculates the untion

void operator +(Items obj1, Items obj2)
{
    //new array to hold the union
    int tempArraySize = 0;
    int *tempArray;
    int j = 0;

    //sets the new array's size to the proper amount
    tempArraySize = obj1.size() + obj2.size();
    tempArray = new int[tempArraySize];
    //copies first array to union array
    for(int i = 0; i<obj1.size(); i++)
    {
        tempArray[i]=obj1.get(i);
    }
    //copies second array to union array
    for(int i = obj1.size(); i < tempArraySize; i++)
    {
            tempArray[i]=obj2.get(j);
            j++;
    }
    //outputs the new union array
    for(int i = 0; i < tempArraySize; i++)
    {
        cout << tempArray[i] << " ";
    }
}
//Calculates the intersect of the two collections
void operator -(Items obj1, Items obj2)
{
    int i = 0; //counters
    int j = 0;

    while(i<obj1.size()&&j<obj2.size())
    {
        if(obj1.get(i) == obj2.get(j)) //if a match is found
            {
                cout << obj1.get(i) << " "; //prints intersections
                i++;
                j++;
            }
        else if(obj1.get(i) > obj2.get(j))
            j++; //i stays the same, j increments
        else
            i++; //j stays the same, i increments
    }

}

//generates relative complement by searching
void operator /(Items obj1, Items obj2)
{
    for(int i = 0; i < obj1.size(); i++) //steps through first array
    {
        bool unique = true;
        for (int j = 0; j < obj2.size(); j++)//steps through second array
        {
            if(obj2.get(j) == obj1.get(i))
            {
                unique = false; //if not unique break loop
                break;
            }
        }

        if (unique)
        {
            cout << obj1.get(i);//if a unique is found, print it
        }
    }
}

//calculates cartesian product
void operator *(Items obj1, Items obj2)
{
    //generates the cartesian product by stepping through each array
    for(int i=0; i < obj1.size(); i++)
    {
        for(int j = 0; j < obj2.size(); j++)
        {
            cout << "(" << obj1.get(i) << "," << obj2.get(j) << ")" << endl; //outputs the product with proper formatting
        }
    }
}

//Prints the two collections
void operator <<(Items obj1, Items obj2)
{
    cout << "The first collection is: ";
    //prints first file
    for (int i = 0; i < obj1.size();i++)
    {
        cout << obj1.get(i) << " ";
    }

    cout << endl << "The second collection is: ";
    //prints second file
    for (int j = 0; j < obj2.size();j++)
    {
        cout << obj2.get(j) << " ";
    }
}
