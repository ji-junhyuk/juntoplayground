//
// Created by junto on 20. 12. 31..
//

/* �����˻�Ʈ���� ����ϴ� ���α׷� */
#include <stdio.h>
#include "Member.h"
#include "BinTree.h"

typedef enum {
    TERMINATE, ADD, REMOVE, SEARCH, PRINT
} Menu;

Menu SelectMenu(void)
{
    int ch;
    do {
        printf("(1) Insert (2) delete (3) search (4) print (0) exit : ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > PRINT);
    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    BinNode *root = NULL;
    do {
        Member x;
        BinNode *temp;
        switch (menu = SelectMenu()) {

            case ADD:
                x = ScanMember("insert", MEMBER_NO | MEMBER_NAME);
                root = Add(root, &x);
                break;

            case REMOVE:
                x = ScanMember("delete", MEMBER_NO);
                Remove(&root, &x);
                break;

            case SEARCH:
                x = ScanMember("search", MEMBER_NO);
                if ((temp = Search(root, &x)) != NULL)
                    PrintLnMember(&temp->data);
                break;

            case PRINT:
                puts("Print all node");
                PrintTree(root);
                break;
        }
    } while (menu != TERMINATE);

    FreeTree(root);

    return 0;
}
