/******************************************************************************************************
* Name: Jonathan Brashears
*
* Student ID: w835032
*
* Description : This program takes an unsorted array and creates a searchable binary tree.  The user
*				is then asked to input a value to search for.  If the value is present in the tree it
*				is output.  If not, the user is notified.  The program then sorts the array and asks the
*				user which key they would like to run a binary search for.  The array is split and 
*				its midpoints checked recursively until the value is found.  If the value is not present,
*				the user is notified.  If the value is found, the user is notified and given its index.
* Date: 3/20/2018
********************************************************************************************************/
using namespace std;
#include <iostream>

//linked list 
struct node
{
	int element;			//holds value
	struct node *left;		//points to lesser value
	struct node *right;		//points to higher value
};

//prototypes
int createForwardList();
struct node *insert(int readNumber, node *root);
void inOrder(node *root);
int treeSearch(node *root);
int binarySearch();

int main()
{
	cout << "This is our unsorted array: " << endl;
	createForwardList();	//Creates a linked list
	binarySearch();			//Performs binary search
	system("Pause");		//pauses console
	return 0;				//no errors
}

int createForwardList()
{
	struct node *root = NULL;		//head node
	int unsorted[14] = {3, 0, 1, 10, 18, 4, 7, 20, 15, 9, 2, 12, 14, 5};	//unsorted array
	int readNumber;					//current number being read
	int size;
	
	size = (sizeof(unsorted) / sizeof(unsorted[0]));  //calculates size of the array
	//loop to move through array and insert nodes
	for (int i = 0; i < size; i++)
	{
		readNumber = unsorted[i];
		cout << unsorted[i] << endl;
		root = insert(readNumber, root);
	}

	//calls funtion to search the tree
	treeSearch(root);
	//inOrder(root);	//function to output the tree in order
	return 0;
}

//function for inserting nodes in order numbers are read
struct node *insert(int readNumber, node *root)
{
	//if root is Null a new node is created
	if (root == NULL)
	{
		root = new node;	//creates root

		root->left = root->right = NULL;	//sets pointers to NULL
		root->element = readNumber;			//sets root element to first number from file
	}

	//if the read number is in our range
	else
	{
		//if the read number is less than our root it is passed to this function again and the 
		//next node to the left is checked.  This is done recursively until we find the correct leaf placement
		if (readNumber < root->element)
			root->left = insert(readNumber, root->left);

		//if the read number is greater than our root it is passed to this function again and the 
		//next node to the right is checked.  This is done recursively until we find the correct leaf placement
		else if (readNumber > root->element)
			root->right = insert(readNumber, root->right);
	}

	return root; //returns root
}

//this function is passed our root.  if the root is not NULL it displays the 
//elements in our tree from right to left.  Due to the order of our insertion 
//the elements will be displayed in ascending order
void inOrder(node *root)
{
	if (root != NULL)
	{
		inOrder(root->left);			//starts from left of root
		cout << root->element << endl;	//displays elements
		inOrder(root->right);			//moves to right side of root

	}
}

//this function is passed our root.
//it then asks the user to input a value to search for.  While the current node
//is not Null we check the current element vs our key.  If our key is greater than
//the current element, we got right, if it is less than, we go left,  and if it 
//is equal, our search is complete and we output the value.  
//If current is equal to NULL our value is not present
int treeSearch(node *root)
{
	int key;		//value user wants to search for

	//asks user to input a search term
	cout << endl << "What value would you like to search the binary tree for?" << endl;

	//user inputs search term
	cin >> key;		

	cout << endl;

	//node for moving through tree
	struct node *current = root;

	//loops while current is not NULL or we have not found our key
	while (current != NULL)
	{
		
		//If we found they key, notify the user and exit the loop
		if (key == current->element)
		{
			cout << key << " found." << endl;
			return 0;
		}
		//if the key is greater than the current element, we move right
		if (key > current->element)
		{
			current = current->right;
		}
		//if the key is less than the current element, we move left
		else if (key < current->element)
		{
			current = current->left;
		}
	}

	//if current is NULL the key was not present
	if (current == NULL) {
		//notifies the user that the key was not found
		cout << key << " not found." << endl;
		return 0; //no errors.
	}

}


//This function sorts the array, then asks the user for a value to search for
//This value is checked against the mid point of the array.  If the value is
//greater than the mid point, we check against the mid point of the top half 
//of the array, if the value is lower than the mid point, we check against
//the mid point of the lower half of the array.  This is done recursively
//until we have found our key, or we determine that the value is not in the 
//array (no more mid points to check)
int binarySearch()
{
	int key;			//value to be searched for
	int mid;			//mid point being checked
	int high;			//high point of array
	int low;			//low point of array
	int size;			//holds size of array
	int temp;			//temp variable to swap values
	int sort[14] = { 3, 0, 1, 10, 18, 4, 7, 20, 15, 9, 2, 12, 14, 5 };	//unsorted array
	
	size = (sizeof(sort) / sizeof(sort[0]));  //calculates size of the array

	//selection sort
	for (int i = 0; i < 14; i++)
	{
		for (int j = i; j > 0; j--)
		{
			if (sort[j] < sort[j - 1])
			{
				temp = sort[j];
				sort[j] = sort[j - 1];
				sort[j - 1] = temp;
			}
		}
	}

	//outputs the sorted array to the console
	cout << "The sorted array is: " << endl;
	for (int i = 0; i < 14; i++)
	{
		cout << sort[i] << endl;
	}

	//asks for user to input value to search for
	cout << endl << "Enter key to run a binary search for: " << endl;
	//user inputs value to search for
	cin >> key;
	cout << endl;

	//initializes the highest index
	high = size;
	//initializes the low index
	low = 0;

	//search loop
	//will continue looping until the value is found, or the entire array is searched. (if low is <= to high, there is no more mid points to check)
	while (low <= high)
	{
		//calculates midpoint
		mid = (low + high) / 2;

		//if the mid point we're checking is higher than the key, we find a new high point and check below it
		if (sort[mid] > key)
		{
			high = mid - 1;
		}
		//if the mid point we're checking is lower than the key, we find a new low point and check above it
		else if (sort[mid] < key)
		{
			low = mid + 1;
		}
		//If the other conditions are not met, we have found our value.
		else
		{
			//ouputs value to console
			cout << sort[mid] << " found at index " << mid << "." << endl;
			return 0;//exits loop
		}
	}
	//if we exit the loop without finding the key, the value is not in the array
	//notify user of search result
	cout << "Key not found" << endl;
	
}