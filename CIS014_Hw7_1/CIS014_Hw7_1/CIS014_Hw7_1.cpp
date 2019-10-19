/*
Assignment 7.1
DUE: 10/20/19
PURPOSE: Take an integer vector consisting of stock prices in chronological order.
Recommend the maximum profit an investor can make by placing at most one buy and sell order in the time slice represented by the input vector
*/
#include <iostream>
#include <vector> 
using namespace std;

int getMaxProfit(vector<int>& prices);

int main()
{
	vector<int> prices = { 4,1,2 };
	cout << getMaxProfit(prices);
}

int getMaxProfit(vector<int>& prices)
{
	int min = prices[0], max = 0, total = 0;

	for (auto i : prices)
	{
		if (i < min) min = i;
		else if (i > max) max = i;
	}
	total = max - min;
	if (total < 0) total = 0;

	return total;
}