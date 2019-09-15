	/**
 * CIS014_Hw2.1
 * Andrew Lam
 * 9-7-19
 *
 * FUNCTION NAME: breakCash
 * PURPOSE: the function takes in the total of pennies from the user as input, computes its equivalent in
 * dollars, quarters, dimes, nickels, and pennies, and outputs the result in string to the console
 * PARAMETER:
 *     int numPennies
 * RETURN VALUE:
 *     string: result in dollars, quarters, dimes, nickels, and pennies
 * FUNCTION SINGATURE:
 * string breakCash(int numPennies)
 */

#include <iostream>
using namespace std;
#include <string>
#include <math.h>


string breakCash(int numPennies) { //breakCash function takes number of pennies and returns a string
	int numDollars = 0,
		numQuarters = 0,
		numDimes = 0,
		numNickels = 0;

	float numCad = numPennies * 0.0133; //USD to CAD conversion

	while (numPennies > 5) { //calculates maximum largest denomination and subtracts from numPennies
		numDollars = floor(numPennies / 100);
		numQuarters = floor((numPennies % 100) / 25);
		numPennies -= (numDollars * 100) + (numQuarters * 25);
		numDimes = floor(numPennies / 10);
		numNickels = floor((numPennies % 10) / 5);
		numPennies -= (numDimes * 10) + (numNickels * 5);
	}

	char result[150]; //constructs string buffer for return
	sprintf(result, "In US currency you have: %d dollars, %d quarters, %d dimes, %d nickels, and %d pennies. \nIn Canadian currency you have %.2f dollars. \n", numDollars, numQuarters, numDimes, numNickels, numPennies, numCad);

	return result;
}

int main()
{
	int numPennies = 0;
	cout << "Please enter all of your pennies: ";
	cin >> numPennies;
	cout << breakCash(numPennies);
	return 0;
}
