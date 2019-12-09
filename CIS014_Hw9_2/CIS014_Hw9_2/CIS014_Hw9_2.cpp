/*
Assignment 9.2
Due: 11/10/19
Purpose:  takes an input string and a dictionary of English words, and checks to see if the given input is composed of only the words from the input dictionary
*/

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;

class CIS14 {
public:
	bool isInputInDictionary(string* s, unordered_set<string>& dict);
	bool isInDict(string prefix, unordered_set<string>& dict);
};

/*
PURPOSE: Takes an input string and a dictionary of English words, and checks to see if the given input is composed of only the words from the input dictionary
PARAMETERS: input string pointer and reference of input dictionary
RETURN VALUES: boolean 
*/
bool CIS14::isInputInDictionary(string* s, unordered_set<string>& dict)
{
	if (s->size() == 0)  return true; //Base case for recursion

	for (int i = 1; i <= s->size(); i++) //Iterate along input string length, create prefixes of every possible size
	{
		if (isInDict(s->substr(0, i), dict) && isInputInDictionary(&s->substr(i, s->size() - i), dict)) //First check if prefix substring is in dictionary, then recursively check
			return true;																				//for remaining substrings with increasing size
	}
	return false; //If no prefixes match dict strings
}

/*
PURPOSE: Determines presence of prefix string in dictionary
PARAMETERS: search string prefix and string unordered set dict
RETURN VALUES: boolean indicating presence of string in dict
*/
bool CIS14::isInDict(string prefix, unordered_set<string>& dict)
{
	unordered_set<string>::const_iterator found = dict.find(prefix); //store find() iterator for prefix substring in dict
	if (found == dict.end()) return false; //iterator at the end signifies prefix not found
	else return true; //prefix found
}

int main()
{
	CIS14 cis14;
	string input = "hellonowl";
	unordered_set<string> dict = { "hell", "on", "owl" };

	cout << cis14.isInputInDictionary(&input, dict);
}
