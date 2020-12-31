//
// Created by junto on 20. 12. 31..
//

#include <stdio.h>
#include "Member.h"
#include "LinkedList.h"

typedef enum {
    TERMINATE, INS_FRONT, INS_REAR, RMV_FRONT, RMV_REAR, PRINT_CRNT,
    RMV_CRNT, SRCH_NO, SRCH_NAME, PRINT_ALL, CLEAR
} Menu;

Menu SelectMenu(void)
{
    int i, ch;
    char *mstring[] = {
            "Insert node in head",   "Insert node in tail",   "Delete head node",
            "Delete tail node",     "Output selected node",   "Delete selected node",
            "Search in number",          "Search to name",        "print all nodes",
            "Delete all nodes",
    };

    do {
        for (i = TERMINATE; i < CLEAR; i++) {
            printf("(%2d) %-18.18s ", i + 1, mstring[i]);
            if ((i % 3) == 2)
                putchar('\n');
        }
        printf("( 0) exit: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > CLEAR);

    return (Menu)ch;
}

int main(void)
{
    Menu menu;
    List list;

    Initialize(&list);                 /* ���� ����Ʈ�� �ʱ�ȭ */
    do {
        Member x;
        switch (menu = SelectMenu()) {
            case INS_FRONT:
                x = ScanMember("Insert to head", MEMBER_NO | MEMBER_NAME);
                InsertFront(&list, &x);
                break;

            case INS_REAR:
                x = ScanMember("Insert to tail", MEMBER_NO | MEMBER_NAME);
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
                x = ScanMember("Search", MEMBER_NO);
                if (search(&list, &x, MemberNoCmp) != NULL)
                    PrintLnCurrent(&list);
                else
                    puts("There was no number in there.");
                break;

            case SRCH_NAME:
                x = ScanMember("Search", MEMBER_NAME);
                if (search(&list, &x, MemberNameCmp) != NULL)
                    PrintLnCurrent(&list);
                else
                    puts("There was no number in there.");
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