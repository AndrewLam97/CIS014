#include <iostream>
using namespace std;

class CIS14 {
public:
	int reverseInt(int input);
	bool reverseValid(int input);
};

/*
PURPOSE:
PARAMETERS:
RETURN VALUES:
*/
int CIS14::reverseInt(int i)
{
	int temp = 0, newNum = 0;
	while (i > 0)
	{
		temp = i % 10;
		newNum *= 10;
		newNum = temp * 10;
	}
}

/*
PURPOSE: Checks validity of reversed integer as compared to int max
PARAMETERS:
RETURN VALUES:
*/
bool CIS14::reverseValid(int i)
{

}

int main()
{
	int input = 1234;
	CIS14 cis14;
	cout << cis14.reverseInt(input);
}

