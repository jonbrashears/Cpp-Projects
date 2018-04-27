/*************************************************************************
* Jonathan Brashears
* w835032
* 4/22/2017
* 
* Opens file dictionary.txt and saves the values to an array and then
* saves the array to a hashtable.  File check.txt is the opened and 
* compared to the hashtable.  Values in check.txt but not in the 
* hashtable are displayed to the user.
* 
* 
*
**************************************************************************/


#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//functions we will use in this program
int hash1(const char *, int);
int hash2(const char *, int);
int hash3(const char *, int);
int openDictionaryFile(struct node*[], int);
int openCheckFile(struct node*[], int);
void getCheckFileData(ifstream &ReadText, struct node*[], int tableSize);
void insert(char *, struct node*[], int);
struct node *findName(char *, struct node *[], int);

//Node we will use to hold data and memory allocation of next node if there is a collision
struct node
{
	char *str;
	struct node *next;
};

//main
int main()
{
	//Here we set a size for our hash table.  There is not a predetermined way to determine the size
	//of the table.  If it is too small, and you have a large amout of data, then you will
	//have many collisions.  If it is too large, and you have a small data set, then you will
	//waste memory space.  This usually is a prime number larger than the expected amount of data
	//
	//const int tableSize = 12941; //prime numbers
	const int tableSize = 15013; //8th prime number
	//const int tableSize = 11; //small table to demonstrate collisions

	//This is our hash table.  It is an array of nodes equivalent to the table size we have set
	struct node *nameList[tableSize];

	//Initializes all array entires to NULL.  You cannot skip this step
	for (int i = 0; i < tableSize; i++)
	{
		nameList[i] = NULL;
	}

	openDictionaryFile(nameList, tableSize);

	cout << endl;

	//calls the function to open the check.txt file.  
	openCheckFile(nameList, tableSize);

	system("Pause");
	return 0;
}

//Give a character string and the size of the hash table, add up the values of each char
// and return the sum table size
int hash1(const char *key, int tableSize)
{
	unsigned int hashVal = 0;

	while (*key != '\0')hashVal += *key++;

	return hashVal % tableSize;
}

//Given a character string and the size of the hash table, this alogrithm
//assumes the key has at least 2 chars plus the null byte
int hash2(const char *key, int tableSize)
{
	//It is the number of letters plus the blank in the English alphabet. 729 is 27 squared
	return(key[0] + 27 * key[1] + 729 * key[2]) % tableSize;

}

//loop through the key, 1 char at a time.  Add the char's value to hashVal *32
int hash3(const char *key, int tableSize)
{
	unsigned int hashVal = 0;

	while (*key != '\0') hashVal = (hashVal * 32) + *key++;

	return hashVal % tableSize;
}

//This function creates a char array to hold words and opens the file dictionary.txt.  The words from the file are then saved
//into the array words.  Words is then passed to our insert function the words are added to a hashtable.
int openDictionaryFile(struct node* nameList[], int tableSize)
{

	//array to hold up to 12000 words
	char *words[12000];

	//initializes all of the array
	for (int i = 0; i < 12000; i++) {
		words[i] = new char[64] {0};
	}

	ifstream ReadDictionary;
	//opens the file dictionary.txt
	ReadDictionary.open("dictionary.txt");

	//checks if file was succesfully opened
	if (!ReadDictionary)
	{
		cout << "Could not open file for reading." << endl;

		return(1);
	}

	//counts the number of words read from dicionary.txt
	int fileOneCounter = 0;

	//while loop that iterrates as long as words are being read from the file
	while (ReadDictionary.good())
	{
		ReadDictionary >> words[fileOneCounter];		//saves word from file to our array
		fileOneCounter++;							//increments for each word read
	}

	//closes dictionary.txt
	ReadDictionary.close();

	//loop to insert words into the hash table itterates for as many loops as words in the file 
	for (int i = 0; i < fileOneCounter; i++)
	{
		insert(words[i], nameList, hash2(words[i], tableSize));

	}
	return 0;
}


