//
// Created by junto on 21. 1. 5..
//

#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1) {
        puts("Failed to create stack.");
        return 1;
    }

    while (1) {
        int menu, x;
        int idx;

        printf("Number of data: %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Push (2)Pop (3)Peek (4)Print (5)Search (6)Clear (7)Full&Empty (0)Exit: ");

        scanf("%d", &menu);

        if (menu == 0) break;

        switch (menu) {
            case 1:
                printf("data: ");
                scanf("%d", &x);
                if (Push(&s, x) == -1)
                    puts("error: Failed to push.");
                break;

            case 2:
                if (Pop(&s, &x) == -1)
                    puts("error: Failed to pop.");
                else
                    printf("Pop data: %d\n", x);
                break;

            case 3:
                if (Peek(&s, &x) == -1)
                    puts("error: Failed to peek.");
                else
                    printf("Peek data: %d\n", x);
                break;

            case 4:
                Print(&s);
                break;

            case 5:
                printf("Search data: ");
                scanf("%d", &x);
                if ((idx == Search(&s, x)) == -1)
                    puts("\aerror: failed to Search/");
                else
                    printf("Search data: %d\n", idx);
                break;

            case 6:
                Clear(&s);
                break;

            case 7:
                printf("Stack is empty? %s\n", IsEmpty(&s) ? "O" : "X");
                printf("Stack is full? %s\n", IsFull(&s) ? "O" : "X");
                break;
        }
    }
    Terminate(&s);
    return 0;
}