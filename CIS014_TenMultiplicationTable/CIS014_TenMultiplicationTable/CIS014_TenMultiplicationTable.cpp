// CIS014_TenMultiplicationTable.cpp

#include <iostream>
#include <iomanip>
using namespace std;

void tenTable()
{
	const int numRows = 10;
	const int numCols = 10;
	int table[numRows][numCols];
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			table[i][j] = (i >= j) ? (i + 1) * (j + 1) : 0;
		}
	}
	for (int i = 0; i < numRows; i++)
	{
		for (int j = 0; j < numCols; j++)
		{
			cout << table[i][j] << " " << setw(1);
		}
		cout << endl;
	}
}

void x(int& i, int& j)
{
	i++;
	j--;
}

int main()
{
	int a = 100, b = 200;

	x(a, b);
	cout << a << " " << b << endl;
}


