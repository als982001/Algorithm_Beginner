#include <iostream>
using namespace std;

int arr[8];
bool check[8];

int n, m;

void dfs(int cnt)
{
	if (cnt == m)
	{
		for (int i = 0; i < m; ++i)
		{
			printf("%d ", arr[i]);
		}
		printf("\n");
		return;
	}

	for (int i = 1; i <= n; ++i)
	{
		check[i] = true;
		arr[cnt] = i;
		dfs(cnt + 1);
		check[i] = false;
	}
}

int main()
{
	cin >> n >> m;
	dfs(0);

	return 0;
}