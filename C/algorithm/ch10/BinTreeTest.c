//
// Created by junto on 21. 1. 12..
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
        printf("(1) Insert (2) Remove (3) Search (4) Print (0) Exit : ");
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
                x = ScanMember("Insert", MEMBER_NO | MEMBER_NAME);
                root = Add(root, &x);
                break;

            case REMOVE:
                x = ScanMember("Remove", MEMBER_NO);
                Remove(&root, &x);
                break;

            case SEARCH:
                x = ScanMember("Search", MEMBER_NO);
                if ((temp = Search(root, &x)) != NULL)
                    PrintLnMember(&temp->data);
                break;

            case PRINT:
                puts("Print all nodes");
                PrintTree(root);
                break;
        }
    } while (menu != TERMINATE);

    FreeTree(root);

    return 0;
}