//file to open check.txt.  This function throws an error if the file could not be opened. 
//The function to get the data from the file is called and is passes the ifstream, the 
//hashtable and the tablesize
int openCheckFile(struct node* nameList[], int tableSize)
{
	ifstream ReadText;

	//Opens the designated file
	ReadText.open("check.txt");

	//checks if file was succesfully opened
	if (!ReadText)
	{
		cout << "Could not open file for reading." << endl;

		return(1);
	}
	
	//calls function to get data from filee.  It is passed the ifstream, the hashtable, and the tablesize
	getCheckFileData(ReadText, nameList, tableSize);

	//closes file when we're done
	ReadText.close();

	return 0;
}

//gets data from check.txt and saves it to our checkArray.
//The function also calls the findName function.
void getCheckFileData(ifstream &ReadText, struct node* nameList[], int tableSize)
{
	char *checkArray[12000]; //array to hold up to 12000 words

	//initializes array
	for (int i = 0; i < 12000; i++) 
	{
		checkArray[i] = new char[64]{0};
	}

	//int to keep track of number of words read from file
	int fileTwoCounter = 0;

	//loop that increments the file counter and saves the words from the file to our array
	while (ReadText.good())
	{	
		
		ReadText >> checkArray[fileTwoCounter];
		fileTwoCounter++;
	}

	//This is a tmperary node. 
	struct node *tmp;

	//loop to call findName function for each word in the array.  Uses our counter to determine
	//how many times the loop is needed
	for (int i = 0; i < fileTwoCounter; i++)
	{
		tmp = findName(checkArray[i], nameList, tableSize);

		//does nothing if the word is found in dictionary.txt
		if (tmp)
		{
			
		}

		//Lets the user know that the word was not found if it is not in dictionary.txt
		else
		{
			cout << checkArray[i] << " is not in the dictionary" << endl;
		}
	}
}

//Given a name, an array, and a hash key, insert name into the array at locationhash key.  If there is a collision
//insert name into a linked list at array index hash key
void insert(char *words, struct node *nameList[], int key)
{
	//If there is a collision in our hash table a linked list gets created and inserted at
	//the end of the list.  we usa  counter to show us how long the list may be
	int count = 1;

	//We createa node to insert into the table
	struct node *newNode = new(node);

	//Assing the information we have to the node we just created.  Because we are inserting
	// the node at the end of the list, we can set the pointer to NULL.  You could use a sentinel
	//node as the head for the list, and do our inserts at the begining of the list,  That allows
	//your insert to be O[1] time which is what we like.  Insetion at the end of the list
	// could be come O(n) if you have a poor hash function
	newNode->str = _strdup(words);
	newNode->next = NULL;

	//If the location in the hash table currently is empty(NULL) then insert the new node
	if (nameList[key] == NULL)
	{
		nameList[key] = newNode;
	}

	//If the location in the hash table already has a node stored in it, we have a collision.
	//We traverse the list to the end and then insert the new node
	else
	{
		struct node *tmp = nameList[key];

		while (tmp->next)
		{
			++count;
			tmp = tmp->next;
		}

		++count;

		tmp->next = newNode;
	}

	//Notify the user what was done
	cout << "Inserted " << words << " at index " << key << " node number " << count << endl;

}

//Given a name to find, the hash table and the table size, return a pointer to the node
//containing the name (or NULL if not found)
struct node *findName(char *checkArray, struct node *nameList[], int tableSize)
{
	//determine the posslbe location by calculating the key.  This has to be the same as was
	//used to store the key
	int key = hash2(checkArray, tableSize);

	//Use the key to ceck the location in the hash table.  If it returns NULL the value is not
	//in the table
	if (nameList[key] == NULL) return(NULL);

	//If the key does not return NULL, we compare what we are looking for to what is stored at
	//the location.  If it is a match return the value
	if (strcmp(nameList[key]->str, checkArray) == 0)
		return (nameList[key]);

	//If the key does not return NULL and the key did not return the value stored at the location
	//we have a list, so we traverse the list
	else
	{
		//tmp node to use for traversal
		struct node *tmp = nameList[key];

		//while loop to advance tmp as long as it does not match what si stored at the location
		while (tmp->next && (strcmp(tmp->str, checkArray) != 0)) tmp = tmp->next;

		//returns the value found or NULL if it is not in the list.  the last pointer in the list
		//is MULL
		return(tmp);
	}
}