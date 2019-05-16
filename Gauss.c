#include "Find_main_function.c"
#include "Find_main_function.h"
#include "Transport.c"
#include "Transport.h"
#include "Gauss.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

void gauss(double** a,  int m,  int n) {
    int index_of_max = 0;
    int k = 0;
    const double eps = 0.000001;

    printf("Матрица, которую мы используем:\n\n");
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            printf("%lf ", a[i][j]);
        }
        printf("\n");
    }

    printf("\n\n\n");
    printf("Приведение к ступенчатому виду:\n\n");

    while (k < m)
    {
        // Поиск строки с максимальным a[i][k]
        index_of_max = find_main(k,m,a);
        // Перестановка строк
        if (index_of_max != -1){
            transport(k, n, index_of_max,a);
        }


        // Нормализация уравнений
        for (int i = k; i < m; i++)
        {
            double temp = a[i][k];
            if (fabs(temp) < eps) continue; // для нулевого коэффициента пропустить
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] / temp;
            if (i == k)  continue; // уравнение не вычитать само из себя
            for (int j = 0; j < n; j++)
                a[i][j] = a[i][j] - a[k][j];
        }
        k++;
    }

    for(int i = 0; i < m; i++){

        for(int j = 0; j < n; j++){

            if(fabs(a[i][j]) > eps){
                printf("%lf ", a[i][j]);
            }
            else {
                printf("%lf ", fabs(a[i][j])); //Для того, чтобы не было -0.0000 из-за погрешности.
            }
        }
        printf("\n");
    }

}