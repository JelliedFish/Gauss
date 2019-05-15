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
    freopen("Gauss.in.txt", "r", stdin);
    freopen("Gauss.out.txt", "w", stdout);
    int n, m;
    double** a;
    double* y;
    srand(time(NULL));//Генерируем случайные числа
    scanf("%d %d", &n, &m);
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
    free(a);
    free(y);
    fclose(stdin);
    fclose(stdout);
    freopen("solve.in.txt", "r", stdin);
    freopen("solve.out.txt", "w", stdout);
    scanf("%d %d", &n, &m);
    a = malloc(sizeof(double*[m]));
    y = malloc(sizeof(double[m]));
    for(int i = 0; i < n; i++){
        a[i] = malloc(sizeof(double[m]));
        for(int j = 0; j < m; j++) {
            scanf("%lf", &a[i][j]);
        }
    }
    for(int i = 0; i < n; i++){
        scanf("%lf", &y[i]);
    }
    solve(a, y, m, n);
    fclose(stdin);
    fclose(stdout);
    return 0;
}