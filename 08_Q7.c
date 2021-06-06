#include <stdio.h>
#pragma warning(disable:4996)

int Str_ncmp(const char* s1, const char* s2, size_t n)
{
	int i;
	for (i = 0; i < n; ++i)
	{
		if (s1[i] == s2[i])
			continue;
		else
		{
			if (s1[i] < s2[i])
				return -1;
			else
				return 1;
		}
	}
	return 0;
}

int main()
{
	char str1[128];
	char str2[128];
	int size;

	printf("First string: ");
	scanf("%s", str1);

	printf("Second string: ");
	scanf("%s", str2);

	printf("Input size of compareing two string(0 is whole size): ");
	scanf_s("%d", &size);

	int result = Str_ncmp(str1, str2, size);

	if (result == 0)
		printf("Two strings are same. \n");
	else if (result < 0)
		printf("%s < %s.\n", str1, str2);
	else
		printf("%s > %s \n", str1, str2);

	return 0;
}