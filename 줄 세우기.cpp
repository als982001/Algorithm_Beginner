#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;
int inDegree[MAX];
vector<int> a[MAX];
void topolotySort(int times)
{
	queue<int> q;
	int result[MAX];
	for (int i = 1; i <= times; ++i)
	{
		if (inDegree[i] == 0)
			q.push(i);
	}

	for (int i = 1; i <= times; ++i)
	{
		if (q.empty())
		{
			cout << "사이클이 발생했습니다.";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); ++i)
		{
			int y = a[x][i];
			if (--inDegree[y] == 0)
				q.push(y);
		}
	}
	for (int i = 1; i <= times; ++i)
	{
		cout << result[i] << " ";
	}
}

int main()
{
	int n, m;
	cin >> n >> m;
	int x, y;
	for (int i = 0; i < m; ++i)
	{
		cin >> x >> y;
		a[x].push_back(y);
		++inDegree[y];
	}
	topolotySort(n);
	return 0;
}