#include <stdio.h>
#include <string.h>

int bf_match(const char txt[], const char pat[])
{
	int txt_len = strlen(txt);
	int pat_len = strlen(pat);
	int pt = txt_len - pat_len;
	int pp;

	while (pt >= 0)
	{
		pp = 0;
		while (txt[pt] == pat[pp])
		{
			if (pp == pat_len - 1)
				return pt - pp;
			pp++;
			pt++;
		}
		pt = pt - pp - 1;
	}
	return -1;
}

int main()
{
	int idx;
	char s1[256];
	char s2[256];
	printf("txt: ");
	scanf("%s", s1);
	printf("pat: ");
	scanf("%s", s2);
	idx = bf_match(s1, s2);
	if (idx == -1)
		puts("no pattern");
	else
		printf("%d 문자부터 match.\n", idx + 1);

	return 0;
}
