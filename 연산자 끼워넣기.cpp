#include <iostream>
#include <limits.h>
using namespace std;

int opr[4]; // 순서대로 +, -, x, /
int opr_for_exp[10];
int num[11];
int n;
int mn = 2147483647;
int mx = -2147483640;

int Calculate()
{
	int res = num[0];

	for (int i = 0; i < n - 1; ++i)
	{
		if (opr_for_exp[i] == 0)
			res += num[i + 1];
		else if (opr_for_exp[i] == 1)
			res -= num[i + 1];
		else if (opr_for_exp[i] == 2)
			res *= num[i + 1];
		else if (opr_for_exp[i] == 3)
			res /= num[i + 1];
	}
	return res;
}

void Make_Exp(int cnt)
{
	if (cnt == n - 1)
	{
		int res = Calculate();
		if (res < mn)
			mn = res;
		if (res > mx)
			mx = res;
		return;
	}
	else
	{
		for (int i = 0; i < 4; ++i)
		{
			if (opr[i] > 0)
			{
				opr_for_exp[cnt] = i;
				--opr[i];
				Make_Exp(cnt + 1);
				++opr[i];
			}
		}
	}
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> num[i];
	}

	for (int i = 0; i < 4; ++i)
	{
		cin >> opr[i];
	}

	Make_Exp(0);

	cout << mx << endl << mn << endl;

	return 0;
}