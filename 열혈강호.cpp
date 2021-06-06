#include <iostream>
#include <vector>
#define MAX 1001

using namespace std;

vector<int> a[MAX];
bool check[MAX];
int pointed[MAX];

bool dfs(int s)
{
	for (int i = 0; i < a[s].size(); ++i)
	{
		int t = a[s][i];

		if (check[t])
			continue;
		check[t] = true;

		if (pointed[t] == 0 || dfs(pointed[t]))
		{
			pointed[t] = s;
			return true;
		}
	}
	return false;
}

int main()
{
	int n, m;

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		int t, cs;
		cin >> t;
		for (int j = 0; j < t; ++j)
		{
			cin >> cs;
			a[i].push_back(cs);
		}
	}

	int count = 0;
	for (int i = 1; i <= n; ++i)
	{
		fill(check, check + MAX, false);
		if (dfs(i))
			++count;
	}

	cout << count << endl;
	return 0;
}