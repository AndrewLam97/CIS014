#include <iostream>
#include <vector>
using namespace std;

class CIS14 {
public:
	int getMaxPoints(vector<vector<int>>& maze);
private:
	vector<int> results;
};

int CIS14::getMaxPoints(vector<vector<int>>& maze)
{
	int subtotal = 0;
	if (maze.size() == 0) return 0;
	
	for (int i = 0; i < maze.size(); i++)
	{
		for (int j = 0; j < maze[i].size(); j++)
		{

		}
	}
}


int main()
{

}