#include <stdio.h>
#include "funcs.h"

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int N, i, j;
    int max_value;
    int max_row = 0;
    int max_col = 0;

    // Введення та перевірка розміру квадратної матриці
    printf("Enter matrix size N (1-%d): ", MAX_SIZE);
    if (scanf("%d", &N) != 1 || N < 1 || N > MAX_SIZE)
    {
        printf("Error: invalid matrix size.\n");
        return 1;
    }

    // Зчитування елементів матриці з клавіатури
    printf("\nEnter matrix elements:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("A[%d][%d] = ", i, j);
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Error: invalid matrix element.\n");
                return 1;
            }
        }
    }

    // Виведення введеної матриці
    printf("\nMatrix A:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("%6d", matrix[i][j]);
        }
        printf("\n");
    }

    // Пошук максимуму за допомогою окремої функції
    max_value = find_max_lower_triangle(matrix, N, &max_row, &max_col);

    // Виведення результату та індексів (нумерація з нуля)
    printf("\nMaximum value: %d\n", max_value);
    printf("Row index: %d\n", max_row);
    printf("Column index: %d\n", max_col);

    return 0;
}
