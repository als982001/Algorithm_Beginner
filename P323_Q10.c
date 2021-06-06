#include <stdio.h>
#include <string.h>
#pragma warning(disable:4996)
int bf_match(const char txt[], const char pat[])
{
	int pt = 0;	// txt 커서
	int pp = 0;	// pat 커서
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			++pt;
			++pp;
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

int bf_matchr(const char txt[], const char pat[])
{
	int pt = 0;	// txt 커서
	int pp = 0;	// pat 커서
	while (txt[pt] != '\0' && pat[pp] != '\0')
	{
		if (txt[pt] == pat[pp])
		{
			++pt;
			++pp;
		}
		else
		{
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	if (pat[pp] == '\0')
		return pt - pp + strlen(pat) - 1;
	return -1;
}

int main()
{
	int idx;
	char s1[256];	// 텍스트
	char s2[256];	// 패턴
	puts("브루트-포스 법");
	printf("텍스트: ");
	scanf("%s", s1);
	printf("패턴: ");
	scanf("%s", s2);

	idx = bf_matchr(s1, s2);

	if (idx == -1)
		printf("텍스트에 패턴이 없습니다.\n");
	else
		printf("%d번째 문자부터 거꾸로 match합니다.\n", idx + 1);

	return 0;
}