/*
Assignment 7.2
DUE: 10/20/19
PURPOSE: Take an integer vector consisting of stock prices in chronological order.
Recommend the maximum profit an investor can make by placing as many buy and sell orders as possible
Must sell previous before buying
*/

#include <iostream>
#include <vector> 
using namespace std;

int getMaxProfit(vector<int> &prices);

int main()
{
	vector<int> prices = { 5,1,5,9,1 };
	cout << getMaxProfit(prices);
}

/*
PURPOSE: Takes an integer vector consisting of stock prices in chronological order.
Calculates the maximum profit possible by placing as many buy and sell orders as possible
PARAMETERS: integer vector prices
RETURN VALUES: integer of max possible profit
*/
int getMaxProfit(vector<int> &prices)
{
	struct Stock { 
		int val;
		int pos;
	};

	Stock min = { prices[0], 0 }, max = { prices[0], 0 }; //initialize min and max
	int total = 0;

	for (int i = 0; i < prices.size(); i++)
	{
		if (prices[i] < min.val && max.pos <= i) //check current value and position
		{
			max = { 0 , i }; //reset max if new min discovered (decreasing prices)
			min.val = prices[i];
			min.pos = i;
		}
		else if (prices[i] > max.val) //set max
		{
			max.val = prices[i];
			max.pos = i;
		}
		if (max.val > min.val && max.pos > min.pos) //check val and pos are valid
		{
			total += max.val - min.val; //add difference in val
			min = max; //reset min
			max = { prices[0],0 }; //reset max
		}
	}
	return total;
}

/*
TEST CASES
vector<int> prices = { 3,1,5,2,4 };
6 //5-1, 4-2

vector<int> prices = { 9,2,5,1,6 };
8

vector<int> prices = { 1,2,5,1,6 };
9

vector<int> prices = { 2,8,1,5 };
10

vector<int> prices = { 4,2,1 };
0

vector<int> prices = { 1,2,4 };
3

vector<int> prices = { 1 };
0
*/