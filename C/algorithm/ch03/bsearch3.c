//
// Created by junto on 21. 1. 4..
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[10];
    int height;
    int weight;
} Person;

int npcmp(const Person *x, const Person *y)
{
    return strcmp(x->name, y->name);
}

int main(void)
{
    Person x[] = {
            {"Anna",   170, 55},
            {"Bazil",  180, 70},
            {"Corona", 188, 95},
            {"Fog",    160, 45},
            {"July",   168, 51},
    };

    int nx = sizeof(x) / sizeof(x[0]);
    int retry;
    puts("Search to name");
    do {
        Person temp, *p;
        printf("name: ");
        scanf("%s", temp.name);

        p = bsearch(&temp, x, nx, sizeof(Person),
                    (int (*)(const void *, const void *)) npcmp);

        if (p == NULL)
            puts("Failed to search.");
        else {
            puts("Search success!");
            printf("x[%d]: %s %dcm %dkg\n",
                   (int) (p - x), p->name, p->height, p->weight);
        }
        printf("Retry? 1. Yes 0. No");
        scanf("%d", &retry);
    } while (retry == 1);

    return 0;
}