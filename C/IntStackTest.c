//
// Created by junto on 12/18/20.
//

/*
#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1) {
        puts("Failed to Stack Create.");
        return 1;
    }

    while (1) {
        int menu, x;
        printf("Current number of data: %d / %d\n", Size(&s), Capacity(&s));
        printf("(1)Push (2)Pop (3)Peek (4)Print (5)Exit: ");
        scanf("%d", &menu);

        if (menu == 0) break;
        switch (menu) {
            case 1:
                printf("data:");
                scanf("%d", &x);
                if (Push(&s,x) == -1)
                    puts("\aerror: Failed to Push.");
                break;

            case 2:
                if (Pop(&s,&x) == -1)
                    puts("\aerror: Failed to Pop");
                else
                    printf("Pop data is %d.\n", x);

            case 3:
                if (Peek(&s,&x) == -1)
                    puts("\aerror: Failed to peek.");
                else
                    printf("Peek data is %d.\n", x);
                break;

            case 4:
                Print(&s);
                break;
        }
    }
    Terminate(&s);
    return 0;
}
*/
/* int�� ���� IntStack�� ��� */
#include <stdio.h>
#include "IntStack.h"

int main(void)
{
    IntStack s;
    if (Initialize(&s, 64) == -1) {
        puts("���� ������ �����Ͽ����ϴ�.");
        return 1;
    }

    while (1) {
        int menu, x;

        printf("Number of Data: %d / %d\n", Size(&s), Capacity(&s));
        printf("(1) Push (2) Pop (3) Peek (4) Print (0) Exit : ");
        scanf("%d", &menu);
        if (menu == 0) break;

        switch (menu) {
            case 1: /*--- Ǫ��---*/
                printf("data: ");
                scanf("%d", &x);
                if (Push(&s, x) == -1)
                    puts("\aerror :failed to push.");
                break;

            case 2: /*--- �� ---*/
                if (Pop(&s, &x) == -1)
                    puts("\a���� : �˿� �����Ͽ����ϴ�.");
                else
                    printf("�� �����ʹ� %d�ϴ�.\n", x);
                break;

            case 3: /*--- ��ũ ---*/
                if (Peek(&s, &x) == -1)
                    puts("\a���� : ��ũ�� �����Ͽ����ϴ�.");
                else
                    printf("��ũ �����ʹ� %d�ϴ�.\n", x);
                break;

            case 4: /*--- ��� ---*/
                Print(&s);
                break;
        }
    }

    Terminate(&s);

    return 0;
}