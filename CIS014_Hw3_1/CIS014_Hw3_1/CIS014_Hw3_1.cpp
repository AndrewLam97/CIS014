/*
 *	CIS014 HW3.1
 *	Andrew Lam
 *	DUE: 9-22-19
 *	PURPOSE: Determine whether or not you are always the winner given n starting quantity of pebbles
 *  RULES: Must remove 1 to 4 pebbles, user goes first, person to remove last pebble wins
 */
#include <iostream>
using namespace std;

/*
 *  NAME: CanIAlwaysWin
 *	PURPOSE: This function determines whether it is possible to always win the game of nim given a starting n quantity of pebbles
 *	PARAMETERS: integer n containing the starting quantity of pebbles
 *	RETURN VALUES: bool true or false
 */
bool CanIAlwaysWin(int n)
{
	if (n % 5 == 0) {
		return false;
	}
	else
	{
		return true;
	}
}

int main()
{
	int n = 0;
	cout << "Enter # of pebbles: \n";
	cin >> n;
	cout << "\nCan I always win: " << CanIAlwaysWin(n);
	
	return 0;
}

/* 
 *  TEST CASE
 * 
 *  Enter # of pebbles:
 *  43
 *  Can I always win: 1
 *
 * Enter # of pebbles:
 * 25
 * Can I always win: 0
 */