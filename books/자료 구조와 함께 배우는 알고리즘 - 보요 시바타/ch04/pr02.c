#include <stdio.h>
#include "pr02.h"

int main()
{
	IntStack s;

	if (Initialize(&s, 12) == -1)
	{
		puts("failed to create stack.");
		return 1;
	}

	while (1)
	{
		int menu, x;
		int idx;

		printf("Data, A:%d B:%d / %d\n", Size(&s, StackA), Size(&s, StackB), Capacity(&s));
		printf("1)Push to A 2)A to Pop 3)A to Peek 4)Print A 5)A to Search 6)Clear A\n"
				"7)Push to B 8)B to Pop 9)B to Peek 10)Print B 11)B to Search 12)Clear B\n"
				"13)IsEmpty / IsFull 0)Exit: ");
		scanf("%d", &menu);

		if (menu == 0)
			break;

		switch (menu)
		{
			case 1: 
				printf("data: ");
				scanf("%d", &x);
				if (Push(&s, StackA, x) == -1)
					puts("\aerror: failed to push.");
				break;

			case 2:
				if (Pop(&s, StackA, &x) == -1)
					puts("\aerror: failed to pop.");
				else
					printf("Pop data: %d\n", x);
				break;

			case 3:
				if (Peek(&s, StackA, &x) == -1)
					puts("\aerror: failed to peek.");
				else
					printf("Peek data: %d\n", x);
				break;

			case 4:
				Print(&s, StackA);
				break;

			case 5:
				printf("data: ");
				scanf("%d", &x);
				if ((idx = Search(&s, StackA, x)) == -1)
					puts("\aerror: failed to search");
				else
					printf("Search data index: %d\n", idx);
				break;

			case 6:
				Clear(&s, StackA);
				break;
				
			case 7: 
				printf("data: ");
				scanf("%d", &x);
				if (Push(&s, StackB, x) == -1)
					puts("\aerror: failed to push.");
				break;

			case 8:
				if (Pop(&s, StackB, &x) == -1)
					puts("\aerror: failed to pop.");
				else
					printf("Pop data: %d\n", x);
				break;

			case 9:
				if (Peek(&s, StackB, &x) == -1)
					puts("\aerror: failed to peek.");
				else
					printf("Peek data: %d\n", x);
				break;

			case 10:
				Print(&s, StackB);
				break;

			case 11:
				printf("data: ");
				scanf("%d", &x);
				if ((idx = Search(&s, StackB, x)) == -1)
					puts("\aerror: failed to search");
				else
					printf("Search data index: %d\n", idx);
				break;

			case 12:
				Clear(&s, StackB);
				break;

			case 13:
				printf("Stack A is %s.\n", IsEmpty(&s, StackA) ? "empty" : "not empty");
				printf("Stack B is %s.\n", IsEmpty(&s, StackB) ? "empty" : "not empty");
				printf("Stack is %s.\n", IsFull(&s) ? "full" : "not full");
				break;
		}
	}
	Terminate(&s);

	return 0;
}
