
#include "Find_main_function.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

int find_main(int k, int m, double **a) {
    double max = 0;
    int index = 0;
    const double eps = 0.00001;

    // Поиск строки с максимальным a[i][k]
    max = fabs(a[k][k]);
    index = k;
    for (int i = k + 1; i < m; i++) {
        if (fabs(a[i][k]) > max) {
            max = fabs(a[i][k]);
            index = i;
        }
    }

    if (max < eps){
        return -1;
    }
    else {
        return index;
    }
}
