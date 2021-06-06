#include <iostream>
#include <stdlib.h>
#pragma warning(disable:4996)
using namespace std;

// 요소 개수가 n인 배열 a의 최댓값을 구합니다.
int maxof(const int a[], int n)
{
	int i;
	int max = a[0];
	for (i = 1; i < n; ++i)
		if (a[i] > max) max = a[i];
	return max;
}

int minof(const int a[], int n)
{
	int i;
	int min = a[0];
	for (i = 1; i < n; ++i)
		if (a[i] < min) min = a[i];
	return min;
}

int sumof(const int a[], int n)
{
	int sum = 0;
	for (int i = 0; i < n; ++i)
		sum += a[i];
	return sum;
}

double aveof(const int a[], int n)
{
	double total = 0;
	double num = n;

	for (int i = 0; i < n; ++i)
		total += a[i];


	return total / num;
}

int main()
{
	int i;
	int* height;
	int number;
	printf("사람 수: ");
	scanf("%d", &number);
	height = (int*)calloc(number, sizeof(int));

	printf("%d사람의 키를 입력하세요.\n", number);
	for (i = 0; i < number; ++i)
	{
		printf("height[%d] : ", i);
		scanf("%d", &height[i]);
	}

	printf("최댓값은 %d입니다.\n", maxof(height, number));
	printf("최솟값은 %d입니다.\n", minof(height, number));
	printf("총 합은 %d입니다.\n", sumof(height, number));
	printf("평균은 %lf입니다.\n", aveof(height, number));

	free(height);

	return 0;
}