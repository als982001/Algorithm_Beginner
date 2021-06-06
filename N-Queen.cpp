#include <iostream>
using namespace std;

int col[16];
int n;
int times = 0;

bool 둘수있나(int q)
{
	for (int i = 1; i < q; ++i)
	{
		if (col[i] == col[q] || abs(col[q] - col[i]) == q - i)
			return false;
	}
	return true;
}

void Place_Queen(int cnt)
{
	if (cnt == n + 1)
	{
		++times;
	}
	else
	{
		for (int i = 1; i <= n; ++i)
		{
			col[cnt] = i;
			if (둘수있나(cnt))
			{
				Place_Queen(cnt + 1);
			}
		}
	}
		
}
int main()
{
	cin >> n;

	Place_Queen(1);
	cout << times << endl;

	return 0;
}