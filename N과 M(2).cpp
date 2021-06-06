#include <iostream>
#include <algorithm>
using namespace std;

int arr[8];
bool check[9];

int n, m;

void dfs(int num, int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			cout << arr[i] << " ";
		}
		cout << endl;
		return;
	}

	for (int i = num; i <= n; ++i)
	{
		if (!check[i])
		{
			check[i] = true;
			arr[cnt] = i;
			dfs(i + 1, cnt + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;
	dfs(1, 0);
}