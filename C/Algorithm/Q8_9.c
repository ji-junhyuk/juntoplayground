//
// Created by junto on 20. 12. 30..
//

#include <stdio.h>
#include <string.h>



int bf_match(const char txt[], const char pat[])
{
	int i, k = -1;
	int count = 0;
	int tlen = strlen(txt);
	int plen = strlen(pat);
	int pt = 0;
	int pp = 0;

	while (txt[pt] != '\0' && pat[pp] != '\0') {
		if (k == pt - pp)
			printf("    ");
		else {
			printf("%2d  ", pt - pp);
			k = pt - pp;
		}
		for (i = 0; i < tlen; i++)
			printf("%c ", txt[i]);
		putchar('\n');

		printf("%*s%c\n", pt * 2 + 4, "", (txt[pt] == pat[pp]) ? '+' : '|');

		printf("%*s", (pt - pp) * 2 + 4, "");
		for (i = 0; i < plen; i++)
			printf("%c ", pat[i]);
		printf("\n\n");
		count++;

		if (txt[pt] == pat[pp]) {
			pt++;
			pp++;
		}
		else {
			pt = pt - pp + 1;
			pp = 0;
		}
	}

	printf("비교를 %d회 했습니다.\n", count);
	if (pat[pp] == '\0')
		return pt - pp;
	return -1;
}

int main(void)
{
    int idx;
    char s1[256];
    char s2[256];
    puts("brute force method");

    printf("text:");
    scanf("%s", s1);
    printf("pattern: ");
    scanf("%s", s2);

    idx = bf_match(s1, s2);

    if (idx == -1)
        puts("Text has no pattern.");
    else
        printf("%d match", idx + 1);

    return 0;
}