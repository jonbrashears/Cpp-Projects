//Jonathan Brashears
//CS 102
//Homework 1
//9-6-16
#include <iostream>
#include <fstream>

using namespace std;

int main()
{
        ifstream infile;
        ofstream outfile;
        infile.open("reviewdata.txt");  //opens reviewdata.txt
        outfile.open("homeworkoutput.txt"); //opens file for output

        int sum = 0; //holds sum
        int val = 0; //holds each line
        int count = 0; //counts numbers in file

        while(infile.good())
        {
            infile >> val;  //writes line from file to value
            sum = sum + val; //calculates the sum
            count++; //counts the numbers in file
        }

        if((sum%2)==0) //loop for even or odd
        {
            cout << "Jonathan" << endl; //first name if even
            outfile << "Jonathan" <<endl; //first name to file
        }

        else
        {
            cout  << "Brashears" << endl; //last name if odd
            outfile << "Brashears" <<endl; //last name to file
        }
        cout << "The sum of the numbers is " << sum << "." << endl;  //outputs the sum
        cout << "There are " << count << " lines in the file." <<endl; //outputs the count

        infile.close(); //closes reviewdata.txt


        outfile << sum << endl; //writes sum to file
        outfile << count << endl; //writes count to file
        outfile.close(); //closes homeworkoutput.txt
        cin.get();
        return 0;
}


