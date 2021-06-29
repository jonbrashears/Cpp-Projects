////////////////////////////////////////////////////////////////////////////////////////////////
// Jonathan Brashears
// 4/2/2017
// 
// This program will ask the user to input a file name.  The program will then read the file
// and seperate the values read into a stack or queue depending on their values.  Any
// non-integer values will be discarded.  The program will then sum these items and store
// them in serparate files.
////////////////////////////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <string>
#include <fstream>
#include <queue>
#include <stack>

using namespace std;

//This function will ask the user for a filename to open and will then return that name
string getFileName();

//This function opens the filename returned in the previous function.  If the file could be opened it calls the sortFile function. If not, the program terminates.
int openFile(string, stack<int> *myStack, queue<int> *myQueue);

//This functions reads in the information from the user's file.  The information's value is checked as it is read to determine if where to place the information
//Values from 0-49 (inclusive) vall the pushToStack function, values from 50 to 99 (inclusive) vall the pushToQueue function.  All other values are ignored.
void sortFile(ifstream &ReadFile, stack<int> *myStack, queue<int> *myQueue);

//Values from the read file are pushed to myStack.  Successfully added values are displayed in the console
void pushToStack(int, stack<int>*);

//Values from the read file are pushed to myQueue.  Successfully added values are displayed in the console
void pushToQueue(int, queue<int>*);

//Creates a file named Stack.txt.  Throws error if file could not be created.  The function then uses the top command to save the value to the file.  Afterwards the value is popped
//from the stack.  A while loop is used to ensure this process continues until the stack is empty.
int writeStack(stack<int>*);

//Creates a file named Queue.txt.  Throws error if file could not be created.  The function then uses the front command to save the value to the file.  Afterwards the value is popped
//from the queue.  A while loop is used to ensure this process continues until the queue is empty.
int writeQueue(queue<int>*);


int main()
{
	string fileName;	//variable to hold the returned file name from the user.
	stack<int> myStack;	//stack to hold all values between 0-49
	queue<int> myQueue;	//queue to hold all values between 50-99

	fileName = getFileName();	//Sets fileName equal to the value the user enters in the getFileName function

	//Passed the fileName, myStack, and myQueue.  Opens the file with the name the user entered.  If the file could not be opened, an error is thrown
	//If the file is successfully opened, the sortFile function is called.
	openFile(fileName, &myStack, &myQueue);

	//Function for writing the information stored in myStack to a file named Stack.txt.  myStack is deleted during this process.
	//If the file could not be created, an error is thrown.  
	
	writeStack(&myStack);

	//function for writing the information stroed in myQueue to a file named Queue.txt.  myQueue is deleted during this process.
	//If the file could not be created, an error is thrown.
	writeQueue(&myQueue);

	//Waits for user input, so user can have time to read results of program
	system("PAUSE");
	return 0;
}

//Asks user to input a filename to be opened.  The user's input is then returned to be used by other functions
string getFileName()
{
	string myFile;	//holds file name from user
	
	//Prompts user to input a filename to open
	cout << "This program will open a file, read its data,\nthen create organized files based on the data.  \nUseless data will be discarded" << endl << "\nWhich file would you like to open?" << endl;
	cin >> myFile;	//file to be opened
	return myFile;	//returns filename to be opened
}

//Function uses the fileName provided by the user to open a file for reading.  Error is thrown if file could not be opened.
//If the file was opened, Sort file is called and passed the opened file, myStack, and myQueue.
int openFile(string fileName, stack<int> *myStack, queue<int> *myQueue)
{
	ifstream ReadFile;

	//Opens the designated file
	ReadFile.open(fileName.c_str());

	cout << "\nOpening " << fileName << "...\n";  //Lets the user know that the program is attempting to open their file.

	//checks if file was succesfully opened
	if (!ReadFile)
	{
		cout << "Could not open file for reading." << endl; //Throws error to console

		return(1);
	}

	//Calls the sortFile function.  Passes the opened file, myStack, and myQueue.  This function sends information from 0-49 to the stack and information from 50-99 to the queue
	//irrelevant information is ignored.
	sortFile(ReadFile, myStack, myQueue);

	//Closes the file when we are finished with its information
	ReadFile.close();

	return 0;
}

