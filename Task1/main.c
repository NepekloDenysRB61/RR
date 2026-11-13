#include <ctype.h>
#include <float.h>
#include <stdio.h>
#include <windows.h>
#include "funcs.h"

int main(void)
{
    // Налаштування кодування UTF-8 для консолі Windows
    SetConsoleOutputCP(CP_UTF8);

    double a;
    int N;
    int skipped = 0;
    int readStatus, ch, extra;

    // Введення параметра a з перевіркою коректності
    while (1)
    {
        printf("Введіть значення a: ");
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

        printf("Помилка: некоректне значення a. Спробуйте ще раз.\n");
        if (ch == EOF) return 1;
    }

    // Введення N з перевіркою коректності
    while (1)
    {
        printf("Введіть ціле число N (N >= 1): ");
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

        printf("Помилка: некоректне значення N. Спробуйте ще раз.\n");
        if (ch == EOF) return 1;
    }


    // Обчислення суми ряду
    double sum = calculate_series(a, N, &skipped);

    // Виведення результатів обчислення
    printf("\nСума ряду S = %.10f\n", sum);
    printf("Пропущено доданків: %d\n", skipped);

    return 0;
}
