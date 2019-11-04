/*
Assignment 8.3 Extra Credit
DUE: 11/3/19
PURPOSE: Calculate the number of possible ways to build a wall of height target_height
using the bricks present in vector lego_heights in unlimited supply
*/
#include <iostream>
#include <vector>
using namespace std;

/*
PURPOSE: Calculate the number of possible ways to build a wall of height target_height
using the bricks present in vector lego_heights in unlimited supply
PARAMETERS: integer vector lego_heights and integer target_height
RETURN VALUES: integer of number of possible combinations
*/
int getLegoCombinations(vector<int>& lego_heights, int target_height) {
	if (lego_heights.size() == 1) //handle only 1 brick
		return target_height % lego_heights[0] == 0 ? 1 : 0;
	if (target_height == 0) //handle target_height = 0
		return 0;

	int numCoins = lego_heights.size(); //determine # of types of coins
	int S[target_height + 1][numCoins]; //declare 2D array
	for (int i = 0; i <= target_height; i++) //iterate through lesser target_height values
  {
		for (int j = 0; j < numCoins; j++) //iterate through coins
    {
			if (i == 0) //handle height 0
				S[0][j] = 1; //set solution = 1, important for summation
			else 
      {
				S[i][j] = 0; //initialize each cell
				for (int k = 0; k <= j; k++) //utilize coins
        {
					int remain = i - lego_heights[k]; //calculate using current coin
					S[i][j] += ((remain >= 0) ? S[remain][k] : 0); //set cell to sum of prev and current
				}
			}
		}
	}
	int result = S[target_height][numCoins - 1]; //find element with desired result in solution table
	return result;
}

// Driver program to test above function 
int main()
{
	vector<int> lego_heights = { 1,2,5 };
	int total = 3;

	cout << getLegoCombinations(lego_heights, total);

	return 0;
}