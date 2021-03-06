#include <stdio.h>
#include "ex01_IntStack.h"

int main(void)
{
	IntStack s;
	if (Initialize(&s, 8) == -1)
	{
		puts("스택 생성에 실패하였습니다.");
		return 1;
	}

	while(1)
	{
		int menu, x;
		printf("현재 데이터 수: %d / %d\n", Size(&s), Capacity(&s));
		printf("(1)푸시 (2)팝 (3)피크 (4)출력 \
			    (5)Clear (6)IsEmpty (7)IsFull (8)Search (0)종료 : ");
		scanf("%d", &menu);

		if (menu == 0)
			break;
		switch (menu)
		{
			case 1 :
				printf("data: ");
				scanf("%d", &x);
				if (Push(&s, x) == -1)
					puts("\aerror: failed to push.");
				break;

			case 2 :
				if (Pop(&s, &x) == -1)
					puts("\aerror: failed to pop.");
				else
					printf("pop data is %d.\n", x);
				break;

			case 3 :
				if (Peek(&s, &x) == -1)
					puts("\aerror: failed to peek.");
				else
					printf("peek data is %d.\n", x);
				break;

			case 4 :
				Print(&s);
				break;
				
			case 5 :
				Clear(&s);
				break;
				
			case 6 :
				if (!IsEmpty(&s))
					puts("비어있지 않습니다.");
				else
					puts("비어 있습니다.");
				break;

			case 7 :
				if (!IsFull(&s))
					puts("가득 차지 않았습니다.");
				else
					puts("가득 찼습니다.");

				break;

			case 8 :
				printf("data: ");
				scanf("%d", &x);
				if (Search(&s, x) == -1)
					puts("\aerror: failed to search.");
				else
					printf("search data is %d\n", x);
				break;
		}
	}
	Terminate(&s);
	return 0;
}
