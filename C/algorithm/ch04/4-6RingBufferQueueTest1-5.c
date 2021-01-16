//
// Created by junto on 21. 1. 5..
//

#include <stdio.h>
#include "IntQueue.h"

int main(void)
{
    IntQueue que;
    if (Initialize(&que, 64) == -1) {
        puts("Failed to create queue.");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("Number of data: %d / %d\n", Size(&que), Capacity(&que));
        printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Clear (7)Empty&Full (0)Exit: ");
        scanf("%d", &menu);

        if (menu == 0)break;
        switch (menu) {
            case 1:
                printf("data: ");
                scanf("%d", &x);
                if (Enque(&que, x) == -1)
                    puts("error: Failed to push.");
                break;

            case 2:
                if (Deque(&que, &x) == -1)
                    puts("error: Failed to pop.");
                else
                    printf("Pop data: %d\n", x);
                break;

            case 3:
                if (Peek(&que, &x) == -1)
                    puts("error: Failed to peek.");
                else
                    printf("Peek data: %d\n", x);
                break;

            case 4:
                Print(&que);
                break;

            case 5:
                printf("data: ");
                scanf("%d", &x);
                if ((idx = Search(&que, x)) == -1)
                    puts("\aError: failed to search.");
                else {
                    printf("data index: %d\n", idx);
                    printf("que front %d behind", Search2(&que, x));
                }
                break;

            case 6:
                Clear(&que);
                break;

            case 7:
                printf("Empty: %s\n", IsEmpty(&que) ? "O" : "X");
                printf("Full: %s\n", IsFull(&que) ? "0" : "X");
                break;
        }
    }
    Terminate(&que);
    return 0;
}