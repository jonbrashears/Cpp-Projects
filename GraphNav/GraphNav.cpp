/*********************************************************
*
* Jonathan Brashears
* April 26, 2018
* Algorithms
* This program uses a matrix representation of a graph.
* It uses separate array to track the points visited.
* It visits each vertex of the graph by traveling
* along edges.  A algorithm for depth first searches
* and an algorithm for breadth first searches are
* preformed.  Each algorithm terminates when each
* vertex is visited.
*
********************************************************/
using namespace std;
#include <iostream>
#include <queue>
#include <stack>

void BFS();
void DFS();

int main()
{
	//calls the breadth first search
	BFS();

	//calls the depth first search
	DFS();

	//pauses to display results
	cin.get();
    return 0;
}

void BFS() {
	//Queue to hold values to be checked
	queue<int> graphQueue;

	//matrix to hold vertices and edges
	int graph[6][6] = { {0, 1, 1, 0, 0, 0},
						{1, 0, 0, 1, 1, 0},
						{1, 0, 0, 0, 1, 0},
						{0, 1, 0, 0, 1, 1},
						{0, 1, 1, 1, 0, 1},
						{0, 0, 0, 1, 1, 0} };

	//array to track which vertices we have visited
	int visited[6] = { 0, 0, 0, 0, 0, 0 };

	//variable we are starting at
	int start = 0;

	//pushes the starting vertex to the queue
	graphQueue.push(start);

	//we visit the point we start at
	visited[start] = 1;
	cout << "Breadth First Search: " << endl;
	cout << "Starting at " << start + 1 << endl;

	//loops until all points are visited
	while (visited[0] == 0 || visited[1] == 0 || visited[2] == 0
		|| visited[3] == 0 || visited[4] == 0 || visited[5] == 0)
	{
		//j holds the value of the front of the queue
		int j = graphQueue.front();
		cout << "Checking " << j+1 << "'s edges" << endl;
		//loop to check current front of queue
		for (int i = 0; i < 6; i++)
		{
			//if there is a connection, and we haven't visited the vertex, we go there
			if (graph[j][i] == 1 && visited[i] != 1)
			{
				//push to vertex to queue
				graphQueue.push(i);
				cout << "Discovered " << i + 1 << endl;

				//Mark it as discovered
				visited[i] = 1;
			}
		}

		//pop the value off of the queue
		graphQueue.pop();

		////loop to display what points we've visited for testing
		//for (int i = 0; i < 6; i++)
		//{
		//	cout << visited[i] << " ";
		//}

	}
	cout << endl << "All points discovered!" << endl << endl;
}

void DFS()
{
	//Stack to hold values to be checked
	stack<int> graphStack;

	//matrix to hold vertices and edges
	int graph[6][6] = { { 0, 1, 1, 0, 0, 0 },
						{ 1, 0, 0, 1, 1, 0 },
						{ 1, 0, 0, 0, 1, 0 },
						{ 0, 1, 0, 0, 1, 1 },
						{ 0, 1, 1, 1, 0, 1 },
						{ 0, 0, 0, 1, 1, 0 } };

	//array to track which vertices we have visited
	int visited[6] = { 0, 0, 0, 0, 0, 0 };

	//variable we are starting at
	int start = 0;

	//pushes the starting vertex to the stack
	graphStack.push(start);

	//we visit the point we start at
	visited[start] = 1;
	cout << endl << "Depth First Search:" << endl;
	cout << "Starting at " << start + 1 << endl;

	//loops until all points are visited
	while (visited[0] == 0 || visited[1] == 0 || visited[2] == 0 || visited[3] == 0 || visited[4] == 0 || visited[5] == 0)
	{
		int j = graphStack.top();
		cout << "Checking " << j + 1 << "'s edges" << endl;
		//loop to check current top of stack
			for (int i = 0; i < 6; i++)
			{
				//if there is a connection, and we haven't visited the vertex, we go there
				if (graph[j][i] == 1 && visited[i] != 1)
				{
					//push to vertex to stack
					graphStack.push(i);
					cout << "Discovered " << i + 1 << endl;
					//gets the new point from the stack
					j = graphStack.top();
					//lets the user know what vertex is being checked
					cout << "Checking " << j + 1 << "'s edges" << endl;
					//Mark it as discovered
					visited[i] = 1;
				}
			}
			//pop the value off of the Stack
			graphStack.pop();

			////loop to display what points we've visited for testing
			//for (int i = 0; i < 6; i++)
			//{
			//	cout << visited[i] << " ";
			//}
			//cout << endl;
	}

	cout << endl << "All points discovered!" << endl;
}
