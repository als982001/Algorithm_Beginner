#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int gcd_array(const int a[], int n)
{
	int gcd = 100000000;

	for (int i = 0; i < n; ++i)
	{
		if (gcd < a[i])
			gcd = a[i];
	}

	bool finish = false;

	while (!finish && gcd > 1)
	{
		finish = true;

		for (int i = 0; i < n; ++i)
		{
			if (a[i] % gcd != 0)
			{
				finish = false;
				break;
			}
		}
		--gcd;
	}

	return gcd + 1;
}

int main()
{
	int* x;
	int n;

	printf("배열의 크기를 입력하세요: ");
	scanf("%d", &n);

	x = (int*)calloc(n + 1, sizeof(int));

	for (int i = 0; i < n; ++i)
	{
		printf("x[%d] = ", i);
		scanf("%d", &x[i]);
	}

	int gcd = gcd_array(x, n);

	printf("최대공약수는 %d입니다.\n", gcd);

	return 0;
}