#include <stdio.h>
int card_convr(unsigned x, int n, char d[])
{
	char dchar[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int digits = 0; 
	if (x == 0)
		d[digits++] = dchar[0];
	else
		while (x)
		{
			d[digits++] = dchar[x % n];
			x /= n;
		}
	return digits;
}

int main()
{
	int i, cd, dno, retry;
	unsigned no;
	char cno[512];

	do {
		printf("변환하는 음이 아닌 정수: ");
		scanf("%u", &no);
		do {
			printf("어떤 진수로 변환할까요? (2-36): ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_convr(no, cd, cno);

		i = dno-1;
		while (i >= 0)
		{
			printf("%c", cno[i]);
			i--;
		}
		puts("");
		printf("retry: 1\n");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
