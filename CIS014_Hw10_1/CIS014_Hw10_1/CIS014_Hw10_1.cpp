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
	for (int i = maze.size() - 2; i >= 0; i--)
		for (int j = 0; j <= i; j++)
			maze[i + 1][j] > maze[i + 1][j + 1] ? maze[i][j] += maze[i + 1][j] : maze[i][j] += maze[i + 1][j + 1];
	return maze[0][0];
}

int main()
{
	CIS14 cis14;
	vector<vector<int>> maze = { {1}, {1,22305}, {1,29394,1}, {1,1,1234,1}, {1,1,3,1,10} };
	cout << cis14.getMaxPoints(maze);
}