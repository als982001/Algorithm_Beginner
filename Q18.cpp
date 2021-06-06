#include <iostream>
using namespace std;

void nrpira(int n);

int main()
{
	nrpira(4);

	return 0;
}

void nrpira(int n)
{
	int total = n;
	int spacing_num = 0;

	for (int i = 1; i <= n; ++i, ++spacing_num, --total)
	{
		for (int spacing = spacing_num; spacing > 0; --spacing)
			printf(" ");
		for (int cur = 2 * total - 1; cur > 0; --cur)
			printf("%d", i);
		for (int spacing = spacing_num; spacing > 0; --spacing)
			printf(" ");
		printf("\n");
	}
}