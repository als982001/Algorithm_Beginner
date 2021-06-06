#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b)
{
	if (a.size() == b.size())
		return a < b;
	return a.size() < b.size();
}

int main()
{
	int n;
	cin >> n;
	cin.get();

	string* str = new string[n];

	for (int i = 0; i < n; ++i)
		getline(cin, str[i]);

	sort(str, str + n, compare);
	for (int i = 0; i < n; ++i)
	{
		if (i > 0 && str[i - 1] == str[i])
			continue;
		cout << str[i] << endl;
	}
	delete[] str;
	return 0;
}