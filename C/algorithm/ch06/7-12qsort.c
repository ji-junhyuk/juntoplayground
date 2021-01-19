//
// Created by junto on 21. 1. 19..
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

int hpcmp(const Person *x, const Person *y)
{
    return x->height < y->height ? -1 :
           x->height > y->height ? 1 : 0;
}

int wpcmp(const Person *x, const Person *y)
{
    return x->weight < y->weight ? 1 :
           x->weight > y->weight ? -1 : 0;
}

void print_person(const Person x[], int no)
{
    int i;
    for (i = 0; i < no; i++)
        printf("%-10s %dcm %dkg\n", x[i].name, x[i].height, x[i].weight);
}

int main()
{
    Person x[] = {
            { "sunmi", 170, 52 },
            { "yoobin", 180, 70 },
            { "sohee", 172, 63 },
            { "jina", 165, 50 },
    };

    int nx = sizeof(x) / sizeof(x[0]); 		/* �迭 x�� ��� ���� */

    print_person(x, nx);
    putchar('\n');

    qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *)) npcmp);
    print_person(x, nx);
    putchar('\n');

    qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *)) hpcmp);
    print_person(x, nx);
    putchar('\n');

    qsort(x, nx, sizeof(Person), (int(*)(const void *, const void *)) wpcmp);
    print_person(x, nx);
    putchar('\n');

    return 0;
}