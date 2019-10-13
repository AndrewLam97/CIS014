/*
Assignment Hw6.1
Due: 10/13/19
Purpose: Shift elements to the right in an array
*/
#include <iostream>
using namespace std;

/*
PURPOSE: Swaps elements in an array
PARAMETERS: array arr, index of elements to be swapped
RETURN VALUES: none, array passed by pointer
*/
void swap(int arr[], int i, int y)
{
	int temp = arr[i];
	arr[i] = arr[y];
	arr[y] = temp;
}

/*
PURPOSE: Simulate the effect of a circular array, shift elements of an array of size N, to the right by M elements
PARAMETERS: integer array arr, integer N size of array, integer M desired shift
RETURN VALUES: none, array passed by pointer
*/
void rightShiftElements(int arr[], int N, int M)
{
	if (M > N)
	{
		M = M % N;
	}

	for (int i = N-1; i > 0; i--)
	{
		int y = i + M;
		if (y >= N)
		{
			y -= N;
		}
		swap(arr, i, y);
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6, 7, 8};
	int size = sizeof(arr) / sizeof(arr[0]);

	rightShiftElements(arr, size, 2);

	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i]; cout << ((i == size - 1) ? "" : ",");
	}
	cout << "]";
	// or you can write your assert() to validate - what you do here is 
	// completely up to you
	return 0;
}