//Function is passed an open file, myStack, and myQueue.  Stores values from file in readNumber.  If the values are from 0-49 the user is notified and the pushToStack function is called.
//If the values are from 50-99 the user is notified and the pushToQueue function is called.  Irrelevant information is discarded.
void sortFile(ifstream &ReadFile, stack<int> *myStack, queue<int> *myQueue)
{
	//This variable is used to hold the values we read from the file.
	int readNumber = -1;

	cout << "\nProcessing file... \n";	//Alerts the user that the files is being processed

	//While loop continuously runs.  Conditions inside the loop break it at the end of the file.
	while (1)
	{
		//The user designated file is read line by line into the readNumber variable
		ReadFile >> readNumber;

		//Checks to see if it is the end of the file AFTER the line is saved to readNumber.  This prevents the loop from printing the last line twice.
		if (ReadFile.eof())
			break; //breaks out of the loop

		//If-else loop.  Checks the value of readNumber and calls pushToStack or pushToQueue accordingly.
		//Values from 0-49 are sent to the stack.
		if (readNumber >= 0 && readNumber <= 49)
		{
			//Notifies user that a value is being sent to the stack
			cout << "Push to stack: ";

			//Calls the pushToStack function.  The function is passed readNumber and myStack.
			pushToStack(readNumber, myStack);
			readNumber = -1;	//resets readNumber so it will be discarded if a non-int is read.
		}
		//Values from 50-99 are sent to the queue
		else if (readNumber >= 50 && readNumber <= 99)
		{
			//Notifies the user that a value is being sent to the queue
			cout << "Push to queue: ";

			//Calls the pushToQueue function.  The function is passed readNumber and myQueue
			pushToQueue(readNumber, myQueue);	
			readNumber = -1;	//resets readNumber so it will be discarded if a non-int is read.
		}
		//If the informnation is negative, above 99, or not an int, it is ignored
		else
		{
			ReadFile.clear(); 
			ReadFile.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

			cout << "Irrelevant information discarded.(Not in our needed range) " << endl;  //Lets the user know that irrelevant information was found and ignored
		}
	}
}

//This function is passed the certain values read from the file and myStack.  readNumber is pushed to myStack and the user is notified by the top() command if the value was successfully added.
void pushToStack(int readNumber, stack<int> *myStack)
{
	myStack->push(readNumber);			//adds readNumber to the stack
	cout << myStack->top() << endl;		//displays the added value
}

//This function is passed the certain values read from the file and myQueue.  readNumber is pushed to myQueue and the user is notified by the back() command if the value was successfully added.
void pushToQueue(int readNumber, queue<int> *myQueue)
{
	myQueue->push(readNumber);			//adds readNumber to the queue
	cout << myQueue->back() << endl;	//displays the added value	
}

//This function is used to create a file named Stack.txt and to write myStack to the file line by line.  It also sums the values stored in myStack and writes the sum to the file. 
//It is passed myStack.  If the file could not be created or opened, an error is thrown.  At the end the file is closed.
int writeStack(stack<int> *myStack)
{
	ofstream writeStack;

	int sum = 0;					//This variable will hold the sum of the values held in myStack
	writeStack.open("Stack.txt");	//attempts to create the file Stack.txt

	//checks to make sure the file was created/opened
	if (!writeQueue)
	{
		//notifies user and throws error if the file could not be created/opened
		cout << "Could not create/open file for writing. " << endl << endl; 
		return(1);
	}

	cout << "\nWriting file: Stack.txt...";	//Alerts the user that the file is being written

	//while loop that iterates as long as the stack is not empty
	while (!myStack->empty()) //Checks if stack is empty
	{
		writeStack << myStack->top() << endl;	//Writes top value of the stack to Stack.txt
		sum += myStack->top();					//Adds the top value to the sum
		myStack->pop();							//pops the top value off of the stack.
	}

	writeStack << endl << sum;					//writes the sum to the file after all values are read from stack

	writeStack.close();							//closes the file when we are done

	cout << "\nFile successfully written!\n";	//Lets the user know that the file was created and written

	return 0;
}

//This function is used to create a file named Queue.txt and to write myQueue to the file line by line.  It also sums the values stored in myQueue and writes the sum to the file. 
//It is passed myQueue.  If the file could not be created or opened, an error is thrown.  At the end the file is closed.
int writeQueue(queue<int> *myQueue)
{
	ofstream writeQueue;

	int sum = 0;					//This variable will hold the sum of the values held in myQueue
	writeQueue.open("Queue.txt");	//attempts to create the file Queue.txt
	
	//checks to make sure the file was created/opened
	if (!writeQueue)
	{
		//notifies user and throws error if the file could not be created/opened
		cout << "Could not create/open file for writing. " << endl << endl;
		return(1);
	}

	cout << "\nWriting file: Queue.txt...";	//Alerts the user that the file is being writted

	//While loop that iterates as long as the queue is not empty
	while (!myQueue->empty())
	{
		writeQueue << myQueue->front() << endl;		//Writes the front value of the queue to Queue.txt
		sum += myQueue->front();					//Adds the front value of the queue to the sum
		myQueue->pop();								//pops the front value off of the queue
	}

	writeQueue << endl << sum;						//writes the sum of the file after all values are read from queue

	writeQueue.close();								//closes the file when we are done
		
	cout << "\nFile successfully written!\n";		//Lets the user know that the file was created and written

	return 0;
}
