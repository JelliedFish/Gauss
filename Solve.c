
#include "Find_main_function.h"
#include "Transport.h"
#include "Gauss.h"
#include "Solve.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>


int solve(double** a, double* y, int m, int n) {
    double *x = malloc(sizeof(double[n]));
    int index_of_max = 0;
    int k = 0;
    const double eps = 0.00001;

    printf("Матрица, которую мы используем:\n\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    printf("Решения нашей СЛАУ:\n\n");

    if (m != n) {
        printf("Нет решений! Потому что матрица не квадратная!");
    } else {

        while (k < m) {
            // Поиск строки с максимальным a[i][k]
            index_of_max = find_main(k, m, a);
            // Перестановка строк
            if (index_of_max != -1) {
                transport(k, n, index_of_max, a);
            } else {
                printf("Нет решений!");
                return 0;
            }

            double temp = y[k];
            y[k] = y[index_of_max];
            y[index_of_max] = temp;

            // Нормализация уравнений
            for (int i = k; i < m; i++) {
                double temp = a[i][k];
                if (fabs(temp) < eps) continue; // для нулевого коэффициента пропустить
                for (int j = 0; j < m; j++)
                    a[i][j] = a[i][j] / temp;
                y[i] = y[i] / temp;
                if (i == k) continue; // уравнение не вычитать само из себя
                for (int j = 0; j < m; j++)
                    a[i][j] = a[i][j] - a[k][j];
                y[i] = y[i] - y[k];
            }
            k++;
        }

        for (int k = n - 1; k >= 0; k--) {
            x[k] = y[k];
            for (int i = 0; i < k; i++) {
                y[i] = y[i] - a[i][k] * x[k];
            }
        }

        for (int i = 0; i < m; i++) {
            printf("x%d = ", i + 1);
            printf("%lf\n", x[i]);
        }
        return 0;
    }
}





