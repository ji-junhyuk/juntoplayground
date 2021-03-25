#include <stdio.h>

int med(int a, int b, int c)
{
	if (a >= b)
		if (a <= c)
			return a; 
		else if (b >= c) 
			return b; 
		else  
			return c;
	else if (a > c)
		return a;
	else if (b < c)
		return b;
	else
		return c;
}

void main()
{
	printf("med(3,2,1): %d\n", med(3,2,1));
	printf("med(3,2,2): %d\n", med(3,2,2));
	printf("med(3,1,2): %d\n", med(3,1,2));
	printf("med(3,2,3): %d\n", med(3,2,3));
	printf("med(2,1,3): %d\n", med(2,1,3));
	printf("med(3,3,2): %d\n", med(3,3,2));
	printf("med(3,3,3); %d\n", med(3,3,3));
	printf("med(2,2,3); %d\n", med(2,2,3));
	printf("med(2,3,1); %d\n", med(2,3,1));
	printf("med(2,3,2); %d\n", med(2,3,2));
	printf("med(1,3,2); %d\n", med(1,3,2));
	printf("med(2,3,3); %d\n", med(2,3,3));
	printf("med(3,3,1); %d\n", med(3,3,1));
}
