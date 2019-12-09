/*
Assignment #12
Due: 12/8/19
Purpose: function that takes in a R x C vector (namely, a vector of vectors)
		 representing your terrain map, where R > 0 and C > 0, and outputs the
		 total amount of water retention in that given map
*/
#include <iostream>
#include <climits>
#include <vector>
#include <queue>
using namespace std;

typedef pair<int, int> p;

int getTotalWaterAmount(vector<vector<int>>& map);

int main()
{
	vector<vector<int>> map = {
	{13,45,33,77,335,2,3},

	{32,25,123,1,3,41,3},

	{13,64,19,73,3,212,3},

	{52,3,35,35,389,13,3},

	{1,4,9,7,3,21,3}

	};
	cout << getTotalWaterAmount(map);
}

/*
Purpose: function that takes in a R x C vector (namely, a vector of vectors)
		 representing your terrain map, where R > 0 and C > 0, and outputs the
		 total amount of water retention in that given map
Parameters: 2D vector (vector of vectors) of integers
Return Values: integer of units of water retained by the terrain
*/
int getTotalWaterAmount(vector<vector<int>>& map)
{
	int R = map.size(), C = map[0].size(), total = 0;

	vector<int> visited(R * C, 0); //store visited cells for BFS
	priority_queue<p, vector<p>, greater<p>> q; //min height priority queue of cell pairs (height, index)

	for (int i = 0; i < R * C; i++) //add edge cells to queue, convert local index (row, col) to global index i	
		if (i % C * ((i + 1) % C) * (i / C) * (i / C - R + 1) == 0) //edge
			q.emplace(map[i / C][i % C], i), visited[i] = 1; //store and mark as visited 

	for (int i, maxH = INT_MIN; q.size(); ) { //BFS implementation
		auto current = q.top(); //get first in priority queue (lowest)
		q.pop(); //remove current from queue
		maxH = max(maxH, current.first); //current max height of water
		for (int d : {C, -C, 1, -1}) //direction
			if ((i = current.second + d) >= 0 && i < R * C && !visited[i]) //if unvisited neighbor
				total += max(maxH - map[i / C][i % C], 0), q.emplace(map[i / C][i % C], i), visited[i] = 1; //add retained water to total
	}
	return total;
}

/*
Test Cases:
vector<vector<int>> map = {
	{6,2,4,123},

	{33,2,35,10},

	{12,3,0,23},

	{83,33,2,34}

	};
output: 2

vector<vector<int>> map = {
	{1,4,3,7,3,2},

	{3,2,1,1,3,4},

	{5,3,3,5,3,1}

	};
output: 5

vector<vector<int>> map = {
	{13,45,33,77,335,2,3},

	{32,25,123,1,3,41,3},

	{13,64,19,73,3,212,3},

	{52,3,35,35,389,13,3},
	
	{1,4,9,7,3,21,3}

	};
output: 140

vector<vector<int>> map = {
	{123}

	};
output: 0

vector<vector<int>> map = {
	{9,2},

	{2,1}

	};
output: 0
*/