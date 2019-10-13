/*
Assignment 6.2
DUE: 10/13/19
PURPOSE: Simulate ++N by taking a vector representation of a number and incrementing it by one
*/

#include <iostream>
#include <vector>
//#include <assert.h>
using namespace std;

/*
PURPOSE: Simulate ++N by taking a vector representation of a number and incrementing it by one
PARAMETERS: vector v containing number
RETURN VALUES: vector v incremented by 1
*/
vector<int> plusPlusN(vector<int> v)
{
	bool carry = true;
	for (int i = v.size() - 1; i >= 0; i--)
	{
		if (carry == true)
		{
			v[i]++;
			carry = false; //reset flag
			if (v[0] == 10)//handles creation of new element
			{
				v[0] = 1;
				v.emplace_back(0);
				break;
			}
			if (v[i] == 10) { //if current element is 10
				carry = true; //carry flag
				v[i] = 0;//set place value to 0
			}
		}
	}
	return v;
}


int main()
{
	vector<int> v { 9,5,2,9,9 };

	vector <int> retVal = plusPlusN(v);
	vector <int> expected = { 9,5,3,0,0 };

	//assert(equal(retVal.begin(), retVal.end(), expected.begin()) == true);

	cout << "[";
	for (int i = 0; i < retVal.size(); i++) {
		cout << retVal[i]; cout << ((i == retVal.size() - 1) ? "" : ",");
	}
	cout << "]";

	return 0;
}

/*
TEST CASES
v = { 1, 2 }
Output: [1,3]

v = { 9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9,9 }
Output: [[1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0]]

v = { 9,2,3,9 }
Output: [9,2,4,0]

v = { 2,9,9 }
Output: [3,0,0]

v = { 9,9,9,9 }
Output: [1,0,0,0,0]
*/