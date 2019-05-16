#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Gauss.c"
#include "Solve.c"

//jbbj


int main() {
    freopen("Gauss.in.txt", "r", stdin);
    freopen("Gauss.out.txt", "w", stdout);
    int n, m;
    double** a;
    double* y;
    srand(time(NULL));//Генерируем случайные числа
    scanf("%d %d", &m, &n);
    a = malloc(sizeof(double*[m]));
    y = malloc(sizeof(double[m]));
    for(int i = 0; i < m; i++){
        a[i] = malloc(sizeof(double[n]));
        for(int j = 0; j < n; j++) {
            a[i][j] = 1.0 + 4.0*rand()/(float)RAND_MAX; //Добавляем случайные числа
           // scanf("%lf", &a[i][j]); //раскомментить, если хочется ввести матрицу вручную.
        }
    }
    for(int i = 0; i < m; i++){
        scanf("%lf", &y[i]);
    }
    gauss(a, m, n);
    free(a);
    free(y);
    fclose(stdin);
    fclose(stdout);
    freopen("solve.in.txt", "r", stdin);
    freopen("solve.out.txt", "w", stdout);
    scanf("%d %d", &m, &n);
    a = malloc(sizeof(double*[m]));
    y = malloc(sizeof(double[m]));

    for(int i = 0; i < n; i++){
        a[i] = malloc(sizeof(double[n]));
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