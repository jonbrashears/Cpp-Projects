#include "items.h"

template <class T>
Items<T>::Items()
{
    //initializes the values
    myArray = new T[1];
    myArray[0] = 0;
    arraySize = 1;
    nextIndex = 0;
}

//adds a value to the array
template <class T>
void Items<T>::add(T value)
{
    T* newArray;                                        //new array of pointers
    if (nextIndex == arraySize)
    {
        arraySize = arraySize + 1;                      // updates array size if there is another value
        newArray = new T[arraySize];                    // creates a new array with the updated size
        for (int i = 0; i < nextIndex; i++)
            newArray[i] = myArray[i];                   // copies the values of the old array to the newly created one
        for (int j = nextIndex; j < arraySize; j++)
            newArray[j] = 0;                            // newArray holds a zero in the new spot to update the size of the original array
        delete[] myArray;                               // deletes original array
        myArray = newArray;                             // copies values of newArray to the original array
    }
    myArray[nextIndex] = value;
    cout << value << endl << myArray[nextIndex] << endl;

    for (int i = 0; i < arraySize; i++)
    {
        cout << "Array is " << myArray[i] << endl;
    }

    nextIndex++;
    selectionSort();
}

//removes a value from the array
template <class T>
void Items<T>::remove(int index)
{
    //starts at the user given element and moves each element back one spot in the array
    for (int i = index; i < arraySize; i++)
    {
        myArray[i] = myArray[i + 1];
    }
    arraySize = arraySize - 1;              //updates the array size
    T* newArray;                            // new array to hold values while updating size
    newArray = new T[arraySize];
    
    for (int i = 0; i < arraySize; i++)     //Sets the new array to the values of the original array
    {
        newArray[i] = myArray[i];
    }
    delete[] myArray;                       //deletes original array
    myArray = newArray;                     //original array of updated size copies values from new array
}


//prints values of array separated by commas
template <class T>
void Items<T>::print()
{
    cout << endl;
    for (int i = 0; i < (arraySize - 1); i++)
    {
        cout << myArray[i] << ", ";
    }
    cout << myArray[arraySize - 1];  //doesn't print comma for last value
}

//returns value at user given index
template <class T>
T Items<T>::get(int index)
{
    return myArray[index];
}

//sums the values of the array
template <class T>
T Items<T>::sum()
{
    T sum = 0;
    for (int i = 0; i < arraySize; i++)
    {
        sum += myArray[i];
    }
    return sum;
}

//returns the size of the array
template <class T>
int Items<T>::size()
{
    return arraySize;
}

//sorts the arrays to more easily determine repeats
template <class T>
void Items<T>::selectionSort()
{
    int minIndex;
    T* temp = nullptr;
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



template class Items<int>;
template class Items<float>;
template class Items<double>;