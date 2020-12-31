//
// Created by junto on 20. 12. 31..
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
        printf("(1) ADD (2) Delete (3) Search (4) Clear (5) dump (0) exit : ");
        scanf("%d", &ch);
    } while (ch < TERMINATE || ch > DUMP);

    return(Menu)ch;
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
                    printf("\aerror : cannot add(%s).\n",
                           (result == 1) ? "Already added" : "short of memory");
                break;

            case DELETE:
                x = ScanMember("Delete", MEMBER_NO);
                result = Remove(&hash, &x);
                if (result == 1)
                    printf("\aerror : this number not exist.\n");
                break;

            case SEARCH: /*--- ������ �˻� ---*/
                x = ScanMember("Search", MEMBER_NO);
                temp = Search(&hash, &x);
                if (temp == NULL)
                    printf("\afailed to search.\n");
                else {
                    printf("success to search ");
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