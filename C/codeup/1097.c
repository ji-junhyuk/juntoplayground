//
// Created by junto on 21. 1. 17..
//

#include <stdio.h>

int main()
{
    int h, w, n, l, d, x, y, i, j;
    int a[101][101]={0};
    scanf("%d %d",&h,&w);
    scanf("%d",&n);

    for(i=1 ; i<=n ; i++)
    {
        scanf("%d %d %d %d",&l,&d,&x,&y);
        if(l==1)
            if(a[x][y]==0) a[x][y]=1;
        if(l!=1)
        {
            if(d==0)
                for(j=1 ; j<=l ; j++)
                    a[x][y+j-1]=1;
            else if(d==1)
                for(j=1 ; j<=l ; j++)
                    a[x+j-1][y]=1;
        }
    }

    for(i=1 ; i<=h ; i++)
    {
        for(j=1 ; j<=w ; j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
