#include <stdio.h>
#define swap(type, x, y) do {type t = x; x = y; y = t;} while (0)
int card_convr(unsigned x, int n, char d[])
{
	int i;
	char dchar[] = "0123456789abcdefghijklmnopqrstuvwxyz";
	int digits = 0; 
	if (x == 0)
		d[digits++] = dchar[0];
	else
	{
		while (x)
		{
			printf("%d|%7d ''' %d\n", n, x, x%n);
			d[digits++] = dchar[x % n];
			x /= n;
			printf(" +-------\n");
		}
	}

	i = 0;
	while (i < digits / 2)
	{
		swap(char, d[i], d[digits -i -1]);
		i++;
	}

	return digits;
}

int main()
{
	int i, cd, dno, retry;
	unsigned no;
	char cno[512];
	int a = 0;

	do {
		printf("변환하는 음이 아닌 정수: ");
		scanf("%u", &no);
		do {
			printf("어떤 진수로 변환할까요? (2-36): ");
			scanf("%d", &cd);
		} while (cd < 2 || cd > 36);

		dno = card_convr(no, cd, cno);

		i = 0;
		while (i <= dno)
		{
			printf("%c", cno[i]);
			i++;
		}
		puts("");
		printf("retry: 1\n");
		scanf("%d", &retry);
	} while (retry == 1);

	return 0;
}
