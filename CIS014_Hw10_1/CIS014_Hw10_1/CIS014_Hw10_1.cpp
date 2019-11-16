#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CIS14 {
public:
	int getMaxPoints(vector<vector<int>>& maze);
};

int CIS14::getMaxPoints(vector<vector<int>>& maze)
{
	if (maze.size() == 0 || maze[0].size() == 0) //handles empty vector array and an array of empty vectors
	{
		return 0;
	}

	for (int i = maze.size() - 2; i >= 0; i--) //start at row max-1 and work backwards
		for (int j = 0; j <= i; j++) //iterate through row
			maze[i + 1][j] > maze[i + 1][j + 1] ? maze[i][j] += maze[i + 1][j] : maze[i][j] += maze[i + 1][j + 1];  //check if row [j] > [j+1], 
																													//add greater num to row above at same index [j] or j[-1]
	return maze[0][0];
}

int main()
{
	CIS14 cis14;
	vector<vector<int>> maze = { {0}, {7,4}, {2,4,6}, {8,5,9,3} };
	cout << cis14.getMaxPoints(maze);
}