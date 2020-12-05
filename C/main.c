#include <stdio.h>

int main()
{
    int score;
    char grade;
    printf("enter the score:");
    scanf("%d", &score);

    switch (score/10) {
        case 10:
        case 9:
            printf("grade: 'A'\n");
            printf("Your %d score is %c credit.", score, grade);
            break;
        case 8:
            printf("grade: B\n");
            break;
        case 7:
            printf("grade: C\n");
            break;
        default:
            printf("grade: D");
    }


/*   int score;
   char grade;

    printf("enter the score:");
    scanf("%d", &score);

    if (score >= 90) {
        grade = 'A';
    } else if (score >= 80) {
        grade = 'B';
    } else if (score >= 70) {
        grade = 'C';
    } else {
        grade = 'D';
    }

    printf("Your %d score is %c credit.", score, grade);

    return 0;*/
}