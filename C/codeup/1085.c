//
// Created by junto on 21. 1. 14..
//

#include <stdio.h>
int main()
{
    int h,b,c,s;
    scanf("%d %d %d %d",&h,&b,&c,&s);
    printf("%0.1lf MB",(double)h*b*c*s/8/1024/1024);
    return 0;
}