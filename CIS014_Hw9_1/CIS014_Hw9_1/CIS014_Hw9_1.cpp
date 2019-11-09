#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class CIS14 {
public:
	int getNumPossibleSigns(string* letterInventory, string* addresses, int length);
private:
	
};

/**
 * MEMBER FUNCTION NAME:
 *    getNumPossibleSigns
 * PURPOSE:
 *    The function takes in a series of addresses in a string array and compares each of them with the available
 *    letterInventory, returning the number of addresses that are POSSIBLE to form from the given letterInventory
 * PARAMETER:
 *    string* letterInventory
 *    string* addresses
 *    int length: length of the array, addresses[]
 * RETURN VALUE:
 *    int: the number of possible addresses that can be formed from your inventory of letters
 */
int CIS14::getNumPossibleSigns(string* letterInventory, string* addresses, int length)
{
	int count = 0;

	for (int i = 0; i < length; i++)
	{
		string tempLetters = *letterInventory; //create copy of letterInventory
		string tempAddress = addresses[i]; //create copy of address
		bool cont = true; //initialize continue flag to true

		tempAddress.erase(remove(tempAddress.begin(), tempAddress.end(), ' '), tempAddress.end()); //remove spaces from tempAddress

		for (int j = 0; j < tempAddress.length(); j++) //iterate along tempAddress
		{
			size_t found = tempLetters.find(tempAddress[j]); //find tempAddress's current char in tempLetters
			if(found != string::npos) //if found char
			{
				tempLetters.erase(tempLetters.begin() + found); //remove from inventory
			}
			else //did not find char
			{
				cont = false; //set continue flag to false for current tempAddress
				break; //exit inner loop for this address early
			}
		}
		if (cont == false) continue; //skip current address without incrementing counter

		else count++;
	}
	return count;
}

int main()
{
	string letterInventory = "99S9ABCDAAST";
	string addresses[] = { "999 S ST", "A BAD ST", "B BAD ST" };
	int length = sizeof(addresses) / sizeof(addresses[0]);

	CIS14 cis14;
	cout << cis14.getNumPossibleSigns(&letterInventory, addresses, length);
}

