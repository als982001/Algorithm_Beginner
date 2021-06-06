#include <iostream>
using namespace std;

void spira(int n);

int main()
{
	spira(4);

	return 0;
}

void spira(int n)
{
	int cur = n;
	int spacing_num = n - 1;

	for (int i = 1; i <= n; ++i, --spacing_num)
	{
		for (int spacing = spacing_num; spacing > 0; --spacing)
			printf(" ");
		for (cur = 2 * i - 1; cur > 0; --cur)
			printf("*");
		for (int spacing = spacing_num; spacing > 0; --spacing)
			printf(" ");
		printf("\n");
	}
}