#include <iostream>
#include <map>
#include <string>
#include <vector>

static const std::vector<std::string> names = {
    "Alice",    "Bob",   "Chris",   "Dylan",  "Eve",     "Felix", "Gerry",
    "Helen",    "Ian",   "Jane",    "Karl",   "Louise",  "Mary",  "Nina",
    "Oscar",    "Penny", "Quentin", "Ronald", "Spencer", "Tom",   "Ulrich",
    "Victoria", "Wonda", "Xavier",  "Yvonne", "Zachary",
};

void diff_codes(std::vector<int>* prev, std::vector<int>& next)
{
    for (int i = prev->size() - 1; i >= 0; i--)
    {
        int idx = prev->size() - i - 1;
        if (prev->at(i) == 0 && next[i] == 1)
        {
            std::cout << names.at(idx) << " In";
        }
        else if (prev->at(i) == 1 && next[i] == 0)
        {
            std::cout << names.at(idx) << " Out";
        }
    }
}

// Find all binary grey codes or order n
std::vector<std::vector<int>> BRGC(int n)
{
    std::vector<std::vector<int>> arr = {};
    if (n == 1)
    {
        arr.push_back({0});
        arr.push_back({1});
    }
    else
    {
        arr = BRGC(n - 1);

        // copy arr to arr2 in reverse order
        std::vector<std::vector<int>> arr2(arr.rbegin(), arr.rend());

        // put a 0 in front of all of the codes in arr and a 1 in front of all
        // codes int arr2
        for (size_t i = 0; i < arr.size(); i++)
        {
            arr[i].insert(arr[i].begin(), 0);
            arr2[i].insert(arr2[i].begin(), 1);
        }

        // append arr2 to arr
        arr.insert(arr.end(), arr2.begin(), arr2.end());
    }
    return arr;
}

int main(void)
{
    int n;
    std::cout
        << "Graycodesarefun supports generating the table of photo arrangements"
           " up to n=26. Specify and n value"
        << std::endl;
    std::cin >> n;
    if (n > 26)
    {
        std::cout
            << "I said n must be _less than or equal to_ 26. So we are using 26"
            << std::endl;
        n = 26;
    }

    std::vector<std::vector<int>> arr = BRGC(n);
    std::vector<int>* last = nullptr;
    std::cout << "Index | Gray Code | Children in Photo | Action" << std::endl;
    for (size_t i = 1; i < arr.size(); i++)
    {
        std::cout << i << " | ";
        std::vector<int> inphoto;
        for (size_t j = 0; j < arr[i].size(); j++)
        {
            std::cout << arr[i][j];
            if (arr[i][j] == 1)
            {
                inphoto.push_back(arr[i].size() - j - 1);
            }
        }
        std::cout << " | ";
        for (auto it = inphoto.begin(); it != inphoto.end(); ++it)
        {
            std::cout << names.at(*it) << " ";
        }
        std::cout << " | ";
        if (last != nullptr)
        {
            diff_codes(last, arr[i]);
        }
        last = &arr[i];
        std::cout << std::endl;
    }
    return 0;
}
