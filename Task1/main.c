#include <ctype.h>
#include <float.h>
#include <stdio.h>
#include "funcs.h"

int main(void)
{
    double a;
    int N;
    int skipped = 0;
    int readStatus, ch, extra;

    // Введення параметра a з перевіркою коректності
    while (1)
    {
        printf("Enter a: ");
        readStatus = scanf("%lf", &a);
        extra = 0;

        // Перевірка наявності зайвих символів
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            if (!isspace((unsigned char)ch))
                extra = 1;
        }

        if (readStatus == 1 && !extra &&
            a >= -DBL_MAX && a <= DBL_MAX)
            break;

        printf("Error: invalid a. Try again.\n");
        if (ch == EOF) return 1;
    }

    // Введення N з перевіркою коректності
    while (1)
    {
        printf("Enter N (N >= 1): ");
        readStatus = scanf("%d", &N);
        extra = 0;

        // Перевірка наявності зайвих символів
        while ((ch = getchar()) != '\n' && ch != EOF)
        {
            if (!isspace((unsigned char)ch))
                extra = 1;
        }

        if (readStatus == 1 && !extra && N >= 1)
            break;

        printf("Error: invalid N. Try again.\n");
        if (ch == EOF) return 1;
    }


    // Обчислення суми ряду
    double sum = calculate_series(a, N, &skipped);

    // Виведення результатів обчислення
    printf("\nSum S = %.10f\n", sum);
    printf("Skipped terms: %d\n", skipped);

    return 0;
}
