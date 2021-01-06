//
// Created by junto on 21. 1. 6..
//

#include <stdio.h>

void recur(int n)
{
    if (n > 0) {
        recur(n - 1);
        printf("%d\n", n);
        recur(n - 2);
    }
}

int main(void)
{
    int x;
    printf("Enter the number:");
    scanf("%d", &x);
    recur(x);

    return 0;
}

/*
 * Top-down analysis
 * x = 4
 * recur(4)
 * recur(3) 4 recur(2)
 * recur(2) 3 recur(1) 4 recur(2)
 * recur(1) recur(0) 2 3 recur(1) 4 recur(2)
 * recur(0) 1 2 3 recur(1) 4 recur(2)
 * 1 2 3 1 4 recur(1) 2 recur(0)
 * 1 2 3 1 4 recur(0) 1 2
 * 1 2 3 1 4 1 2
 *
 * Bottom-up analysis
 * recur 0
 * recur(1) = 1
 * recur(2) = recur(1) 2 = 1, 2
 * recur(3) = recur(2) 3 recur(1) = 1,2,3,1
 * recur(4) = recur(3) 4 recur(2) = 1,2,3,1,4,1,2
*/


