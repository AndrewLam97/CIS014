/*
CIS014 HW3
Andrew Lam
9-16-19
*/

#include <iostream>
using namespace std;
#include <string>

string separateLetters(string input)
{
	int aCounter = 0;

	for (int i = 0; i < input.length(); i++)
	{
		if (input[i] == 'a')
		{
			aCounter++;
		}
	}
	cout << endl << aCounter;
	string result = "";

	for (int j = 0; j < aCounter; j++)
	{
		result += "a";
	}

	for (int k = input.length() - aCounter; k > 0; k--)
	{
		result += "b";
	}
	
	return result;
}

int main()
{
	cout << "aaabababbba" << endl;
	cout << separateLetters("aaabababbba");
}