//
// Created by junto on 12/20/20.
//

#include <stdio.h>
#include "ArrayIntQueue.h"

int main(void)
{
    IntQueue que;

    if (Initialize(&que, 64) == -1) {
        puts("failed to create que");
        return 1;
    }

    while (1) {
        int m, x;
        int idx;

        printf("data: %d, %d\n", Size(&que), Capacity(&que));
        printf("(1)Enque (2)Deque (3)Peek (4)Print (5)Search (6)Clear (7)Empty / IsFull (0)Exit: ");
        scanf("%d", &m);

        if (m == 0) break;

        switch (m) {
            case 1:
                printf("data: ");
                scanf("%d", &x);
                if (Enque(&que, x) == -1)
                    puts("\aerror: failed to Enque.");
                break;

            case 2:
                if (Deque(&que, &x) == -1)
                    puts("\aerror: failed to deque.");
                else
                    printf("deque: %d \n", x);
                break;

            case 3:
                if (Peek(&que, &x) == -1)
                    puts("\aerror: failed to peek");
                else
                    printf("Peek: %d \n", x);
                break;

            case 4:
                Print(&que);
                break;

            case 5:
                printf("Search data: ");
                scanf("%d", &x);
                if ((idx = Search(&que, x)) == -1)
                    puts("\aerror: failed to Search");
                else
                    printf("data index %d \n", idx);
                break;

            case 6:
                Clear(&que);
                break;

            case 7:
                printf("que Empty%s \n", IsEmpty(&que) ? "Yes" : "Not");
                printf("que is Full%s \n", IsFull(&que) ? "Yes" : "Not");
                break;
        }
    }
    Terminate(&que);

    return 0;
}
