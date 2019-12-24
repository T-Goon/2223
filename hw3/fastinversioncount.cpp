#include <iostream>
#include <vector>

long merge_count(std::vector<int>& arr, std::vector<int>& left,
                 std::vector<int>& right)
{
    size_t i = 0;
    size_t j = 0;
    size_t count = 0;
    while (i < left.size() || j < right.size())
    {
        if (i == left.size())
        {
            arr[i + j] = right[j];
            j++;
        }
        else if (j == right.size())
        {
            arr[i + j] = left[i];
            i++;
        }
        else if (left[i] <= right[j])
        {
            arr[i + j] = left[i];
            i++;
        }
        else
        {
            arr[i + j] = right[j];
            count += left.size() - i;
            j++;
        }
    }
    return count;
}

long fast_inversion_count(std::vector<int>& vec)
{
    if (vec.size() < 2)
    {
        // Cant invert...
        return 0;
    }

    int middle = (vec.size() + 1) / 2;
    std::vector<int> left(vec.begin(), vec.begin() + middle);
    std::vector<int> right(vec.begin() + middle, vec.end());

    return fast_inversion_count(left) + fast_inversion_count(right) +
           merge_count(vec, left, right);
}

void print_it(std::vector<int>& vec)
{
    long invs = fast_inversion_count(vec);
    std::cout << "Inversions: " << invs << std::endl;
}

int main(void)
{
    size_t size;
    std::cout << "enter the desired array size" << std::endl;
    std::cin >> size;

    std::vector<int> list;
    int elem;
    for (size_t i = 0; i < size; i++)
    {
        std::cin >> elem;
        list.push_back(elem);
    }
    print_it(list);
    return 0;
}
