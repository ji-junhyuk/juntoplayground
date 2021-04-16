#include <stdio.h>
#include "../ch09/Member.h"
#include "ex01_BinTree.h"

typedef enum {
	TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

Menu SelectMenu(void)
{
	int ch;
	do {
		printf("(1)삽입 (2)삭제 (3)검색 (4)출력 (0)종료: ");
		scanf("%d", &ch);
	} while (ch < TERMINATE || ch > PRINT);
	return (Menu)ch;
}

int main(void)
{
	Menu menu;
	t_btree *root = NULL;	
	do {
		Member x;
		t_btree *temp;
		switch (menu = SelectMenu()) {
		
		case ADD:
			x = ScanMember("삽입", MEMBER_NO | MEMBER_NAME);
			root = Add(root, &x);
			break;
		
		case REMOVE:
			x = ScanMember("삭제", MEMBER_NO);
			Remove(&root, &x);
			break;
		
		case SEARCH:
			x = ScanMember("검색", MEMBER_NO);
			if ((temp = Search(root, &x)) != NULL)
				PrintLnMember(&temp->data);
			break;
		
		case PRINT:
			puts("모든 노드 출력");
			PrintTree(root);
			break;
		}
	} while (menu != TERMINATE);

	FreeTree(root);
	
	return 0;
}
