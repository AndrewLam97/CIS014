#include <iostream>
#include <string>

using namespace std;

int main()
{
	char arr[128];
	for (int i = 0; i < 128; i++)
	{
		arr[i] = i;
	}

	string str = " PoT A TOo";

	for (int i = 0; i < 128; i++)
	{
		int count = 0;
		for (int j = 0; j < str.length(); j++)
		{
			if (arr[i] == str[j])
				count++;
		}
		if (count != 0)
		{
			cout << arr[i] << ": " << count << endl;
		}
	}
}


