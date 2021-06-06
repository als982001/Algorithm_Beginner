#include <stdio.h>
#include <stdlib.h>
#pragma warning(disable:4996)

int search_idx(const int a[], int n, int key, int idx[])
{
	int idx_i = 0;
	int num = 0;

	for (int i = 0; i < n; ++i)
	{
		if (a[i] == key)
		{
			idx[idx_i++] = i;
			++num;
		}
	}

	if (num == 0)
		return -1;
	return num;
}

int main()
{
	int i, nx, ky, num;
	int* x;
	int* idx_array;

	puts("선형 검색(보초법)");
	printf("요소 개수 : ");
	scanf("%d", &nx);
	x = (int*)calloc(nx + 1, sizeof(int));
	idx_array = (int*)calloc(nx + 1, sizeof(int));

	for (i = 0; i < nx; ++i)
	{
		printf("x[%d] : ", i);
		scanf("%d", &x[i]);
	}

	printf("검색값: ");
	scanf("%d", &ky);

	num = search_idx(x, nx, ky, idx_array);

	printf("\n");
	if (num == -1)
		puts("검색에 실패했습니다.");
	else
	{
		printf("배열에는 총 %d개의 %d가 있으며 \n", num, ky);
		printf("위치는 ");
		for (int i = 0; i < num; ++i)
			printf("%d ", idx_array[i]);
		printf("입니다. \n");
	}
	free(x);
	free(idx_array);
	return 0;
}