
#include "funcs.h"

double calculate_series(double a, int N, int *skipped)
{
    double sum = 1.0;
    double power = 1.0;

    *skipped = 0;

    // Послідовне обчислення доданків ряду
    for (int n = 1; n <= N; n++)
    {
        // Обчислення a^n без використання pow()
        power *= a;

        // Визначення знака (-1)^(n-1)
        int sign = (n % 2 == 1) ? 1 : -1;

        double denominator = a + sign * n;

        // Пропуск доданка з нульовим знаменником
        if (denominator == 0.0)
        {
            (*skipped)++;
            continue;
        }

        sum += sign * power / denominator;
    }

    return sum;
}
