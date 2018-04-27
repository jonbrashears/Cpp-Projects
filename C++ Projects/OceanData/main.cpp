#include <ctime>
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
#include <string>
using namespace std;

void getFileName(string fileName);
int openFile(string fileName);
void getMetaData();

int metaData[3];
int size = 0;
int main()
{
	string fileName;
	getFileName(fileName);
	openFile(fileName);
	getMetaData();
	system("Pause");
	return 0;
}

void getFileName(string fileName)
{
	cout << "Which file would you like to open?" << endl;
	cin >> fileName;
}

int openFile(string fileName)
{
	cout << fileName << endl;
	ifstream ReadBinary;

	ReadBinary.open(fileName.c_str(), ios::in | ios::binary);

	if (!ReadBinary)
	{
		cout << "Could not open file for reading." << endl;

		return(1);
	}
}

void getMetaData()
{
	ifstream ReadBinary;
	for (int i = 0; i < 3; i++)
	{
		ReadBinary.read((char*)&metaData[i], sizeof(int));
	}
	ReadBinary.read((char*)&size, sizeof(int));

	cout << size;
}
