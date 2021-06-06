#include <iostream>
#include <vector>
using namespace std;

int cards[100];
bool check[100];
int target[3];
int sum;

int n, m;

void Blackjack(int cur, int count)
{
	if (count == 3)
	{
		int temp = 0;

		for (int i = 0; i < 3; ++i)
		{
			temp += target[i];
		}

		if (m >= temp && temp > sum)
			sum = temp;
		return;
	}

	for (int i = cur; i < n; ++i)
	{
		if (!check[i])
		{
			target[count] = cards[i];
			check[i] = true;
			Blackjack(i + 1, count + 1);
			check[i] = false;
		}
	}
}

int main()
{
	cin >> n >> m;

	for (int i = 0; i < n; ++i)
		cin >> cards[i];

	Blackjack(0, 0);

	cout << sum << endl;

	return 0;
}