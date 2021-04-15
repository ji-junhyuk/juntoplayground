#include <stdio.h>
#include "Member.h"
#include "ex04_ArrayLinkedList.h"

typedef enum {
		TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
			RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

Menu SelectMenu(void)
{
	int i, ch;
		
	char *mstring[] = 
	{
		"머리노드삽입",      "꼬리노드삽입",     "머리노드삭제",
		"꼬리노드삭제",      "선택노드출력",     "선택노드삭제",
		"번호    검색",  "이름    검색",     "모든노드출력",
		"모든노드삭제",
	};
	
	do {
		for ( i = TERMINATE; i < CLEAR; i++)
		{
			printf("(%2d) %-20.20s    ", i + 1, mstring[i]);
			if ((i % 3) == 2)
				putchar('\n');
		}
		printf("(0) 종료: ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > CLEAR);
	return (Menu)ch;
}

int main()
{
	Menu menu;
	List list;
	Initialize(&list, 30);

	do {
		Member x;
		switch (menu = SelectMenu())
		{
			case INS_FRONT:
				x = ScanMember("머리에 삽입", MEMBER_NO | MEMBER_NAME);
				InsertFront(&list, &x);
				break;

			case INS_REAR:
				x = ScanMember("꼬리에 삽입", MEMBER_NO | MEMBER_NAME);
				InsertRear(&list, &x);
				break;

			case RMV_FRONT:
				RemoveFront(&list);
				break;

			case RMV_REAR:
				RemoveRear(&list);
				break;

			case PRINT_CRNT:
				PrintLnCurrent(&list);
				break;

			case RMV_CRNT:
				RemoveCurrent(&list);
				break;

			case SRCH_NO:
				x = ScanMember("검색", MEMBER_NO);
				if (search(&list, &x, MemberNoCmp) != Null)
					PrintLnCurrent(&list);
				else
					puts("그 번호의 데이터가 없습니다.");
				break;

			case SRCH_NAME:
				x = ScanMember("검색", MEMBER_NAME);
				if (search(&list, &x, MemberNameCmp) != Null)
					PrintLnCurrent(&list);
				else
					puts("그 이름의 데이터가 없습니다.");
				break;

			case PRINT_ALL:
				Print(&list);
				break;

			case CLEAR:
				Clear(&list);
				break;
		}
	} while (menu != TERMINATE);
	Terminate(&list);

	return 0;
}
