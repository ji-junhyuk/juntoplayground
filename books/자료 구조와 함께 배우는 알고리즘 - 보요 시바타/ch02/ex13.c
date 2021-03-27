#include <stdio.h>
#define VMAX 21

typedef struct {
	char name[20];
	int height;
	double vision;
} PhysCheck;

double ave_height(const PhysCheck dat[], int n)
{
	int i;
	
	double sum = 0;
	i = 0;
	while (i < n)
	{
		sum += dat[i].height;
		i++;
	}
	return sum / n;
}

void dist_vision(const PhysCheck dat[], int n, int dist[])
{
	int i;

	i = 0;
	while (i < VMAX)
	{
		dist[i] = 0;
		i++;
	}

	i = 0;
	while (i < n)
	{
		if (dat[i].vision >= 0.0 && dat[i].vision <= VMAX/10.0)
			dist[(int)(dat[i].vision * 10)]++;
		i++;
	}
}

int main()
{
	int i;
	PhysCheck x[] = 
	{
		{"박현규", 162, 0.3},
		{"함진아", 173, 0.7},
		{"최윤미", 175, 2.0},
		{"홍연의", 171, 1.5},
		{"이수진", 168, 0.4},
		{"김영준", 174, 1.2},
		{"박용규", 169, 0.8}
	};

	int nx = sizeof(x) / sizeof(x[0]);
	int vdist[VMAX];
	
	i = 0;
	while (i < nx)
	{
		printf("%-12s%3d%4.1f\n", x[i].name, x[i].height, x[i].vision);
		i++;
	}
	puts("");
	printf("ave height: %-6.1f\n", ave_height(x, nx));
	dist_vision(x, nx, vdist);
	puts("");

	i = 0;
	while (i < VMAX)
	{
		printf("%3.1f ~ : ", i/10.0);
		if (vdist[i] > 0)
			printf("*");
		puts("");
		i++;
	}

	return 0;
}
