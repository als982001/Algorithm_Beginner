#include <stdio.h>
#pragma warning(disable:4996)

int gcd(int x, int y)
{
	for (int g = x <= y ? x : y; g > 1; --g)
	{
		if (x % g == 0 && y % g == 0)
			return g;
	}
}

int main()
{
	int x, y;
	puts("두 정수의 최대공약수를 구합니다.");
	printf("정수를 입력하세요: ");
	scanf("%d", &x);

	printf("정수를 입력하세요: ");
	scanf("%d", &y);

	printf("최대공약수는 %d입니다. \n", gcd(x, y));

	return 0;
}