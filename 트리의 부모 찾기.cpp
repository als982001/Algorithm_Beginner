#include <iostream>
#include <queue>
using namespace std;

vector<int> p[100001];
queue<int> q;
vector<int> parent;
int n;

void BFS()
{
	q.push(1);

	while (!q.empty())
	{
		int cn = q.front();
		q.pop();
		for (int i = 0; i < p[cn].size(); ++i)
		{
			int nn = p[cn][i];
			if (parent[nn] == 0)
			{
				parent[nn] = cn;
				q.push(nn);
			}
		}
	}
}

int main()
{
	cin >> n;

	int a, b;
	for (int i = 1; i < n; ++i)
	{
		scanf("%d %d", &a, &b);
		p[a].push_back(b);
		p[b].push_back(a);
		parent.push_back(0);
	}
	parent.push_back(0);
	parent.push_back(0);

	BFS();

	for (int i = 2; i <= n; ++i)
	{
		printf("%d\n", parent[i]);
	}

	return 0;
}