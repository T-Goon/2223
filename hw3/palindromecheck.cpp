#include <iostream>
#include <unordered_set>
#include <vector>

static const std::unordered_set<char> punctuation = {',', '.', '?', '\"', '\'',
                                                     ';', ':', '!'};

// Removes punctuation from a string
std::string fix(std::string& text)

{
    std::string tmp;
    for (size_t i = 0; i < text.length(); i++)
    {
        if (punctuation.find(text[i]) == punctuation.end())
        {
            tmp.push_back(std::tolower(text[i]));
        }
    }
    return tmp;
}

// Checks if a string is a palindrome

void palindromeCheck(std::string text, int i)
{
    std::string check = fix(text);
    int j = check.length() - 1 - i;
    if (i > j)
    {
        std::cout << "This is a palindrome" << std::endl;
        
    }
    else if (check[i] != check[j])
    {
        std::cout << "This is not a palindrome" << std::endl;
    }
    else
    {
        palindromeCheck(check, i + 1);
    }
}

int main()
{
    std::string test;
    std::cout << "          PALINDROME CHECK!!!           " << std::endl;
    std::cout << "Please enter the text you want to check!" << std::endl;
    std::cin >> test;
    
    palindromeCheck(test, 0);
    return 0;
}
