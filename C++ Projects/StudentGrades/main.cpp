//Jonathan Brashears
//Homework 2
//9/18/16
//CS 102
//Read student name and grade from file.  Determines highest, lowest, and average grades

#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

struct studentInfo {    //struct for student information

string name;            //holds student's name
int grade;              //holds student's grade

};

studentInfo student[50];    //array of structs for student information
int count;                  //counter
string fileName;            //Holds user input filename

void readFile()
{
    ifstream infile;

    cout << "Files Grades1.txt and Grades2.txt are available." << endl << "Please input which file you would like to read. " << endl;  //asks user to input filename
    cin >> fileName; //Gets filename from user

    infile.open(fileName.c_str()); //Opens the file the user input

    while(infile.good()) //reads file and assigns to array and struct
    {
        infile >> student[count].name >> student[count].grade;
        count++;

    }
    infile.close();

}

void selectionSort()
{
    int positionMin;            //Holds smallest possible position
    studentInfo temp;           //used for swapping

    for(int i=0; i < count-1; i++)          //Selection Sort
    {
        positionMin = i;                    //position of the smallest element so far

        for(int j=i+1; j < count; j++)      //Looks for smallest remaining element
            if(student[j].grade < student[positionMin].grade)   //if current number is smallest found so far
            {
                positionMin = j;            //Smallest for this iteration
            }

        if (positionMin!=i) //Swaps
        {
            temp = student[i];
            student[i] = student[positionMin];
            student[positionMin] = temp;
        }
    }
}



void printMinMax()
{
    cout << student[0].name << " had the lowest grade with a " << student[0].grade << endl; //Displays lowest grade
    cout << student[count-1].name << " had the highest grade with a " << student[count-1].grade << endl; //Displays highest grade
}

void findAverage() //finds average
{
    double sum = 0;             //holds sum
    double avgCount = count;    //double count
    double average = 0.0;       //holds average
    for(int i = 0; i < count; i++) //loop to add all the grades
    {
        sum += student[i].grade;
    }
    average = sum/avgCount;    //calculates average
    cout  << "The class average is " << fixed << setprecision(2) << average << endl; //prints average
}

/*void printFile() //Test function to print info held in array
{
    for(int i = 0; i < count; i++)  //Loop to print array
    {
        cout << student[i].name << " " << student[i].grade << endl;
    }
}*/

int main()
{
    //calls functions
    readFile ();
    selectionSort();
    printMinMax ();
    findAverage ();
    //printFile ();  //Test function to make sure file was being read properly
    cin.get();
    cin.get();
    return 0;
}
