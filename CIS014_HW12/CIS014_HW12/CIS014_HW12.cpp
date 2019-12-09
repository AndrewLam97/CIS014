/*
Assignment #12
Due: 12/8/19
Purpose: function that takes in a R x C vector (namely, a vector of vectors)
		 representing your terrain map, where R > 0 and C > 0, and outputs the 
		 total amount of water retention in that given map
*/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

/*
Purpose: function that takes in a R x C vector (namely, a vector of vectors)
		 representing your terrain map, where R > 0 and C > 0, and outputs the 
		 total amount of water retention in that given map
Parameters: 2D vector (vector of vectors) of integers
Return Values: integer of units of water retained by the terrain
*/
int getTotalWaterAmount(vector<vector<int>>& map)
{
typedef pair<int, int> cell;
	priority_queue<cell, vector<cell>, greater<cell>> q;
	int m = map.size();
	if (m == 0) return 0;
	int n = map[0].size();
	vector<int> visited(m * n, false);

	for (int i = 0; i < m; ++i)
		for (int j = 0; j < n; ++j) {
			if (i == 0 || i == m - 1 || j == 0 || j == n - 1) {
				if (!visited[i * n + j])
					q.push(cell(map[i][j], i * n + j));
				visited[i * n + j] = true;
			}
		}

	int dir[4][2] = { {0,1}, {0, -1}, {1, 0}, {-1, 0} };
	int ans = 0;
	while (!q.empty()) {
		cell c = q.top();
		q.pop();
		int i = c.second / n, j = c.second % n;

		for (int r = 0; r < 4; ++r) {
			int ii = i + dir[r][0], jj = j + dir[r][1];
			if (ii < 0 || ii >= m || jj < 0 || jj >= n || visited[ii * n + jj])
				continue;
			ans += max(0, c.first - map[ii][jj]);
			q.push(cell(max(c.first, map[ii][jj]), ii * n + jj));
			visited[ii * n + jj] = true;
		}
	}
	return ans;
}

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

