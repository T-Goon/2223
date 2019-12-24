#include <iostream>
#include <vector>

void easyinversioncount(std::vector<int>& intList)
{
    size_t s = intList.size();
    int paircount = 0;

    for (size_t i = 0; i < s; i++)
    {
        for (size_t j = i + 1; j < s; j++)
        {
            if (intList[i] > intList[j])
            {
                paircount++;
                std::cout << intList[i] << " : " << intList[j] << std::endl;
            }
        }
    }

    std::cout << paircount << " pairs" << std::endl;
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

    easyinversioncount(list);
}
