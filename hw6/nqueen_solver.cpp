/**
 * Finds the first solution to the n-queens problem from n= 4..100.
 */
#include <algorithm>
#include <iostream>
#include <vector>

std::vector<int> solve(size_t n)
{
    std::vector<int> solution;
    for (size_t i = 2; i <= n; i += 2)
    {
        solution.push_back(i);
    }
    for (size_t i = 1; i <= n; i += 2)
    {
        solution.push_back(i);
    }
    if (n % 6 != 2 && n % 6 != 3)
    {
        // nothing
    }
    else if (n % 6 == 2)
    {
        auto one = std::find(solution.begin(), solution.end(), 1);
        auto three = std::find(solution.begin(), solution.end(), 3);
        std::swap(*one, *three);
        solution.erase(std::find(solution.begin(), solution.end(), 5));
        solution.push_back(5);
    }
    else if (n % 6 == 3)
    {
        auto two = std::find(solution.begin(), solution.end(), 2);
        auto one = std::find(solution.begin(), solution.end(), 1);

        solution.erase(two);
        solution.insert(one - 1, 2);

        solution.erase(one);
        solution.erase(std::find(solution.begin(), solution.end(), 3));
        solution.push_back(1);
        solution.push_back(3);
    }

    return solution;
}

int main(void)
{
    for (size_t n = 4; n < 101; n++)
    {
        std::cout << "n = " << n << " : ";
        std::vector<int> solution = solve(n);
        for (auto it = solution.begin(); it != solution.end(); ++it)
        {
            std::cout << *it << ", ";
        }
        std::cout << std::endl;
    }
    return 0;
}
