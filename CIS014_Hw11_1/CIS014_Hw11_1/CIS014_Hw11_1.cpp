/*
Assignment 11.1
Due: 12/1/19
Purpose:function that takes in a pointer reference to an array of any arbitrary elevation and its array size,
		and outputs the total amount of water retention in that given terrain
*/
#include <iostream>
#include <algorithm>
using namespace std;

int getTotalWaterAmount(int* arr, int size);

int main()
{
	int arr[] = { 1,2,3,4,5,6,5,4,3,6,22,3,2 };
	int size = sizeof(arr) / sizeof(arr[0]);

	cout << getTotalWaterAmount(arr, size);
}

/*
PURPOSE: Takes in a pointer reference to an array of any arbitrary elevation and its array size,
		 and outputs the total amount of water retention in that given terrain
PARAMETERS: pointer reference of integer array containing elevation data and array size
RETURN VALUES: integer of units of water retained by the terrain
*/
int getTotalWaterAmount(int* arr, int size)
{
	int total = 0;
	for (int i = 1; i < size - 1; i++) { //iterate middle point through array 

		int leftPeak = arr[i]; //find peak on left
		for (int j = 0; j < i; j++)
		{
			leftPeak = max(leftPeak, arr[j]); //find find subpeak
		}

		int rightPeak = arr[i]; //find peak on right
		for (int j = i + 1; j < size; j++)
		{
			rightPeak = max(rightPeak, arr[j]); //find subpeak
		}
		total += (min(leftPeak, rightPeak) - arr[i]);
	}
	return total;
}

/*
TEST CASES:

input: 5,2,1,3,1,5
output: 13

input: 5,4,1,2
ouput: 1

input: 0,1,2,5,4,2,6,4,3,2,1,1,1,1,1,1,8
output: 43

input: 1,2,3,4,5,6,5,4,3,6,22,3,2
output: 6
*/