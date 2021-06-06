#include <stdio.h>
#pragma warning(disable:4996)

int str_cmp(const char* s1, const char* s2)
{
	while (*s1 == *s2)
	{
		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)*s2;
}

char Upper(char c)
{
	if ('a' <= c && c <= 'z')
		return c - 32;
}
int str_cmpic(const char* s1, const char* s2)
{

	while (*s1 == Upper(*s2))
	{

		if (*s1 == '\0')
			return 0;
		s1++;
		s2++;
	}
	return (unsigned char)*s1 - (unsigned char)Upper(*s2);
}

int str_ncmpic(const char* s1, const char* s2, size_t n)
{
	int times = 0;
	while (*s1 == Upper(*s2))
	{

		if (*s1 == '\0' || times >= n)
			return 0;
		s1++;
		s2++;
		++times;
	}
	return (unsigned char)*s1 - (unsigned char)Upper(*s2);
}

int main()
{
	char st[128];
	puts("\"ABCD\"와 비교합니다.");
	puts("\"XXXX\"면 종료합니다.");
	while (1)
	{
		printf("문자열 st: ");
		scanf("%s", st);
		if (str_cmpic("XXXX", st) == 0)
			break;
		printf("str_cmp(\"ABCD\", st) = %d \n", str_cmp("ABCD", st));

	}

	return 0;
}