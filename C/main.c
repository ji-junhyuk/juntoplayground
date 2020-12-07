#include <stdio.h>

int main()
{
    int year, mon, lastday = 0;

    printf("Enter the year: ");
    scanf("%d", &year);
    printf("Enter the mon:");
    scanf("%d", &mon);

    switch (mon)
    {
        case 1:case 3: case 5: case 7:case 8:case 10:case 12:
            lastday = 31;
            break;

        case 4: case 6: case 9: case 11:
            lastday = 30;
            break;

        case 2:
            if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
            {
                lastday = 29;
            }
            else
            {
                lastday = 28;
            }
            break;

        default:
            printf("wrong mon.");

    }

    (1 <= mon && mon <= 12) ? printf("%d year %d mon last day is %d.\n", year, mon, lastday) : printf("\n");

    return 0;
}

