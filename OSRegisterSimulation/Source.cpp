/************************************************************************************************************
*	Jonathan Brashears
*	10/5/2017
*	Operating Systems Project C
*
*	This program generates 4 arrays of 100 random numbers (0-99) and one 100 number priority array (1-3).
*	These values are inserted into a buffer (10 nodes) linked list, through a register at the head and tail, 
*	in ascending order, and by priority.  These values are then output using a register as they are deleted.
*	The number of clock cylces for input and output are counted and output at the end. This is done for
*	one input register and one output register, 4 input registers and 4 output registers, one input  
*	registers and four output registers, and four input registers and one output registers
*	
*
*************************************************************************************************************/

#include <iostream>
#include <ctime>
#include <stdio.h>
#include <stdlib.h>
using namespace std;


//linked list
struct node
{
	int element;
	int priority;
	struct node *next;
};

//prototypes
int randomNumber();										//generates random values
int randomPriority();									//generates priority values
int addFromHead(node *head1, int rIn);					//adds nodes at the head
int addFromTail(node *head2, int rIn);					//adds nodes at the tail
int addSort(node *head3, int rIn);						//sorts nodes as they're added to the buffer
int addPriority(node *head4, int rIn, int priority);	//sorts nodes by priority as they are added to the buffer
int processTail(node *head);							//processes the tail by return the tails value, then deleting it
int priorityProcessTail(node *head, int *pOut);			//processes the tail by returning the tail's value, saving the priority, then deleting it

