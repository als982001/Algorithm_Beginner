#include <iostream>
using namespace std;

int n, m, target;
int a[100000];
int answer[100000];

void QuickSort(int front, int end)
{
	if (front >= end)
		return;

	int key = front;
	int left = front + 1;
	int right = end;
	int temp;

	while (left <= right)
	{
		while (left <= end && a[left] <= a[key])
			++left;
		while (right > front && a[right] >= a[key])
			--right;

		if (left > right)
		{
			temp = a[right];
			a[right] = a[key];
			a[key] = temp;
		}
		else
		{
			temp = a[left];
			a[left] = a[right];
			a[right] = temp;
		}
	}

	QuickSort(front, right - 1);
	QuickSort(right + 1, end);
}

int Binary_Search(int front, int end, int target)
{
	if (front > end)
		return -1;
	int mid = (front + end) / 2;

	if (a[mid] == target)
		return mid;
	else if (a[mid] > target)
		return Binary_Search(front, mid - 1, target);
	else
		return Binary_Search(mid + 1, end, target);

}

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; ++i)
		scanf("%d", &a[i]);
	QuickSort(0, n - 1);

	scanf("%d", &m);
	for (int i = 0; i < m; ++i)
	{
		scanf("%d", &target);
		if (Binary_Search(0, n - 1, target) != -1)
			answer[i] = 1;
		else
			answer[i] = 0;
	}

	for (int i = 0; i < m; ++i)
		printf("%d \n", answer[i]);

	return 0;
}