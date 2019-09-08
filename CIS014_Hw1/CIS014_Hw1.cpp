// CIS014_Hw1.cpp : Andrew Lam 9-2-19
// This is a console application that takes a user's numeric "pennies" input and returns a string output (using the USD units of currency).
// The program should then convert USD to CAD.

#include <iostream>
using namespace std;
#include <math.h>

int main()
{
	const float convRate = 1.33;

	// Initializes required variables for coin types
	int pennies = 0, 
		dollars = 0,
		quarters = 0,
		dimes = 0,
		nickels = 0;

	// Takes and stores user input for total number of pennies
	cout << "Please enter all your pennies: ";
	cin >> pennies;

	// Converts US pennies to CAD
	float cad = (float(pennies) / 100) * convRate;

	// Reduces pennies to the two largest denominations available and subtracts from total penny count until pennies are less than the value of a nickel
	while (pennies > 5) {
		dollars = floor(pennies / 100);
		quarters = floor((pennies % 100) / 25);
		pennies -= (dollars * 100) + (quarters * 25);
		dimes = floor(pennies / 10);
		nickels = floor((pennies % 10) / 5);
		pennies -= (dimes * 10) + (nickels * 5);
	}

	// Prints desired monetary conversions
	cout << "In US currency you have: " << dollars << " dollars, " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies. \n";
		
	cout << "In Canadian currency you have: " << cad << " dollars. \n";

	system("PAUSE");

	return 0;
}