//main function
int main()
{
	//FIFO list
	struct node *head1 = new(node);
	head1->next = NULL;

	//LIFO list
	struct node *head2 = new(node);
	head2->next = NULL;

	//Sorted list
	struct node *head3 = new(node);
	head3->next = NULL;

	//Priority list
	struct node *head4 = new(node);
	head4->next = NULL;

	//random number arrays
	int rArray1[100];
	int rArray2[100];
	int rArray3[100];
	int rArray4[100];

	//random priority array
	int priority[100];
	
	//pointer to hold the priority of node that is processed
	int *pOut = &priority[0];

	//registers
	//input
	int rIn1;
	int rIn2;
	int rIn3;
	int rIn4;

	//output
	int rOut1;
	int rOut2;
	int rOut3;
	int rOut4;

	//clock counters
	int clockIn1 = 0;
	int clockOut1 = 0;
	int clockIn2 = 0;
	int clockOut2 = 0;
	int clockIn3 = 0;
	int clockOut3 = 0;
	int clockIn4 = 0;
	int clockOut4 = 0;

	//labels the arrays
	cout << "Array 1\t" << "Array 2\t" << "Array 3\t" << "Array 4\t" << "Priority\t" << endl;

	//generates random values and populates arrays
	for (int i = 0; i < 100; i++)
	{
		rArray1[i] = randomNumber();
		rArray2[i] = randomNumber();
		rArray3[i] = randomNumber();
		rArray4[i] = randomNumber();
		priority[i] = randomPriority();

		//outputs array values
		cout << rArray1[i] << "\t" << rArray2[i] << "\t" << rArray3[i] << "\t" << rArray4[i] << "\t" << priority[i] << endl;
	}

	//Beginning of 1 Input register/1 ouput register run
	//loop to load first 10 values into buffer
	for (int i = 0; i < 10; i++)
	{
		rIn1 = rArray1[i];			//passes value to register
		addFromHead(head1, rIn1);	//sends value to the FIFO linked list
		clockIn1++;					//tracks input clock cycles

		rIn1 = rArray2[i];			//passes value to register
		addFromTail(head2, rIn1);	//sends value to the LIFO linked list
		clockIn1++;					//tracks input clock cycles

		rIn1 = rArray3[i];			//passes value to register
		addSort(head3, rIn1);		//sends value to the sorted linked list
		clockIn1++;					//tracks input clock cycles

		rIn1 = rArray4[i];						//passes value to register
		addPriority(head4, rIn1, priority[i]);	//sends value to the priority linked list
		clockIn1++;								//tracks input clock cycles
	}

	//labels 
	cout << endl << "One Input and 1 Output register" << endl << "FIFO\tLIFO\tSort\tPrioritized\tPriority"  << endl;

	//loop to send remaining values to buffer.  Buffer is deleted from tail and the values output to the console
	for (int i = 10; i < 100; i++)
	{
		rIn1 = rArray1[i];				//loads input register
		rOut1 = processTail(head1);		//loads output register
		clockOut1++;					//tracks output clock cycles
		addFromHead(head1, rIn1);		//Adds to FIFO list
		clockIn1++;						//tracks input clock cycles
		cout << rOut1 << "\t";			//outputs register value to console
		

		rIn1 = rArray2[i];				//loads input register
		rOut1 = processTail(head2);		//loads output register
		clockOut1++;					//tracks output clock cycles
		addFromTail(head2, rIn1);		//sends value to the LIFO linked list
		clockIn1++;						//tracks input clock cycles
		cout << rOut1 << "\t";			//outputs register value to console

		rIn1 = rArray3[i];				//loads input register
		rOut1 = processTail(head3);		//loads output register
		clockOut1++;					//tracks output clock cycles
		addSort(head3, rIn1);			//sends value to the sorted linked list
		clockIn1++;						//tracks input clock cycles
		cout << rOut1 << "\t";			//outputs register value to console

		rIn1 = rArray4[i];							//loads input register
		rOut1 = priorityProcessTail(head4, pOut);		//loads output register
		clockOut1++;									//tracks output clock cycles
		addPriority(head4, rIn1, priority[i]);			//sends value to the priority linked list
		clockIn1++;										//tracks input clock cycles
		cout << rOut1 << "\t\t" << *pOut << endl;		//outputs register value to console
	}

	//loop to output remaining values in linked lists and delete the lists
	while (head1->next != NULL)
	{
		rOut1 = processTail(head1);				//loads output register
		clockOut1++;							//tracks output clock cycles
		cout << rOut1 << "\t";					//outputs register value to console

		rOut1 = processTail(head2);				//loads output register
		clockOut1++;							//tracks output clock cycles
		cout << rOut1 << "\t";					//outputs register value to console

		rOut1 = processTail(head3);				//loads output register
		clockOut1++;							//tracks output clock cycles
		cout << rOut1 << "\t";					//outputs register value to console

		rOut1 = priorityProcessTail(head4, pOut);		//loads output register
		cout << rOut1 << "\t\t" << *pOut << endl;		//outputs register value to console
		clockOut1++;									//tracks output clock cycles
	}

	system("Pause");

	//Beginning of 4 inputs and 4 outputs run
	//loop to load first 10 values into buffer
	for (int i = 0; i < 10; i++)
	{
		rIn1 = rArray1[i];					//loads input register
		addFromHead(head1, rIn1);			//Adds to FIFO list

		rIn2 = rArray2[i];					//loads input register
		addFromTail(head2, rIn2);			//sends value to the LIFO linked list

		rIn3 = rArray3[i];					//loads input register
		addSort(head3, rIn3);				//sends value to the Sorted linked list

		rIn4 = rArray4[i];							//loads input register
		addPriority(head4, rIn4, priority[i]);		//sends value to the priority linked list

		clockIn2++;									//tracks input clock cycles
	}

	//labels
	cout << endl << "Four input and Four output registers" << endl << "FIFO\tLIFO\tSort\tPrioritized\tPriority"  << endl;

	//loop to send remaining values to buffer.  Buffer is deleted from tail and the values output to the console
	for (int i = 10; i < 100; i++)
	{
		rIn1 = rArray1[i];				//loads input register
		rOut1 = processTail(head1);		//loads output register
		addFromHead(head1, rIn1);		//Adds to FIFO list
		cout << rOut1 << "\t";			//outputs register value to console


		rIn2 = rArray2[i];				//loads input register
		rOut2 = processTail(head2);		//loads output register
		addFromTail(head2, rIn2);		//sends value to the LIFO linked list
		cout << rOut2 << "\t";			//outputs register value to console

		rIn3 = rArray3[i];				//loads input register
		rOut3 = processTail(head3);		//loads output register
		addSort(head3, rIn3);			//sends value to the sorted linked list
		cout << rOut3 << "\t";			//outputs register value to console

		rIn4 = rArray4[i];							//loads input register
		rOut4 = priorityProcessTail(head4, pOut);		//loads output register
		clockOut2++;									//tracks output clock cycles
		addPriority(head4, rIn4, priority[i]);			//sends value to the priority linked list
		clockIn2++;										//tracks input clock cycles
		cout << rOut4 << "\t\t" << *pOut << endl;		//outputs register value to console
	}

	//loop to output remaining values in linked lists and delete the lists
	while (head1->next != NULL)
	{
		rOut1 = processTail(head1);		//loads output register
		cout << rOut1 << "\t";			//outputs register value to console

		rOut2 = processTail(head2);		//loads output register
		cout << rOut2 << "\t";			//outputs register value to console

		rOut3 = processTail(head3);		//loads output register
		cout << rOut3 << "\t";			//outputs register value to console

		rOut4 = priorityProcessTail(head4, pOut);		//loads output register
		cout << rOut4 << "\t\t" << *pOut << endl;		//outputs register value to console
		clockOut2++;					//tracks output clock cycles
	}

	system("Pause");

	//Beginning of 1 input and 4 outputs run
	//loop to load first 10 values into buffer
	for (int i = 0; i < 10; i++)
	{
		rIn1 = rArray1[i];				//loads input register
		addFromHead(head1, rIn1);		//Adds to FIFO list
		clockIn3++;						//tracks input clock cycles

		rIn1 = rArray2[i];				//loads input register
		addFromTail(head2, rIn1);		//sends value to the LIFO linked list
		clockIn3++;						//tracks input clock cycles

		rIn1 = rArray3[i];				//loads input register
		addSort(head3, rIn1);			//sends value to the sorted linked list
		clockIn3++;						//tracks input clock cycles

		rIn1 = rArray4[i];							//loads input register
		addPriority(head4, rIn1, priority[i]);		//sends value to the priority linked list
		clockIn3++;									//tracks input clock cycles
	}

	//labels
	cout << endl << "One input and Four output registers" << endl << "FIFO\tLIFO\tSort\tPrioritized\tPriority"  << endl;

	//loop to send remaining values to buffer.  Buffer is deleted from tail and the values output to the console
	for (int i = 10; i < 100; i++)
	{
		rIn1 = rArray1[i];				//loads input register
		rOut1 = processTail(head1);		//loads output register
		addFromHead(head1, rIn1);		//Adds to FIFO list
		cout << rOut1 << "\t";			//outputs register value to console
		clockIn3++;						//tracks input clock cycles

		rIn1 = rArray2[i];				//loads input register
		rOut2 = processTail(head2);		//loads output register
		addFromTail(head2, rIn1);		//sends value to the LIFO linked list
		cout << rOut2 << "\t";			//outputs register value to console
		clockIn3++;						//tracks input clock cycles

		rIn1 = rArray3[i];				//loads input register
		rOut3 = processTail(head3);		//loads output register
		addSort(head3, rIn1);			//sends value to the sorted linked list
		cout << rOut3 << "\t";			//outputs register value to console
		clockIn3++;						//tracks input clock cycles

		rIn1 = rArray4[i];							//loads input register
		rOut4 = priorityProcessTail(head4, pOut);		//loads output register
		clockOut3++;									//tracks output clock cycles
		addPriority(head4, rIn1, priority[i]);			//sends value to the priority linked list
		clockIn3++;										//tracks input clock cycles
		cout << rOut4 << "\t\t" << *pOut << endl;		//outputs register value to console
	}

	//loop to output remaining values in linked lists and delete the lists
	while (head1->next != NULL)
	{
		rOut1 = processTail(head1);		//loads output register
		cout << rOut1 << "\t";			//outputs register value to console

		rOut2 = processTail(head2);		//loads output register
		cout << rOut2 << "\t";			//outputs register value to console

		rOut3 = processTail(head3);		//loads output register
		cout << rOut3 << "\t";			//outputs register value to console

		
		rOut1 = priorityProcessTail(head4, pOut);		//loads output register
		cout << rOut4 << "\t\t" << *pOut << endl;		//outputs register value to console
		clockOut3++;					//tracks output clock cycles
	}

	system("Pause");

	//Beginning of 4 inputs and 1 output run
	//loop to load first 10 values into buffer
	for (int i = 0; i < 10; i++)
	{
		rIn1 = rArray1[i];				//loads input register
		addFromHead(head1, rIn1);		//Adds to FIFO list

		rIn2 = rArray2[i];				//loads input register
		addFromTail(head2, rIn2);		//sends value to the LIFO linked list

		rIn3 = rArray3[i];				//loads input register
		addSort(head3, rIn3);			//sends value to the sorted linked list

		rIn4 = rArray4[i];							//loads input register
		addPriority(head4, rIn4, priority[i]);		//sends value to the priority linked list
		clockIn4++;									//tracks input clock cycles
	}

	//labels
	cout << endl << "Four input and One output registers" << endl << "FIFO\tLIFO\tSort\tPrioritized\tPriority" << endl;

	//loop to send remaining values to buffer.  Buffer is deleted from tail and the values output to the console
	for (int i = 10; i < 100; i++)
	{
		rIn1 = rArray1[i];				//loads input register
		rOut1 = processTail(head1);		//loads output register
		addFromHead(head1, rIn1);		//Adds to FIFO list
		cout << rOut1 << "\t";			//outputs register value to console
		clockOut4++;					//tracks output clock cycles

		rIn2 = rArray2[i];				//loads input register
		rOut1 = processTail(head2);		//loads output register
		addFromTail(head2, rIn2);		//sends value to the LIFO linked list
		cout << rOut1 << "\t";			//outputs register value to console
		clockOut4++;					//tracks output clock cycles

		rIn3 = rArray3[i];				//loads input register
		rOut1 = processTail(head3);		//loads output register
		addSort(head3, rIn3);			//sends value to the sorted linked list
		cout << rOut1 << "\t";			//outputs register value to console
		clockOut4++;					//tracks output clock cycles

		rIn4 = rArray4[i];								//loads input register
		rOut1 = priorityProcessTail(head4, pOut);		//loads output register
		clockOut4++;									//tracks output clock cycles
		addPriority(head4, rIn4, priority[i]);			//sends value to the priority linked list
		clockIn4++;										//tracks input clock cycles
		cout << rOut1 << "\t\t" << *pOut << endl;		//outputs register value to console
	}

	//loop to output remaining values in linked lists and delete the lists
	while (head1->next != NULL)
	{
		rOut1 = processTail(head1);		//loads output register
		cout << rOut1 << "\t";			//outputs register value to console
		clockOut4++;					//tracks output clock cycles

		rOut1 = processTail(head2);		//loads output register
		cout << rOut1 << "\t";			//outputs register value to console
		clockOut4++;					//tracks output clock cycles

		rOut1 = processTail(head3);		//loads output register
		cout << rOut1 << "\t";			//outputs register value to console
		clockOut4++;					//tracks output clock cycles

		rOut1 = priorityProcessTail(head4, pOut);		//loads output register
		cout << rOut1 << "\t\t" << *pOut << endl;		//outputs register value to console
		clockOut4++;									//tracks output clock cycles
	}


	//outputs number of clock cycles for input and output registers for each run
	cout << endl << "One register in: " << clockIn1; 
	cout << endl << "One register out: " << clockOut1 << endl;
	cout << endl << "Four registers in: " << clockIn2;
	cout << endl << "Four registers out: " << clockOut2 << endl;
	cout << endl << "One register in: " << clockIn3;
	cout << endl << "Four registers out: " << clockOut3 << endl;
	cout << endl << "Four registers in: " << clockIn4;
	cout << endl << "One register out: " << clockOut4 << endl;

	system("Pause");
	return 0;

}

