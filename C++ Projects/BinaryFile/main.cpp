#include <ctime>
#include <iostream>
#include <fstream>
#include <limits>
#include <cstdlib>
using namespace std;

int GetSize(int Size)
{
    while(Size < 1|| Size > 100)
    {
        cout << endl;
        cout << "How many ints do you want to generate?";
        cin >> Size;

        if(cin.fail()|| Size < 1 || Size > 100)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << endl << "Invalid option, try again";
        }
        cout << endl << endl;
    }
    return(Size);
}

int main()
{
    int Size = 0;

    Size = GetSize(Size);

    ofstream WriteText;
    WriteText.open("Data.txt");

    if(!WriteText)
    {
        cout <<"Could not create/open text file for writing." << endl;

        return(1);
    }

    ofstream WriteBinary;
    WriteBinary.open("Data.file",ios::out | ios::binary);

    if(!WriteBinary)
    {
        cout << "Could not create/open binary file for writing. " << endl << endl;
        return(1);
    }

    srand(time(NULL));

    cout<<"Start writing data to files"<<endl<<endl;
    int dataSize = Size/2;
    int Number=1;
    WriteBinary.write(reinterpret_cast<const char *>(&Number),sizeof(int));
    Number=0;
    WriteBinary.write(reinterpret_cast<const char *>(&Number),sizeof(int));
    Number=1;
    WriteBinary.write(reinterpret_cast<const char *>(&Number),sizeof(int));
    Number = 0;
    WriteBinary.write(reinterpret_cast<const char *>(&dataSize),sizeof(int));
    WriteText << 1 << endl;
    WriteText << 0 << endl;
    WriteText << 1 << endl;
    WriteText << dataSize << endl;
    for(int i = 0; i < Size; i++)
    {
        Number = rand()%100;

        cout << Number << endl;

        WriteText << Number << endl;
        WriteBinary.write(reinterpret_cast<const char *>(&Number),sizeof(int));
    }
    WriteText.close();
    WriteBinary.close();

    cout << endl << "Begin reading date from the files" << endl << endl;

    int *TextReadArray = new int[Size+4];
    int *BinaryReadArray = new int[Size+4];

    ifstream ReadText;
    ReadText.open("Data.txt");

    if(!ReadText)
    {
        cout <<"Could not open text file for reading." << endl << endl;

        return(1);
    }

    ifstream ReadBinary;
    ReadBinary.open("Data.file",ios::in | ios::binary);

    if(!ReadBinary)
    {
        cout << "Could not open binary file for reading." << endl << endl;

        return(1);
    }

    cout << "Text" << "\t" << "Binary" << endl << endl;

    for (int i = 0; i < Size+4; i++)
    {
        ReadText >> TextReadArray[i];

        ReadBinary.read((char*)&BinaryReadArray[i], sizeof(int));

        cout << TextReadArray[i] << "\t" << BinaryReadArray[i] << endl;
    }
    cout << endl;

    ReadText.close();
    ReadBinary.close();

    delete[] TextReadArray;
    delete[] BinaryReadArray;

    system("PAUSE");
    return(0);

}
