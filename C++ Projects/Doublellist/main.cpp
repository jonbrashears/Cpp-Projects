/******************************************************************************************************
* Name: Jonathan Brashears
*
* Student ID: w835032
*
* Description : This program generates 20-100 numbers based on user input.  These values are
*				saved to a file.  The file is then opened and 4 different linked lists are
*				created.  This list display the values in the order they were generateed,
*				the reverse order they were generated, descending order, and ascending order.
*				Afterwards, theses lists are deleted
*
* Date: 3/13/2017
********************************************************************************************************/




#include <iostream>
#include <ctime>
#include <fstream>
#include <stdio.h>
#include <stdlib.h>
#include <limits>
using namespace std;

//linked list
struct node
{
	int element;
	struct node *next;
	struct node *previous;
};

//prototypes
int getSize(int size);
int writeFile(int size);
int createForwardList(int size);
int insertForwardNode(int readNumber, node *head);
int checkOdd(node *head);
void deleteList(node *head);
void printList(node *head);

int main()
{
	int size = 0;	//how many numbers to be generated

	size = getSize(size);		//gets the size from user
	writeFile(size);			//writes the numbers generated to file
	createForwardList(size);	//Creates list as generated
	system("Pause");
	return 0;
}

//Asks user how many numbers to generate
int getSize(int size)
{
	//goes through loop until user inputs a valid number
	while (size < 20 || size > 100)
	{
		cout << endl;
		cout << "How many ints do you want to generate (20-100)?" << endl;	//asks user to input size
		cin >> size;		//user inputs size

		//checks if input was valid
		if (cin.fail() || size < 20 || size > 100)
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			cout << endl << "Invalid option, try again";
		}
		cout << endl << endl;
	}
	return(size);	//returns size
}

int writeFile(int size)
{
	int number = 0;		//holds most recently generated number
	ofstream WriteText;	//writing files
	WriteText.open("Number.txt");	//creates and opens file for storing random numbers

	//Error checking for file writing
	if (!WriteText)
	{
		cout << "Could not create/open text file for writing." << endl;

		return(1);
	}

	srand(time(NULL));		//random generator

	cout << "Start writing data to files" << endl << endl;

	for (int i = 0; i < size; i++)
	{
		number = rand() % 100;			//generates random number

		cout << number << endl;			//outsputs number

		WriteText << number << endl;	//writes number to file
	}
	cout << "Data successfully written" << endl << endl;
	WriteText.close();		//closes file
	return 0;
}

int createForwardList(int size)
{
	struct node *head;		//head node
	int maxNodes;			//max number of nudes
	int readNumber;			//current number being read

	ifstream ReadText;		//reading file in

	ReadText.open("Number.txt");	//opens file for reading

	//checks if file is open
	if (!ReadText)
	{
		cout << "Could not open text file for reading" << endl << endl;
		return(1);
	}

	//creates head node and throws error if unable to create
	if ((head = new(node)) == NULL)
	{
		cout << endl << "Fatal error, could not create head node." << endl << endl;
		return(1);
	}
	//points head to null
	else
	{
		head->next = NULL;
		head->previous = NULL;
		maxNodes = size;
	}

	//loop to go through file
	for (int i = 0; i < size; i++)
	{
		ReadText >> readNumber;	//sets read number value from file

		//inserts new node and checks to make sure it was created
		if (insertForwardNode(readNumber, head) == 1)
		{
			cout << "Could not create node." << endl;
			return(1);
		}
	}

	ReadText.close();	//closes file
	cout << endl << "This is the information as read: " << endl;
	//checkOdd(head);
	printList(head);	//calls print function
	deleteList(head);	//calls function to delete list
	return 0;
}


//function for inserting nodes in order numbers are read
int insertForwardNode(int readNumber, node *head)
{
	struct node *current = head,	//sets current to beginning of list
		*newNode;			//new node
	//goes through list
	while (current->next != NULL)
	{
		current = current->next;
	}
	//checks if list is full
	if ((newNode = new(node)) == NULL)
	{
		cout << "Out of space!";
		return(1);
	}
	newNode->element = readNumber;			//sets value in the new node
	newNode->next = NULL;
	newNode->previous = current;
	current->next = newNode;

	return(0);
}

/*int checkOdd(node *head)
{
	struct node *current = head,
				*tmp;

	while (current->next != NULL)
	{
		current = current->next;
		tmp = current;

		if ((current->element % 2) == 0)
		{

			/*if (current->previous == NULL)
			{

				head = head->next;
				head->previous = NULL;
				delete(tmp);
			}

			if (current->next == NULL)
			{

				tmp->previous->next = NULL;
				delete(tmp);
			}



				tmp->previous->next = tmp->next;
				tmp->next->previous = tmp->previous;
				delete(tmp);


		}
	}

	return 0;
}*/

//function to delete list
void deleteList(node *head)
{
	struct node *tmp;	//temporary node
	//continues until head is NULL(end of list)
	while (head != NULL)
	{
		tmp = head->next;	//sets temp equal to head next
		delete(head);		//deletes head
		head = tmp;			//sets head = tmp
	}
}

//print function
void printList(node *head)
{
	struct node *tmp;	//holds node to be printed
	tmp = head->next;	//holds next value
	int counter = 1;

	while (tmp != NULL)	//prints until NULL
	{
		cout << tmp->element << "\t";	//outputs element of node

		//loop to format printing
		if (counter % 5 == 0)
		{
			cout << endl;
			counter = 0;
		}
		tmp = tmp->next;		//moves to next item in list
		counter = counter + 1;	//increments counter
	}

}
