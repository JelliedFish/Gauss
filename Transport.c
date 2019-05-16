#include "Transport.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void transport (int k, int n, int index_of_max, double** a) {

    //меняем местами строку с макисимальным и верхнюю местами
    for (int j = 0; j < n; j++)
    {
        double temp = a[k][j];
        a[k][j] = a[index_of_max][j];
        a[index_of_max][j] = temp;
    }
}