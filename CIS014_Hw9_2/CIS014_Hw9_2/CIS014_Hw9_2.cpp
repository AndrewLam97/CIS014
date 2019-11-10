#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;


class CIS14 {
public:
	bool isInputInDictionary(string* s, unordered_set<string>& dict);
};

bool CIS14::isInputInDictionary(string* s, unordered_set<string>& dict)
{
	int length = dict.size();

	if (s->size() == 0)
	{
		return false;
	}
	for (int i = 0; i <= s->size(); i++)
	{
		// consider all prefixes of current string
		string prefix = s->substr(0, i);

		// if the prefix is present in the dictionary, add prefix to the 
		// output string and recur for remaining string

		if (find(dict.begin(), dict.end(), prefix) != dict.end())
			isInputInDictionary(&s->substr(i), dict);
	}
}

int main()
{
	CIS14 cis14;
	string input = "joe";
	unordered_set<string> dict = { "joe1", "joe" };

	cout << cis14.isInputInDictionary(&input, dict);
}
