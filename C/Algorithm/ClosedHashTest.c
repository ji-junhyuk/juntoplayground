//
// Created by junto on 20. 12. 31..
//

#include <stdio.h>
#include "Member.h"
#include "ClosedHash.h"

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
    ClosedHash hash;
    Initialize(&hash, 13);

    do {
        int result;
        Member x;
        Bucket *temp;

        switch (menu = SelectMenu()) {
            case ADD:
                x = ScanMember("ADD", MEMBER_NO | MEMBER_NAME);
                result = Add(&hash, &x);
                if (result)
                    printf("\aerror: failed to add\n",
                           (result == 1) ? "finish enroll" : "out of memory");
                break;

            case DELETE:
                x = ScanMember("delete", MEMBER_NO);
                result = Remove(&hash, &x);
                if (result == 1)
                    printf("\aerror : not exist number\n");
                break;

            case SEARCH:
                x = ScanMember("search", MEMBER_NO);
                temp = Search(&hash, &x);
                if (temp == NULL)
                    printf("\afailed to search\n");
                else {
                    printf("success to search: ");
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