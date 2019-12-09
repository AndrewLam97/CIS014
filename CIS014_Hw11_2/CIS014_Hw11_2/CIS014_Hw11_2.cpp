/*
Assignment 11.2
Due: 12/1/19
Purpose: function that takes in a pointer reference to an array of any arbitrary elevation profile and its array size,
		 and outputs the max cross sectional area of the biggest pond based on this profile
*/
#include <iostream>
#include <algorithm>
using namespace std;

int getMaxPond(int* arr, int size);

int main()
{
	int arr[] = { 1,99,1 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << getMaxPond(arr, size);
}

/*
Purpose: Takes a pointer reference to an array of an arbitrary elevation profile and its array size,
		 and outputs the max cross sectional area of the biggest pond based on this profile
Parameters: pointer to elevation profile array and integer array size
Return Values: integer of max cross sectional area
*/
int getMaxPond(int* arr, int size)
{
	int maxArea = 0;
	for (int i = 0; i < size; i++) //iterate starting point through array
	{
		for (int j = size - 1; j >= i; j--) //iterate end point back through array
		{
			int temp = (j - i) * min(arr[i], arr[j]); //calculate temp area between both points
			if (temp > maxArea) //if temp area larger than stored area, update stored area
				maxArea = temp;
		}
	}
	return maxArea;
}

/*
Test Cases:

input: 22,31,1,23
output: 66

input: 1,3,5
output: 3

input: 1,99,1
output: 2
*/