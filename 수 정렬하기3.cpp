#include <iostream>

using namespace std;

int main()
{
	int n, m;
	cin >> n;
	int arr[10001] = { 0, };

	for (int i = 0; i < n; ++i)
	{
		scanf("%d", &m);
		arr[m]++;
	}
	for (int i = 0; i < 10001; ++i)
		while (arr[i] != 0)
		{
			printf("%d\n", i);
			arr[i]--;
		}

	return 0;
}