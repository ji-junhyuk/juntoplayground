#include <stdio.h>
int i, j;

/*
   *
   **
   ***
   ****
   *****
*/
void triangleLB(int n)
{
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j <= i)
		{
			putchar('*');
			j++;
		}
		puts("");
		i++;
	}
	puts("");
}

/*
   *****
   ****
   ***
   **
   *
*/
void triangleLU(int n)
{
	i = 0;
	while (i < n)
	{
		j = n;
		while (j > i)
		{
			putchar('*');
			j--;
		}
		putchar('\n');
		i++;
	}
	puts("");
}

/*
   *****
    ****
	 ***
	  **
	   *
*/
void triangleRU(int n)
{
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < i)
		{
			putchar(' ');
			j++;
		}
		j = 0;
		while (j < n - i)
		{
			putchar('*');
			j++;
		}
		puts("");
		i++;
	}
	puts("");
}

/*
        *
	   **
	  ***
	 ****
	*****
*/
void triangleRB(int n)
{
	i = 0;
	while (i < n)
	{
		j = 0;
		while (j < n - i - 1)
		{
			putchar(' ');
			j++;
		}

		j = 0;
		while (j <= i)
		{
			putchar('*');
			j++;
		}
		puts("");
		i++;
	}
	puts("");
}

int main()
{
	triangleLB(5);
	triangleLU(5);
	triangleRU(5);
	triangleRB(5);
	return 0;
}
