#include <stdio.h>
#include "pr06.h"

int main()
{
	IntDequeue que;

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
		printf("(1)Enque front  (2)Deque front (3)Peek front (4)Print (5)Enque rear (6)Deque rear (7)Peek rear (8)Search (9)Clear (10)Empty/Full (0)Exit");
		scanf("%d", &m);

		if (m == 0)
			break;
		switch (m)
		{
			case 1: 
				printf("data: "); scanf("%d", &x);
				if (EnqueFront(&que, x) == -1)
					puts("\aerror: failed to enque.");
				break;

			case 2:
				if (DequeFront(&que, &x) == -1)
					puts("\aerror: failed to deque.");
				else
					printf("data: %d\n", x);
				break;

			case 3:
				if (PeekFront(&que, &x) == -1)
					puts("\aerror: failed to peek");
				else
					printf("peek data: %d\n", x);
				break;

			case 4:
				Print(&que);
				break;

			case 5:
				printf("data: "); scanf("%d", &x);
				if (EnqueRear(&que, x) == -1)
					puts("\aerror: failed to enque.");
				break;

			case 6:
				if (DequeRear(&que, &x) == -1)
					puts("\aerror: failed to deque.");
				else
					printf("deque data: %d\n", x);
				break;

			case 7:
				if (PeekRear(&que, &x) == -1)
					puts("\aerror: failed to peek");
				else
					printf("peek data: %d\n", x);
				break;

			case 8:
				printf("data: "); scanf("%d", &x);
				if ((idx = Search(&que, x)) == -1)
					puts("\aerror: failed to search");
				else
				{
					printf("data index: %d\n", idx);
					printf("front behind: %d\n", Search2(&que, x));
				}
				break;

			case 9:
				Clear(&que);
				break;

			case 10:
				printf("Que is %s.\n", IsEmpty(&que) ? "empty" : "not empty");
				printf("Que is %s.\n", IsFull(&que) ? "full" : "not full");
				break;
		}
	}
	Terminate(&que);
	return 0;
}
