#include <cstdio>
#include <vector>

constexpr int wrapped_add(const int index, const int increment, const int len)
{
    if (index + increment >= len)
    {
        return 0;
    }
    else if (index - increment < 0)
    {
        return len - 1;
    }
    else
    {
        return index - increment;
    }
}

long count_combinations(const int sum, const std::vector<int> numbers)
{
    long combinations = 0;

    for (size_t x = 0; x < numbers.size(); x++)
    {
        for (size_t y = 0; y < numbers.size() && x != y; y++)
        {

            int i = numbers[x];
            int j = numbers[wrapped_add(x, -1, numbers.size())];
            int k = numbers[y];
            int l = numbers[wrapped_add(y, 1, numbers.size())];

            if (i + j + k + l == sum)
            {
                combinations++;
                printf("Combination: %d, %d, %d, %d = %d\n", i, j, k, l,
                       (i + j + k + l));
            }
        }
    }

    return combinations;
}
/* target: desired sum
 * comboArr: current combination of numbers
 * index: index of the right most value in comboArr plus one. Comes from classList.
 * currentPass: number of elements added to comboArr and number of times the function line has run
 * classList: list of elements to draw from
 * size: size of the classList and max size of comboArr
 * count: pointer to the number of combinations add to target
 * chooseNum: size of the desired subset
 * */

void countCombosHelper(int target, int comboArr[], int index, int currentPass, int classList[], int size, int *count, int chooseNum){
    // get the sum of the current int combo
    int sum = 0;
    for(int i=0;i<currentPass;i++){
        sum+=comboArr[i];
    }

    // If it is finished creating the combo check if adds to target
    if(sum > target)
        return;
    else if(currentPass == chooseNum){
        if(target == sum)
            *count+=1;
        return;
    }

    // Choose an a number that is to the right of the most recently added one and add it to the combo
    for(int i=index;i<size;i++){
        comboArr[currentPass] = classList[i];

        countCombosHelper(target, comboArr, i+1, currentPass+1, classList, size, count, chooseNum);
    }
}

// finds the total number of combinations of numbers that come from Suribachs square that add to target
int countCombinations(int target){
    // numbers from the square
    int classList[] = {1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15};
    int lengthClassList = 16;
    int count = 0;

    // special case of subset of size 0 which will sum to 0
    if(target == 0){
        return 1;
    }

    for (int a=1;a<=lengthClassList;a++){ // do for nums of subset of sizes 0-16
        for(int i=0;i<lengthClassList;i++){ // get the first number in the combo
            int comboArr[lengthClassList];
            comboArr[0] = classList[i];
            countCombosHelper(target, comboArr, i+1, 1, classList, lengthClassList, &count, a);
        }
    }

    return count;
}


int main(void)
{
    int num = 0;
    int *np=&num;
    int numAllSums = 0;
    long comb = count_combinations(
            33, {1, 14, 14, 4, 11, 7, 6, 9, 8, 10, 10, 5, 13, 2, 3, 15});

    printf("Computed %ld combinations\n\n", comb);

    printf("Total number of sums of 33: %d\n", countCombinations(33));

    printf("The sum of the entire square is 132.\n");

    for(int i = 0; i<=132; i++){
        int tempSum = countCombinations(i);
        printf("All possible sums of %d is %d.\n", i, tempSum);
    }

    return 0;
}
