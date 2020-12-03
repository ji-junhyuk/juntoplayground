#include <stdio.h>

int main()
{
    char alpha;

    printf("알파벳 입력: ");
    scanf("%c", &alpha);
    printf("알파벳 %d은(는) 10진수로 %d이다.", alpha, alpha);

    return 0;
}