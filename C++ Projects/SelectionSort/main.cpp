/*
Jonathan Brashears
Homework 1
9/13/17
CS 102
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


int counter = 0;  //Counts the number of lines in the file
int val[30] = {0}; //Array to hold up to 30 numbers from the file

string fileName;

void fileRead()
{
    ifstream infile;

        cout << "Files test1.txt and test2.txt are available." << endl << "Please input which file you would like to read. " << endl;  //asks user to input filename
        cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    while(infile.good()) //reads file and assigns to array
    {
        infile>>val[counter];
        counter++;

    }
    infile.close();
}

void selectionSort()
{
    int positionMin;    //Holds smallest possible position
    int temp;           //used for swapping

    for(int i=0; i < counter-1; i++)        //Selection Sort
    {
        positionMin = i;                    //position of the smallest element so far

        for(int j=i+1; j < counter; j++)    //Looks for smallest remaining element
            if(val[j] < val[positionMin])   //if current number is smallest found so far
            {
                positionMin = j;            //Smallest for this iteration
            }

        if (positionMin!=i) //Swaps
        {
            temp = val[i];
            val[i] = val[positionMin];
            val[positionMin] = temp;
        }
    }
}

void findMean()
{
    double mean = 0.0;  //holds the mean
    int sum = 0;        //holds the sum

    for(int i=0; i <counter; i++) //Calculates the sum
    {
        sum += val[i];
    }

    mean = sum/counter; //finds the average
    cout << endl << "The mean of the numbers is: " << mean << endl; //displays the mean
}
void findMedian()
{

    int middle = 0;         //Variable for checking the median

    if (counter%2 == 0)     //for even sets
    {
        middle = counter/2;
        cout << "The median of the numbers is: " << (val[middle] + val[middle-1])/2 <<endl;
    }
    else if(counter%2 == 1)//for odd sets
    {
        middle = (counter+1)/2;
        cout << "The median of the numbers is: " << val[middle-1] << endl;
    }
}

void findMode()
{

    int currentMode = 1;            //Holds the current highest number of repetitions
    int repeats = 1;                //Number of repeats of current value
    int currentNumber = val[0];     //starts the loop at the 0 value
    int mode = currentNumber;

    cout << val[0] << " is unique." << endl; //First number is always unique

    for(int i = 1; i < counter; i++)  //Goes through array
    {

        if(val[i] == currentNumber) //Counts repeats of the current number
        {
            repeats++;
        }
        else //If the number is different
        {
            cout << val[i] << " is unique." << endl; //Displays each unique number after the first value

            if(repeats > currentMode) //if the number of repetitions is higher than the previous recorded repetitions
            {
                currentMode = repeats;  //updates the highest repetitions
                mode = currentNumber;   //Sets mode to the currentNumber
            }
            repeats = 1;  //Resets for next value
            currentNumber = val[i];
        }
    }
    cout <<"The mode of the numbers is: " << mode << endl;  //Displays the mode

}
int main()  //Main function
{
    fileRead ();        //Calls to read the file
    selectionSort ();   //Calls to sort the file
    findMean ();        //Calls to find the mean
    findMedian ();      //Calls to find the median
    findMode ();        //Calls to find the mode and display unique numbers
    cin.get();
    cin.get();
    return 0;
}

