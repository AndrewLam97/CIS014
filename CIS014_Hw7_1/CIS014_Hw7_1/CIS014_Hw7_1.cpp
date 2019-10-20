/*
Assignment 7.1
DUE: 10/20/19
PURPOSE: Take an integer vector consisting of stock prices in chronological order.
Recommend the maximum profit an investor can make by placing at most one buy and sell order in the time slice represented by the input vector
*/
#include <iostream>
#include <vector> 
using namespace std;

int getMaxProfit(vector<int> &prices);

int main()
{
	vector<int> prices = { 2,9,1,4 };
	cout << getMaxProfit(prices);
}

/*
PURPOSE: Takes an integer vector consisting of stock prices in chronological order.
Calculates the maximum profit possible by placing one buy and sell order
PARAMETERS: integer vector prices 
RETURN VALUES: integer of max possible profit
*/
int getMaxProfit(vector<int> &prices)
{
	struct Stock {
		int val;
		int pos;
	};

	Stock min = { prices[0], 0 }, max = {0, 0}; //initialize min and max
	int total = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < min.val && max.pos <= i)
		{
			max = { 0,i }; //reset max if new min discovered (decreasing prices)
			min.val = prices[i]; //set min
			min.pos = i;
		}
		else if (prices[i] > max.val) //check current value against max
		{
			max.val = prices[i];
			max.pos = i;
		}
		if (min.pos < max.pos) //check min and max positions
		{
			if(max.val - min.val > total) //calculate new total
				total = max.val - min.val;
		}
	}
	return total;
}

/*
TEST CASES
vector<int> prices = { 3,1,2,4 };
3

vector<int> prices = { 2,8,1,5 };
6

vector<int> prices = { 1 };
0

vector<int> prices = { 1,2,99,1 };
98

vector<int> prices = { 4,2,1 };
0

vector<int> prices = { 3,1,5,2,4 };
4

vector<int> prices = { 9,2,5,1,6 };
5
*/