//generates random values (0-99)
int randomNumber()
{
	int number = rand() % 100;
	return number;
}

//generates priority values (1-3)
int randomPriority()
{
	int number = rand() % 3;
	number = number + 1;
	return number;
}

//function to add to the head of a linked list.  It is passed the head and a value from a register
int addFromHead(node *head1, int rIn)
{
	struct node *current = head1,	//sets current to beginning of list
				*newNode = new(node);

	newNode->element = rIn;			//stores current value in new node
	newNode->next = current->next;	//sets newNode pointer
	current->next = newNode;		//updates pointer
	return 0;
}

//function to add to the tail of a linked list.  It is passed the head and a value from a register
int addFromTail(node *head2, int rIn)
{
	struct node *current = head2,	//sets current to beginning of list
				*newNode = new(node);

	while (current->next != NULL)
	{
		current = current->next;
	}
	newNode->element = rIn;			//stores current value in new node
	newNode->next = NULL;			//sets newNode pointer
	current->next = newNode;		//updates pointer
	
	return 0;
}

//function to add to the linked list by value.  It is passed the head and a value from a register
int addSort(node *head3, int rIn)
{
	struct node *current = head3,	//sets current to beginning of list
				*newNode = new(node);

	//goes through list until correct location is found
	while ((current->next != NULL) && (current->next->element < rIn))
	{
		current = current->next;
	}

	newNode->element = rIn;				//sets value of new node
	newNode->next = current->next;		//updates new node's point to current pointer
	current->next = newNode;			//updates current to point to new node

	return 0;
}

