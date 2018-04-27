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

using namespace std;

//linked list 
struct node
{
	int element;
	struct node *next;
};

//prototypes
int getSize(int size);
int writeFile(int size);
int createForwardList(int size);
int createReverseList(int size);
int createHigherList(int size);
int createLowerList(int size);
int insertForwardNode(int readNumber, node *head);
int insertReverseNode(int readNumber, node *head);
int insertHigherNode(int readNumber, node *head);
int insertLowerNode(int readNumber, node *head);
void deleteList(node *head);
void printList(node *head);

int main()
{
	int size = 0;	//how many numbers to be generated

	size = getSize(size);		//gets the size from user
	writeFile(size);			//writes the numbers generated to file
	createForwardList(size);	//Creates list as generated
	createReverseList(size);	//Creates list in reverse order generated
	createHigherList(size);		//List from highest to lowest
	createLowerList(size);		//List from lowest to highest
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
		cin >>size;		//user inputs size

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
	int number=0;		//holds most recently generated number
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
	printList(head);	//calls print function
	deleteList(head);	//calls function to delete list
	return 0;
}

//creates list in reverse order
int createReverseList(int size)
{
	struct node *head;	//head of linked list
	int maxNodes;		//maximum number of nodes
	int readNumber;		//current number being read from file

	ifstream ReadText;	//reading from file

	ReadText.open("Number.txt");	//opens file for reading

	//checks if file was opened
	if (!ReadText)
	{
		cout << "Could not open text file for reading" << endl << endl;
		return(1);
	}

	//creates head node.  Throws error if node can't be created
	if ((head = new(node)) == NULL)
	{
		cout << endl << "Fatal error, could not create head node." << endl << endl;
		return(1);
	}

	//points head to NULL
	else
	{
		head->next = NULL;
		maxNodes = size;
	}

	//generates linked list
	for (int i = 0; i < size; i++)
	{
		ReadText >> readNumber;		//gets number from file

		//passes number to node creation function
		if (insertReverseNode(readNumber, head) == 1)
		{
			cout << "Could not create node." << endl;
			return(1);
		}
	}

	ReadText.close();	//closes file
	cout << endl << "This is the information as read in reverse: " << endl;
	printList(head);	//print function
	deleteList(head);	//delete function
	return 0;
}

//Creates list ordered from highest to lowest
int createHigherList(int size)
{
	struct node *head;		//head of linked list
	int maxNodes;			//maximum number of nodes
	int readNumber;			//current number being read from file

	ifstream ReadText;		//reading from file

	ReadText.open("Number.txt");	//opens file for reading

	//checks if file was opened, throws error if not
	if (!ReadText)
	{
		cout << "Could not open text file for reading" << endl << endl;
		return(1);
	}

	//creates head node.  Throws error if can't create it
	if ((head = new(node)) == NULL)
	{
		cout << endl << "Fatal error, could not create head node." << endl << endl;
		return(1);
	}

	//points head to NULL
	else
	{
		head->next = NULL;
		maxNodes = size;
	}

	//loop for generating linked list
	for (int i = 0; i < size; i++)
	{
		ReadText >> readNumber;		//gets number from file

		//passes number to node creating function, throws error if node not created
		if (insertHigherNode(readNumber, head) == 1)
		{
			cout << "Could not create node." << endl;
			return(1);
		}
	}

	ReadText.close();	//closes file
	cout << endl << "This is the information as from highest to lowest: " << endl;
	printList(head);	//print function
	deleteList(head);	//delete function
	return 0;
}

//Creates list ordered from lowest to highest
int createLowerList(int size)
{
	struct node *head;	//head node of list
	int maxNodes;		//maximum number of nodes
	int readNumber;		//number from file

	ifstream ReadText;	//read from file

	ReadText.open("Number.txt");	//opens file for reading

	//checks if file was opened, throws error if not
	if (!ReadText)
	{
		cout << "Could not open text file for reading" << endl << endl;
		return(1);
	}

	//creates head node.  Throws error if could not be created
	if ((head = new(node)) == NULL)
	{
		cout << endl << "Fatal error, could not create head node." << endl << endl;
		return(1);
	}

	//points head to NULL
	else
	{
		head->next = NULL;
		maxNodes = size;
	}

	//generates linked list
	for (int i = 0; i < size; i++)
	{
		ReadText >> readNumber;	//gets number from file

		//passes number to node creator, checks if node was created
		if (insertLowerNode(readNumber, head) == 1)
		{
			cout << "Could not create node." << endl;
			return(1);
		}
	}

	ReadText.close();	//closes file
	cout << endl << "This is the information as from lowest to highest: " << endl;
	printList(head);	//print function
	deleteList(head);	//delete function
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
	newNode->element = readNumber;		//sets value in the new node
	newNode->next = current->next;		//sets the new nodes pointer to current pointer
	current->next = newNode;			//updates current to point to new node
	return(0);
}

//function for inserting nodes in opposite order they are read
int insertReverseNode(int readNumber, node *head)
{
	struct node *newNode;	//new node
	//checks if list is full
	if ((newNode = new(node)) == NULL)
	{
		cout << "Out of space!";
		return(1);
	}

	newNode->element = readNumber;		//set value for new node
	newNode->next = head->next;			//updates new node's pointer to heads pointer
	head->next = newNode;				//updates head to point to new node
	return(0);
}

//function for inserting nodes in descending order
int insertHigherNode(int readNumber, node *head)
{
	struct node *current = head,	//sets current to beginning of list
				*newNode;			//new node

	//progresses to correct insertion spot
	while ((current->next != NULL)&&(current->next->element > readNumber))
	{
		current = current->next;
	}
	//checks if list is full
	if ((newNode = new(node)) == NULL)
	{
		cout << "Out of space!";
		return(1);
	}

	newNode->element = readNumber;		//assings value to new node
	newNode->next = current->next;		//points new node to next node
	current->next = newNode;			//updates current to point to new node
	return(0);
}

//function for inserting nodes in ascending order
int insertLowerNode(int readNumber, node *head)
{
	struct node *current = head,	//sets current to beginning of list
				*newNode;			//new node

	//goes through list until correct location is found
	while ((current->next != NULL) && (current->next->element < readNumber))
	{
		current = current->next;
	}
	
	//check to see if list is full
	if ((newNode = new(node)) == NULL)
	{
		cout << "Out of space!";
		return(1);
	}
	newNode->element = readNumber;		//sets value of new node
	newNode->next = current->next;		//updates new node's point to current pointer
	current->next = newNode;			//updates current to point to new node
	return(0);
}

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
		tmp = tmp->next;	//moves to next item in list
		counter = counter + 1;	//increments counter
	}
}