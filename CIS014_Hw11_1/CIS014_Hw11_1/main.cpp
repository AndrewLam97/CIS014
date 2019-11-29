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

	// For every element of the array 
	for (int i = 1; i < size - 1; i++) {

		// Find the maximum element on its left 
		int left = arr[i];
		for (int j = 0; j < i; j++)
			left = max(left, arr[j]);

		// Find the maximum element on its right    
		int right = arr[i];
		for (int j = i + 1; j < size; j++)
			right = max(right, arr[j]);

		// Update the maximum water
		total = total + (min(left, right) - arr[i]);
	}

	return total;
}
