#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)

char Upper(char c)
{
	if ('z' >= c && c >= 'a')
		return c - 32;
	else
		return c;
}

// Compare two string regarless of size
int Str_cmpic(const char* s1, const char* s2)
{
	int len = strlen(s1) < strlen(s2) ? strlen(s1) : strlen(s2);
	char cur_s1, cur_s2;

	for (int i = 0; i < len; ++i)
	{
		cur_s1 = Upper(s1[i]);
		cur_s2 = Upper(s2[i]);

		if (cur_s1 == cur_s2)
			continue;
		else
		{
			if (cur_s1 > cur_s2)
				return 1;
			else
				return -1;
		}
	}

	return 0;
}

int STr_ncmpic(const char* s1, const char* s2, size_t n)
{
	char cur_s1, cur_s2;

	for (int i = 0; i < n; ++i)
	{
		cur_s1 = Upper(s1[i]);
		cur_s2 = Upper(s2[i]);

		if (cur_s1 == cur_s2)
			continue;
		else
		{
			if (cur_s1 > cur_s2)
				return 1;
			else
				return -1;
		}
	}

	return 0;
}

int main()
{
	char str1[100];
	char str2[100];
	int size;
	int result;

	printf("First string: ");
	scanf("%s", str1);

	printf("Second string: ");
	scanf("%s", str2);

	printf("Input size of comparing two string(0 is whole size): ");
	scanf("%d", &size);

	if (size == 0)
		result = Str_cmpic(str1, str2);
	else
		result = STr_ncmpic(str1, str2, size);

	if (result == 0)
		printf("Two strings are same.\n");
	else if (result > 0)
		printf("%s > %s \n", str1, str2);

	else
		printf("%s < %s \n", str1, str2);

	return 0;
}