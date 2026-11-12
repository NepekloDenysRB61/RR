
#include <stdio.h>
#include "funcs.h"

int main(void)
{
    double a;
    int N;
    int skipped = 0;

    // Введення параметра ряду
    printf("Enter a: ");

    if (scanf("%lf", &a) != 1)
    {
        printf("Error: invalid value of a.\n");
        return 1;
    }

    // Введення та перевірка кількості доданків
    printf("Enter N (N >= 1): ");

    if (scanf("%d", &N) != 1 || N < 1)
    {
        printf("Error: N must be >= 1.\n");
        return 1;
    }

    // Обчислення суми ряду
    double sum = calculate_series(a, N, &skipped);

    // Виведення результатів обчислення
    printf("\nSum S = %.10f\n", sum);
    printf("Skipped terms: %d\n", skipped);

    return 0;
}
