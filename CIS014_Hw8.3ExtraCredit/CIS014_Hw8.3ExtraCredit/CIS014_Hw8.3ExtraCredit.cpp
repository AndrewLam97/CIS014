// Recursive C program for 
// coin change problem. 
#include <iostream>
using namespace std;
bool f = false;


//int getLegoCombinations(vector<int>& lego_heights, int target_height) {}


// Returns the count of ways we can  
// sum S[0...m-1] coins to get sum n 
int count(int arr[], int size, int total)
{
	if (size == 1) {
		if (total % arr[0] == 0)
		{
			f = true;
			return 1;
		}
		else
			return 0;

	}
	// If n is 0 then there is 1 solution  
	// (do not include any coin) 
	if (total == 0)
		return 1;

	// If n is less than 0 then no  
	// solution exists 
	if (total < 0)
		return 0;

	// If there are no coins and n  
	// is greater than 0, then no 
	// solution exist 
	if (size <= 0 && total >= 1)
		return 0;

	// count is sum of solutions (i)  
	// including S[m-1] (ii) excluding S[m-1] 
	return count(arr, size - 1, total) + count(arr, size, total - arr[size - 1]);
}

// Driver program to test above function 
int main()
{
	int i, j;
	int arr[] = { 5 };
	int total = 9;
	int size = sizeof(arr) / sizeof(arr[0]);
	cout << count(arr, size, total) << endl;
	if(f == 0)
	{
		cout << "No operation performed, actually 0" << endl;
	}

	return 0;
}