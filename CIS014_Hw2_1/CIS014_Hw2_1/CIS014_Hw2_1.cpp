/*
* CIS014_Hw2.12	Andrew Lam 9-12-19

* NAME: currencySum
* PURPOSE: A console application that takes the user's numeric input values for the following denominations: half-dollars, quarters, dimes, nickels, and pennies.
* The application then outputs the total number of coins, their equivalency in pennies, and conversion to USD to two decimal places.
* INPUTS:
*     integers: number of each denomination
* RETURNS:
*     string:  total number of coins, their equivalency in pennies, and conversion to USD to two decimal places
*/

#include <iostream>
using namespace std;
#include <string>
#include <math.h>

int main()
{
	int numHalfs = 0,
		numQuarters = 0,
		numDimes = 0,
		numNickels = 0,
		numPennies = 0;

	cout << "Enter half dollars: ";
	cin >> numHalfs;
	cout << endl << "Enter quarters: ";
	cin >> numQuarters;
	cout << endl << "Enter dimes: ";
	cin >> numDimes;
	cout << endl << "Enter nickels: ";
	cin >> numNickels;
	cout << endl << "Enter pennies: ";
	cin >> numPennies;

	int totalCoins = numHalfs + numQuarters + numDimes + numNickels + numPennies;
	int totalPennies = (numHalfs * 50) + (numQuarters * 25) + (numDimes * 10) + (numNickels * 5) + numPennies;
	float totalUSD = float(totalPennies) / 100;

	char result[250];
	sprintf_s(result, "The value of your %d coins is equivalent to %d pennies, or $%.2f USD.", totalCoins, totalPennies, totalUSD);

	cout << endl << result;

	return 0;
}