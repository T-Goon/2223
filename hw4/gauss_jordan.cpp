#include <cstdlib>
#include <cstring>
#include <iostream>
#include <stdint.h>
#include <utility>

// Footnote 1 in the description says its okay to assume an 8 x 9 matrix of
// doubles.
constexpr size_t n = 8;

int reduce(double matrix[][n + 1])
{
    uint8_t nonOrInfinite = 0;

    for (size_t i = 0; i < n; i++)
    {
        if (matrix[i][i] == 0)
        {
            int c = 1;
            while (matrix[i + c][i] == 0 && (i + c) < n)
            {
                c++;
            }
            if ((i + c) == n)
            {
                nonOrInfinite = 1;
            }
            else
            {
                size_t j = i;
                for (size_t k = 0; k <= n; k++)
                {
                    std::swap(matrix[j][k], matrix[j + c][k]);
                }
            }
        }

        for (size_t j = 0; j < n; j++)
        {
            if (i != j)
            {
                const double piv = matrix[j][i] / matrix[i][i];

                for (size_t k = 0; k <= n; k++)
                {
                    matrix[j][k] = matrix[j][k] - (matrix[i][k]) * piv;
                }
            }
        }
    }
    return nonOrInfinite;
}

void solve(double a[][n + 1], uint8_t ns)
{
    std::cout << "Results in order: ";

    if (ns)
    {
        std::cout << "No solution or infinite solutions";
    }
    else
    {
        for (size_t i = 0; i < n; i++)
        {
            std::cout << a[i][n] / a[i][i] << " ";
        }
    }
    std::cout << std::endl;
}

int main(void)
{
    double arr[n][n + 1];

    std::cout << "Enter an 8 x 9 matrix to solve." << std::endl;
    for (size_t i = 0; i < n; i++)
    {
        std::cout << "Enter row number " << (i + 1) << std::endl;
        for (size_t j = 0; j < (n + 1); j++)
        {
            scanf("%lf", &arr[i][j]);
        }
    }

    uint8_t result = reduce(arr);

    solve(arr, result);
}
