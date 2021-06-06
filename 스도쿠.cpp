#include <iostream>
#include <vector>
using namespace std;

int sdk[10][10];
vector<pair<int, int>> v;
int check1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
int check2[10] = { 0,1, 2, 3, 4, 5, 6, 7, 8 ,9 };
int check3[10] = { 0,1, 2, 3, 4, 5, 6, 7, 8 ,9 };
int check[10];

int blanks;
bool isend;

void Print_All()
{
	for (int r = 1; r <= 9; ++r)
	{
		for (int c = 1; c <= 9; ++c)
		{
			cout << sdk[r][c] << " ";
		}
		cout << endl;
	}
}

bool Can_Fill(int r, int c, int num)
{
	for (int i = 1; i <= 9; ++i)
	{
		if (sdk[i][c] == num || sdk[r][i] == num)
		{
			return false;
		}
	}

	int pr = (r - 1) / 3, pc = (c - 1) / 3;
	for (int r = 1; r <= 3; ++r)
	{
		for (int c = 1; c <= 3; ++c)
		{
			if (sdk[pr * 3 + r][pc * 3 + c] == num)
			{
				return false;
			}
		}
	}

	return true;
}

bool Is_Completed()
{

	for (int r = 1; r <= 9; ++r)
	{
		for (int c = 1; c <= 9; ++c)
		{
			check[sdk[r][c]] += 1;
		}
	}

	for (int i = 1; i <= 9; ++i)
	{
		if (check[i] != 9)
			return false;
	}

	return true;
}

void Fill_Blank(int cnt)
{
	if (cnt == blanks)
	{
		if (Is_Completed())
		{
			Print_All();
			isend = true;
			return;
		}
	}

	else
	{
		int cr = v[cnt].first;
		int cc = v[cnt].second;

		for (int n = 1; n <= 9; ++n)
		{
			if (Can_Fill(cr, cc, n))
			{
				sdk[cr][cc] = n;
				Fill_Blank(cnt + 1);
			}
			if (isend)
				return;
			sdk[cr][cc] = 0;
		}
	}
}

int main()
{
	for (int r = 1; r <= 9; ++r)
	{
		for (int c = 1; c <= 9; ++c)
		{
			cin >> sdk[r][c];
			if (sdk[r][c] == 0)
				v.push_back(pair<int, int>(r, c));
		}
	}

	blanks = v.size();

	isend = false;
	Fill_Blank(0);

	return 0;

}