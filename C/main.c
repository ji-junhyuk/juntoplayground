#include <time.h>
#include <stdio.h>
#include <stdlib.h>
<<<<<<< HEAD

#define swap(type, x , y) do { type t = x; x = y; y = t;} while (0)
void shuffle(int a[], int n)
{
    srand(time(NULL));
    for (int i = n - 1; i > 0; --i) {
        int j = rand() % (i + 1);
        if (i != j) {
            swap(int, a[i], a[j]);
        }
    }
}

int main(void)
{
    int i;
    int *x;
    int nx;

    printf("number of element:");
    scanf("%d", &nx);
    x = calloc(nx, sizeof(int));

    printf("%d enter the number\n", nx);
    for (int i = 0; i < nx; ++i) {
        printf("x[%d]: ", i);
        scanf("%d", &x[i]);
    }

    shuffle(x, nx);
    for (int i = 0; i < nx; ++i) {
        printf("y[%d] = %d\n", i, x[i]);
    }

    free(x);

    return 0;
}


=======
#include <time.h>

int main() {
    int x, y;

    srand(time(NULL));
    x = rand() % 6;
    y = rand() % 6;

    printf("%d, %d\n", x, y);
}
>>>>>>> 1ec6ad6223aecf8ecfd9578d309c137eb93a52eb
