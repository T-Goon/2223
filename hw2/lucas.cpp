#include <iostream>
#include <stdio.h>
#include <time.h>

#define MAX_LUCAS 30

constexpr long lucas(long n)
{
    long ret = -1;
    if (n == 0)
    {
        ret = 2;
    }
    else if (n == 1)
    {
        ret = 1;
    }
    else
    {
        ret = lucas(n - 1) + lucas(n - 2);
    }
    return ret;
}

int main(void)
{
    clock_t lucasClock;
    double lastTime = 0;
    double ratio = 0;
    for (long x = 0; x < MAX_LUCAS; x++)
    {
        lucasClock = clock();
        long ret = lucas(x);
        lucasClock = clock() - lucasClock;
        double seconds = (double)lucasClock / CLOCKS_PER_SEC;
        if (lastTime != 0)
        {
            ratio = seconds / lastTime;
        }
        lastTime = seconds;
        std::cout << x << " : " << ret << " This number took " << seconds
                  << " seconds" << std::endl;
        std::cout << "Ratio of this and the previous time : " << ratio
                  << std::endl;
    }
    return 0;
}
