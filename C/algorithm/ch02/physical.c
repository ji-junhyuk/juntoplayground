//
// Created by junto on 21. 1. 3..
//

#include <stdio.h>
#define VMAX 21

typedef struct {
    char 	name[20];
    int 	height;
    double vision;
} PhysicalCheck;

double ave_height(const PhysicalCheck data[], int n)
{
    int i;
    double sum = 0;

    for (i = 0; i < n; i++)
        sum += data[i].height;

    return sum / n;
}

void dist_vision(const PhysicalCheck data[], int n, int dist[])
{
    int i;

    for (i = 0; i < VMAX; i++)
        dist[i] = 0;

    for (i = 0; i < n; i++)
        if (data[i].vision >= 0.0 && data[i].vision <= VMAX / 10.0)
            dist[(int)(data[i].vision * 10)]++;
}
int main(void)
{
    int i;
    PhysicalCheck x[] = {
            { "june",	162, 0.3 },
            { "jojo",	173, 0.7 },
            { "jaja",	175, 2.0 },
            { "wawa",	171, 1.5 },
            { "haha",	168, 0.4 },
            { "gogo",	174, 1.2 },
            { "zpzp",	169, 0.8 }
    };

    int nx = sizeof(x) / sizeof(x[0]);
    int vdist[VMAX];

    puts("Physical Table");
    puts("    name    height vision");
    puts("----------------------------");

    for (i = 0; i < nx; i++)
        printf("%-18.18s%4d%5.1f\n", x[i].name, x[i].height, x[i].vision);

    printf("\n average height: %5.1f cm\n", ave_height(x, nx));
    dist_vision(x, nx, vdist);

    printf("\n vision distribution\n");
    for (i = 0; i < VMAX; i++)
        printf("%3.1f ~ : %2d\n", i / 10.0, vdist[i]);

    return 0;
}