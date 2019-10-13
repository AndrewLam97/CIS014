/*
 Assignment 5.2
 DUE: 10/6/19
 PURPOSE: determine secret message by taking the first letter of each word in a string
*/

#include <iostream>
using namespace std;

/**
* FUNCTION SIGNATURE: string getSecretMessage(string str)
 * PURPOSE: get secret message by taking the first character from each word in the input sentence, in the order they appear
 * PARAMETER:
 *     str, the input sentence
 * RETURN VALUE:
 *     The secret message
*/
string getSecretMessage(string str)
{
	char temp = ' ';
	bool hasSpace = true;
	string result = "";
	for (int i = 0; i < str.length(); i++) //iterate along string
	{
		if (str[i] == ' ') //encounter space
		{
			hasSpace = true;
		}
		if (hasSpace == true && str[i] != ' ') //check for previous space encounter and not currently on a space
		{
			result += str[i]; //add char to result string
			hasSpace = false; //set space flag to false
		}
	}
	return result;
}

int main()
{
	string str = "P A SA A DENA E NA A";
	cout << "String: " << str << endl;
	cout << getSecretMessage(str) << endl;
}
/*
TEST CASES
String:       pasadena city        college
pcc

String: pasadena
p

String:


String: professor can code
pcc

String: P A SA A DENA E NA A
PASADENA
*/
