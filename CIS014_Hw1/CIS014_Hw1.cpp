// CIS014_Hw1.cpp : Andrew Lam
// This is a console application that takes a user's numeric "pennies" input and returns a string output (using the USD units of currency).
// The program should then convert USD to CAD.

#include <iostream>
using namespace std;

int main()
{
	int pennies;
	cout << "Please enter all your pennies: ";
	cin >> pennies;

	int dollars;
	int quarters;
	int dimes;
	int nickels;

	float cad = (float(pennies) / 100) * 1.33;

	while (pennies > 5) {
		dollars = floor(pennies / 100);
		quarters = floor((pennies % 100) / 25);
		pennies -= (dollars * 100) + (quarters * 25);
		dimes = floor(pennies / 10);
		nickels = floor((pennies % 10) / 5);
		pennies -= (dimes * 10) + (nickels * 5);
	}

	cout << "In US currency you have " << dollars << " dollars, " << quarters << " quarters, " << dimes << " dimes, " << nickels << " nickels, and " << pennies << " pennies. \n";

	cout << "In Canadian currency you have: " << cad << " dollars. \n";

	system("PAUSE");
	
	return 0;
}
