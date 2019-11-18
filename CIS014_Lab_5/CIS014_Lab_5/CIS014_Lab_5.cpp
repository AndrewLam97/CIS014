/*
ASSIGNMENT: Lab 5
DUE: 11/17/19
PURPOSE: Finds the first occurrence of a C-style string x in s
*/

#include <iostream>
#include <cstring>
using namespace std;

/*
PURPOSE: Finds the first occurrence of a C-style string x in s
PARAMETERS: two pointers to c style strings
RETURN VALUES: integer index of s where x string is found, -1 if not found
*/
int findx(const char* s, const char* x)
{
	int xSize = strlen(x); //size of search string
	int i = 0, j = 0;
	for (i = 0; s[i] != '\0'; i++) //iterate through base string 
	{
		if (s[i] == x[j]) //look for first char match
		{
			while(x[j] != '\0' && s[i+j] == x[j]) j++; //while search string not at terminating char and chars match

			if (j == xSize) return i; //reach end of search string
			else j = 0; //reset index of search string
		}
	}
	return j == xSize ? i - j : -1; //return index of where search string is found or -1 if not found
}

int main()
{
	cout << findx("pasadena", "pas") << endl;		//0
	cout << findx("mississippi", "issip") << endl;	//4
	cout << findx("mississippi", "sippj") << endl;	//-1
	cout << findx("mississippi", "pi") << endl;		//9
	cout << findx("mississippi", "sippia") << endl; //-1
	cout << findx("aaaa", "baaa") << endl;			//-1

}

