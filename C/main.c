#include <stdio.h>

int main() {
    for (int i = 65; i < 128; ++i) {
        printf("%c", i);


        if (i % 8 == 0)
            printf("\n");
        continue;

    }
}