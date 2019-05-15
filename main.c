#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Functions.h"

void text_console() {

    printf("Введите размер матрицы как MxN в файл\n");

    printf("После введите саму матрицу через пробелы\n");

    printf("В конце введите столбец свободных членов B\n");
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m;
    double** a;
    double* y;
    srand(time(NULL));//Генерируем случайные числа
    scanf("%d %d", &m, &n);
    a = malloc(sizeof(double*[m]));
    y = malloc(sizeof(double[m]));
    for(int i = 0; i < m; i++){
        a[i] = malloc(sizeof(double[m]));
        for(int j = 0; j < n; j++) {
            a[i][j] = 1.0 + 4.0*rand()/(float)RAND_MAX; //Добавляем случайные числа
           // scanf("%lf", &a[i][j]);
        }
    }
    for(int i = 0; i < m; i++){
        scanf("%lf", &y[i]);
    }
    //cnan
    gauss(a, m, n);
    //solve(a, y, m, n);
    return 0;
}