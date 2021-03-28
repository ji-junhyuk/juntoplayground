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

int main()
{
	Person x[] = {
		{"김영준", 179, 79},
		{"정상갈", 177, 75},
		{"이수진", 167, 55},
		{"최윤미", 168, 51},
		{"함진아", 155, 46},
		{"홍연의", 173, 60},
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int retry;

	do {
		Person temp, *p;
		printf("이름: ");
		scanf("%s", temp.name);
		p = bsearch(&temp, x, nx, sizeof(Person),
				(int(*)(const void *, const void *)) npcmp);

		if (p == NULL)
			puts("검색 실패");
		else
			printf("x[%d] : %s %dcm %dkg\n", 
					(int)(p-x), p->name, p->height, p->weight);
	} while (retry == 1);

	return 0;
}
