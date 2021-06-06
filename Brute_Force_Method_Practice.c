#include <stdio.h>
#pragma warning(disable:4996)

// Function that search string with brute force method
int Bf_match(const char txt[], const char pat[])
{
	int pt = 0;	// txt cursor
	int pp = 0;	// pat cursor
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			pt++;
			pp++;
		}
		else
		{
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}

int main()
{
	int idx;
	char s1[256];
	char s2[256];
	printf("Text: ");
	scanf("%s", s1);
	printf("Pattern: ");
	scanf("%s", s2);

	idx = Bf_match(s1, s2);
	if (idx == -1)
		puts("There is no pattern in text.");
	else
		printf("Match from %dth letter \n", idx);

	return 0;
}