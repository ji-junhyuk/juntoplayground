//
// Created by junto on 21. 1. 17..
//

#include "stdio.h"

int main()
{
    int map[11][11];
    int x, y;

    for(y=1; y<=10; y++)
        for(x=1; x<=10; x++)
            scanf("%d", &map[y][x]);

    x=y=2;

    while(1)
    {
        if(map[y][x]==2) {
            map[y][x]=9;
            break;
        }

        map[y][x]=9;

        if(map[y][x+1]==0 || map[y][x+1]==2) x++;
        else if(map[y][x+1]==1) {
            if(map[y+1][x]==0 || map[y+1][x]==2) y++;
            else break;
        }
    }

    for(y=1; y<=10; y++) {
        for(x=1; x<=10; x++) {
            printf("%d ", map[y][x]);
        }
        puts("");
    }
}
