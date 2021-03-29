#include <stdio.h>
#include "pr03.h"

int main(void)
{
	ArrayIntQueue que;
	if (Initialize(&que, 8) == -1)
	{
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while(1)
	{
		int menu, x;
		printf("Data: %d / %d\n", Size(&que), Capacity(&que));
		printf("(1)Push (2)Pop (3)Peek (4)Print \
			    (5)Clear (6)IsEmpty (7)IsFull (8)Search (0)Exit : ");
		scanf("%d", &menu);

		if (menu == 0)
			break;
		switch (menu)
		{
			case 1 :
				printf("data: ");
				scanf("%d", &x);
				if (Enque(&que, x) == -1)
					puts("\aerror: failed to enque.");
				break;

			case 2 :
				if (Deque(&que, &x) == -1)
					puts("\aerror: failed to deque.");
				else
					printf("pop data is %d.\n", x);
				break;

			case 3 :
				if (Peek(&que, &x) == -1)
					puts("\aerror: failed to peek.");
				else
					printf("peek data is %d.\n", x);
				break;

			case 4 :
				Print(&que);
				break;
				
			case 5 :
				Clear(&que);
				break;
				
			case 6 :
				if (!IsEmpty(&que))
					puts("비어있지 않습니다.");
				else
					puts("비어 있습니다.");
				break;

			case 7 :
				if (!IsFull(&que))
					puts("가득 차지 않았습니다.");
				else
					puts("가득 찼습니다.");

				break;

			case 8 :
				printf("data: ");
				scanf("%d", &x);
				if (Search(&que, x) == -1)
					puts("\aerror: failed to search.");
				else
					printf("search data is %d\n", x);
				break;
		}
	}
	Terminate(&que);
	return 0;
}
