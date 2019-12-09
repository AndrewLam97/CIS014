/*
ASSIGNMENT: 10.1
DUE: 11/17/19
PURPOSE: Produce the max amount of points possible given a pyramid maze for pinball
*/
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class CIS14 {
public:
	int getMaxPoints(vector<vector<int>>& maze);
};

/*
PURPOSE: Traverse maze from top-down in a pinball-like fashion and find max amount of points 
PARAMETERS: vector of integer vectors representing maze
RETURN VALUES: intger of max points possible
*/
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
	vector<vector<int>> maze = { {1}, {1,-10}, {1,30,1}, {1,-1,-1,1} };
	cout << cis14.getMaxPoints(maze);
}

/*
TEST CASES:
{{0}, {4,1}, {5,3,8}, {1,6,7,3}};	16

vector<vector<int>> maze = { {1}, {1,1}, {1,1,1}, {1,1,1,1} };		4

vector<vector<int>> maze = { {3}, {7,4}, {2,4,6}, {8,5,9,3} };		23

vector<vector<int>> maze = { {1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10} };		52937

vector<vector<int>> maze = { {1}, {1,-10}, {1,30,1}, {1,-1,-1,1} };		31
*/