//function to add to the linked list based on priority.  It is passed the head, a value from a register, and a priority value
int addPriority(node *head4, int rIn, int priority)
{
	struct node *current = head4,	//sets current to beginning of list
				*newNode = new(node);

	//loop to progress though list and insert based on priority
	while ((current->next != NULL) && (current->next->priority > priority))
	{
		current = current->next;
	}

	newNode->element = rIn;				//sets value of new node
	newNode->priority = priority;		//sets priority of new node
	newNode->next = current->next;		//updates new node's point to current pointer
	current->next = newNode;			//updates current to point to new node

	return 0;
}

//this function processes the tail. This function travels to the end of the linked list
//saves the value held there, then deletes the node.  The value is returned to be loaded
//into a register for output.
int processTail(node *head)
{
	int output;		//holds the value to be output

	//Deletes the list if it is empty
	if (head->next == NULL) 
	{
		delete head;
		head = NULL;
	}
	//if list is not empty
	else 
	{
		struct node *nextToEnd = head;	//node to travel to penultimate node
		struct node *end = head->next;	//node to travel to end node

		//traverses until NULL is found
		while (end->next != NULL) 
		{
			nextToEnd = end;	//progresses the second to end nodes position
			end = end->next;	//moves on in the list
		}

		output = end->element;	//holds the final element in the list
		delete end;				//deletes final element
		nextToEnd->next = NULL;	//points new final node to NULL
	}
	return output;	//returns the value to be output by the register
}

//this function processes the tail for the priority linked list. 
//This function travels to the end of the linked list saves the value 
//held there, saves the priority, and then deletes the node.  
//The value is returned to be loaded into a register for output.

int priorityProcessTail(node *head, int *pOut)
{
	int output;		//holds the value to be output
					//Deletes the list if it is empty
	int outputPriority;
	if (head->next == NULL)
	{
		delete head;
		head = NULL;
	}
	//if list is not empty
	else
	{
		struct node *nextToEnd = head;	//node to travel to penultimate node
		struct node *end = head->next;	//node to travel to end node

										//traverses until NULL is found
		while (end->next != NULL)
		{
			nextToEnd = end;	//progresses the second to end nodes position
			end = end->next;	//moves on in the list
		}

		outputPriority = end->priority;	//Holds the priority of the processed node
		output = end->element;			//holds the final element in the list
		*pOut = outputPriority;			//saves the value to a pointer to be output used outside of function
		delete end;						//deletes final element
		nextToEnd->next = NULL;			//points new final node to NULL
	}
	return output;	//returns the value to be output by the register
}