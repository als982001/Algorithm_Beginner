#include <iostream>
#include <vector>
using namespace std;

int team_check[21]; // 1이면 스타트, 0이면 링크
int s[21][21];
int n;
int mn = 100000000;

void Make_Team(int idx, int cnt)
{
	if (cnt > (n / 2))
	{
		vector<int> team_start;
		vector<int> team_link;
		int start_pwr = 0, link_pwr = 0;
		int res = 0;

		for (int i = 1; i <= n; ++i)
		{
			if (team_check[i] == 1)
				team_start.push_back(i);
			else
				team_link.push_back(i);
		}

		for (int a = 0; a < (n / 2); ++a)
		{
			for (int b = 0; b < (n / 2); ++b)
			{
				start_pwr += s[team_start[a]][team_start[b]];
				link_pwr += s[team_link[a]][team_link[b]];
			}
		}
		res = abs(start_pwr - link_pwr);
		if (res < mn)
			mn = res;
		return;
	}

	else
	{
		for (int i = idx; i <= n; ++i)
		{
			if (team_check[i] == 1)
				continue;
			else
			{
				team_check[i] = 1;
				Make_Team(i, cnt + 1);
				team_check[i] = 0;
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= n; ++c)
		{
			scanf("%d", &s[r][c]);
		}
	}

	Make_Team(1, 1);

	printf("%d", mn);
	return 0;
}