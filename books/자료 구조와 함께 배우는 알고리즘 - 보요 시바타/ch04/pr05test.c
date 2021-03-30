#include <stdio.h>
#include "pr05.h"

int main()
{
	IntQueue que;

	if (Initialize(&que, 8) == -1)
	{
		puts("failed to create que.");
		return 1;
	}
	while (1) 
	{
		int m, x;
		int idx;

		printf("data: %d / %d \n", Size(&que), Capacity(&que));
		printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Clear (7)Empty / Full (0)Exit");
		scanf("%d", &m);

		if (m == 0)
			break;
		switch (m)
		{
			case 1: 
				printf("data: "); scanf("%d", &x);
				if (Enque(&que, x) == -1)
					puts("\aerror: failed to enque.");
				break;

			case 2:
				if (Deque(&que, &x) == -1)
					puts("\aerror: failed to deque.");
				else
					printf("data: %d\n", x);
				break;

			case 3:
				if (Peek(&que, &x) == -1)
					puts("\aerror: failed to peek");
				else
					printf("peek data: %d\n", x);
				break;

			case 4:
				Print(&que);
				break;

			case 5:
				printf("data: "); scanf("%d", &x);
				if ((idx = Search(&que, x)) == -1)
					puts("\aerror: failed to search");
				else 
				{
					printf("data index: %d\n", idx);
					printf("q front behind: %d\n", Search2(&que, x));
				}
				break;

			case 6:
				Clear(&que);
				break;

			case 7:
				printf("Que is %s\n", IsEmpty(&que) ? "empty" : "not empty");
				printf("Que is %s\n", IsFull(&que) ? "full" : "not full");
				break;
		}
	}
	Terminate(&que);
	return 0;
}
