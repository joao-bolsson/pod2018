/**
 * @author João Bolsson (jvmarques@inf.ufsm.br)
 * @version 2018, Oct 29.
 */
#include <stdio.h>
#include <stdlib.h>

/**
 * Swap two given elements.
 * @param a First element.
 * @param b Second element.
 */
void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

/**
 * Builds the array in a heap format.
 * @param v Array with integers.
 * @param m Array length.
 */
void buildHeap(int *v, int m) {
    for (int i = 0; i < m - 1; i++) {
        int f = i + 1;
        while (f > 1 && v[f / 2] < v[f]) {
            swap(&v[f / 2], &v[f]);
            f /= 2;
        }
    }
}

int main() {
    int len = 10;
    int *v = (int *) malloc(sizeof(int) * len);

    // fill
    for (int i = 0; i < len; i++) {
        v[i] = i + 1;
    }

    printf("Before\n");
    for (int i = 0; i < len; i++) {
        printf("%d\n", v[i]);
    }

    buildHeap(v, len);

    printf("After\n");

    for (int i = 0; i < len; i++) {
        printf("%d\n", v[i]);
    }

    return 0;
}