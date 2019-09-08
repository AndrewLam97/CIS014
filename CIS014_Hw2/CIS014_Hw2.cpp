/**
 * CIS014_Hw2.1	Andrew Lam 9-7-19 

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
#include <string>
#include <math.h>


string breakCash(int numPennies) {
	int dollars = 0,
		quarters = 0, 
		dimes = 0, 
		nickels = 0;

	while (numPennies > 5) {
		dollars = floor(numPennies / 100);
		quarters = floor((numPennies % 100) / 25);
		numPennies -= (dollars * 100) + (quarters * 25);
		dimes = floor(numPennies / 10);
		nickels = floor((numPennies % 10) / 5);
		numPennies -= (dimes * 10) + (nickels * 5);
	}
	
	string result = "In US currency you have " + std::to_string(dollars) + " dollar(s), " + std::to_string(quarters) + " quarter(s), " + std::to_string(dimes) + " dime(s), " + std::to_string(nickels) + " nickel(s), and " + std::to_string(numPennies) + " pennie(s). \n";

	return result;	

}

int main()
{
	int numPennies = 0;
	cout << "Please enter all your pennies: ";
	cin >> numPennies;
	cout << breakCash(numPennies);
}