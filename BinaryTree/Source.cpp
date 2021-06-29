/******************************************************************************************************
* Name: Jonathan Brashears
*
* Student ID: w835032
*
* Description : This program generates 20-99 digits based on user input.  These values are saved to a file.
*				The file is then opened and the values are read into a binary tree.  Values greater than
*				the current leaf are stored to the right, values less than are stored to the left.
*				The program will then print the values in ascending order.
*
* Date: 4/20/2017
********************************************************************************************************/

#include <iostream>

//linked list
struct node
{
	int element;
	struct node *left;
	struct node *right;
};

int createForwardList(int size);
struct node *insert(int readNumber, node *root);
void inOrder(node *root);

int main()
{
	int size = 0;
	cout << "These are the numbers in descending order: " << endl;
	createForwardList(size);	//Creates list as generated
	system("Pause");
	return 0;
}

int createForwardList(int size)
{
	struct node *root = NULL;		//head node
	int unsorted[14] = { 0, 1, 2, 3, 4, 5, 7, 9, 10, 12, 14, 15, 18, 20 };
	int readNumber;					//current number being read

	//loop to go through file
	for (int i = 0; i < 14; i++)
	{
		readNumber = unsorted[i];
		root = insert(readNumber, root);
	}
	inOrder(root);
	return 0;
}

//function for inserting nodes in order numbers are read
struct node *insert(int readNumber, node *root)
{
	//if root is Null a new node is created
	if (root == NULL)
	{
		root = new node;	//creates root

							//if root is unable to be created an exception is thrown
		if (root == NULL)
		{
			throw exception();
		}

		root->left = root->right = NULL;	//sets pointers to NULL
		root->element = readNumber;			//sets root element to first number from file
	}

	//if the read number is in our range
	else
	{
		//if the read number is less than our root it is inserted on the left
		if (readNumber < root->element)
			root->left = insert(readNumber, root->left);
		//if the read number is greater than our root it is inserted on the right
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
