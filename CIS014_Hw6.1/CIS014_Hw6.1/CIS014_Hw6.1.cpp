/*
Assignment 6.1
Due: 10/13/19
Purpose: Shift elements to the right in an array
*/
#include <iostream>
using namespace std;

/*
PURPOSE: Simulate the effect of a circular array, shift elements of an array of size N, to the right by M elements using cyclic replacement
PARAMETERS: integer array arr, integer N size of array, integer M desired shift
RETURN VALUES: none, array passed by pointer
*/
void rightShiftElements(int arr[], int N, int M)
{
	if (M > N)
	{
		M %= N;
	}

	int count = 0;
	for (int i = 0; count < N; i++) { //loop through array
		int current = i;
		int previous = arr[i];

		do {
			int shift = (current + M) % N; //calculate shift index
			int temp = arr[shift]; //store temp value

			arr[shift] = previous; //place values
			previous = temp;
			current = shift;
			count++;
		} while (i != current);//exit inner loop when we reach original number index
	}
}

int main()
{
	int arr[] = { 1, 2, 3, 4, 5, 6 };
	int size = sizeof(arr) / sizeof(arr[0]);

	rightShiftElements(arr, size, 3);

	cout << "[";
	for (int i = 0; i < size; i++) {
		cout << arr[i]; cout << ((i == size - 1) ? "" : ",");
	}
	cout << "]";
	// or you can write your assert() to validate - what you do here is
	// completely up to you
	return 0;
}

/*
TEST CASES
arr = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34,35,36,37,38,39,40,41,42,43,44,45 }
M = 56
Output: [35,36,37,38,39,40,41,42,43,44,45,1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,28,29,30,31,32,33,34]

arr = { 1, 2, 3, 4, 5, 6, 7, 8 }
M = 141
Output: [4,5,6,7,8,1,2,3]

arr = { 1, 2, 3, 4, 5 }
M = 2
Output: [4,5,1,2,3]

arr = { 1 }
M = 99
Output: [1]
*/
