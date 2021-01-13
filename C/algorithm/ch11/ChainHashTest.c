//
// Created by junto on 21. 1. 13..
//

#include <stdio.h>
#include "Member.h"
#include "ChainHash.h"

typedef enum {
    TERMINATE, ADD, DELETE, SEARCH, CLEAR, DUMP
} Menu;

Menu SelectMenu(void)
{
    int ch;
    do {
        printf("(1)Add (2)Delete (3)Search (4)Clear (5)Dump (6)Exit: ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > DUMP);
    return (Menu) ch;
}

int main(void)
{
    Menu menu;
    ChainHash hash;
    Initialize(&hash, 13);
    do {
        int result;
        Member x;
        Node *temp;
        switch (menu = SelectMenu()) {
            case ADD:
                x = ScanMember("Add", MEMBER_NO | MEMBER_NAME);
                result = Add(&hash, &x);
                if (result)
                    printf("error: Failed to add(%s).\n",
                           (result == 1) ? "Already exist" : "Out of memory");
                break;

            case DELETE:
                x = ScanMember("Delete", MEMBER_NO);
                result = Remove(&hash, &x);
                if (result == 1)
                    printf("error: The number is not existed.\n");
                break;

            case SEARCH:
                x = ScanMember("Search", MEMBER_NO);
                temp = Search(&hash, &x);
                if (temp == NULL)
                    printf("failed to search.\n");
                else {
                    printf("succeed to search.\n");
                    PrintLnMember(&temp->data);
                }
                break;

            case CLEAR:
                Clear(&hash);
                break;

            case DUMP:
                Dump(&hash);
                break;
        }
    } while (menu != TERMINATE);
    Terminate(&hash);

    return 0;
}