#include <ctype.h>
#include <stdio.h>
#include "funcs.h"

int main(void)
{
    int matrix[MAX_SIZE][MAX_SIZE];
    int N, i, j;
    int max_value;
    int max_row = 0;
    int max_col = 0;
    int readStatus, ch, extra;

    // Введення та перевірка розміру квадратної матриці
    while (1)
    {
        printf("Enter matrix size N (1-%d): ", MAX_SIZE);
        readStatus = scanf("%d", &N);
        extra = 0;

        // Перевірка наявності зайвих символів у рядку
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            if (!isspace((unsigned char)ch))
                extra = 1;
        }

        if (readStatus == 1 && !extra && N >= 1 && N <= MAX_SIZE)
            break;

        printf("Error: invalid matrix size. Try again.\n");
        if (ch == EOF) return 1;
    }

    // Зчитування елементів матриці з повторним запитом у разі помилки
    printf("\nEnter matrix elements:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            while (1)
            {
                printf("A[%d][%d] = ", i, j);
                readStatus = scanf("%d", &matrix[i][j]);
                extra = 0;

                // Перевірка коректності введеного елемента
                while ((ch = getchar()) != '\n' && ch != EOF)
                {
                    if (!isspace((unsigned char)ch))
                        extra = 1;
                }

                if (readStatus == 1 && !extra)
                    break;

                printf("Error: invalid element. Try again.\n");
                if (ch == EOF) return 1;
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
