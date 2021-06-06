#include <iostream>
using namespace std;

int n;
int arr[1000];

void Sort(int start, int end)
{
	if (start >= end)
		return;

	int pivot = start;
	int front = start + 1;
	int back = end;
	int temp;

	while (front <= back)
	{
		while (front <= end && arr[front] <= arr[pivot])
			++front;

		while (back > start && arr[back] >= arr[pivot])
			--back;

		if (front > back)
		{
			temp = arr[back];
			arr[back] = arr[pivot];
			arr[pivot] = temp;
		}
		else
		{
			temp = arr[front];
			arr[front] = arr[back];
			arr[back] = temp;
		}
	}

	Sort(start, back - 1);
	Sort(back + 1, end);
}

int main()
{
	cin >> n;

	for (int i = 0; i < n; ++i)
		cin >> arr[i];

	Sort(0, n - 1);

	for (int i = 0; i < n; ++i)
		cout << arr[i] << endl;

	return 0;
}