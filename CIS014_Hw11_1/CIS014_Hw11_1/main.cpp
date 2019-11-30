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
	int arr[] = { 0,1,2,5,4,2,6,4,3,2,1,1,1,1,1,1,8 };
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

		int left = arr[i]; //find peak on left
		for (int j = 0; j < i; j++)
		{
			left = max(left, arr[j]);
		}

		int right = arr[i]; //find peak on right
		for (int j = i + 1; j < size; j++)
		{
			right = max(right, arr[j]);
		}
		total = total + (min(left, right) - arr[i]);
	}
	return total;
}
