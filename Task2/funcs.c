#include "funcs.h"

int find_max_lower_triangle(int matrix[][MAX_SIZE], int N,
                            int *max_row, int *max_col)
{
    int max_value = matrix[0][0];
    int i, j;

    // Ініціалізація індексів першого допустимого елемента
    *max_row = 0;
    *max_col = 0;

    // Перегляд головної діагоналі та елементів під нею
    for (i = 0; i < N; i++)
    {
        for (j = 0; j <= i; j++)
        {
            // Оновлення максимуму та його координат
            if (matrix[i][j] > max_value)
            {
                max_value = matrix[i][j];
                *max_row = i;
                *max_col = j;
            }
        }
    }

    return max_value;
}
