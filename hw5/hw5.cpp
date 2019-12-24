#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

constexpr int C = 123;
constexpr int m = 1000;

int hash(std::string&);

class HashTable
{
public:
    void insert(std::string& word)
    {
        int h = hash(word);
        do_insert(word, h);
    }

    std::string& operator[](int index)
    {
        return table[index];
    }

private:
    std::string table[m] = {std::string("")};


    void do_insert(std::string word, int index)
    {
        if (word != this->table[index])
        {
            if (this->table[index].length() > 0)
            {
                // We have a collision.
                index = (index + 1) % m;
                do_insert(word, index);

            }
            else
            {
                this->table[index] = word;
            }
        }
    }
};

int hash(std::string& word)
{
    int h = 0;
    for (size_t i = 0; i < word.length(); i++)
    {
        h = (h * C + word[i]) % m;
    }
    return h;
}
// gapOrCluster: true to find gaps, false to find clusters
// count: count of number of empty or filled elements
// index: index of current word in hash table
void areaCounter(bool gapOrCluster, std::string& word, int *count, int index, int *area_start, int *max_area_run, int *max_area_start){
    if (word.empty() == gapOrCluster)
    {
        *count+=1;
        if (*area_start < 0)
        {
            *area_start = index;
        }
    }
    else if (*area_start > 0)
    {
        int run = index - *area_start;
        if (run > *max_area_run)
        {
            *max_area_run = index - *area_start;
            *max_area_start = *area_start;
        }

        *area_start = -1;
    }
    else
    {
        *area_start = -1;
    }
}

int main(void)
{
    std::ifstream file;
    file.open("Raven.txt", std::ios::in);

    std::istreambuf_iterator<char> begin(file), end;

    std::string current;
    HashTable table;
    while (begin != end)
    {
        if (*begin == ' ')
        {
            if (current.length() > 0)
            {
                table.insert(current);
                current.clear();
            }
        }
        else if (*begin == '\'')
        {
            current.push_back(*begin);
        }
        else if (ispunct(*begin) || *begin == '\n' || *begin == '\r')
        {
            // nothing
        }
        else
        {
            current.push_back(*begin);
        }
        ++begin;
    }
    file.close();

    int non_empty = 0;
    int empty = 0;
    int cluster_start = -1;
    int gap_start = -1;
    int max_cluster_start = 0;
    int max_gap_start = 0;
    int max_cluster_run = 0;
    int max_gap_run = 0;
    int hashCount[1000] = {0};
    int largest_distance = 0;
    std::string furthest_word;
    // Loop through the words in the hash table
    for (int i = 0; i < m; i++)
    {
        std::string& word = table[i];
        // Find the largest cluster
        areaCounter(false, word, &non_empty, i, &cluster_start, &max_cluster_run, &max_cluster_start);

        // Find the largest gap
        areaCounter(true, word, &empty, i, &gap_start, &max_gap_run, &max_gap_start);

        // Finds the word that is furthest away from its initial hash
        int wordHash = hash(word);
        int wrappedDist = 0;
        int unwrappedDist = 0;
        if(word != "") {
            if (i > wordHash) {
                wrappedDist = (m - i) + wordHash;
                unwrappedDist = i - wordHash;
            } else if (wordHash > i) {
                wrappedDist = (m - wordHash) + i;
                unwrappedDist = wordHash - i;
            }

            if (wrappedDist < unwrappedDist && wrappedDist > largest_distance) {
                largest_distance = wrappedDist;
                furthest_word = word;
            } else if (unwrappedDist < wrappedDist && unwrappedDist > largest_distance) {
                largest_distance = unwrappedDist;
                furthest_word = word;
            }
        }

        if (word != "")
            hashCount[hash(word)] += 1;
        std::cout << i << ", " << word << ", " << hash(word) << std::endl;
    }

    std::cout << "Part 3 Questions" << std::endl;
    std::cout << "A. " << non_empty
              << " Non-Empty slots. Load factor: " << (double)non_empty / m
              << std::endl;
    std::cout << "B. Longest empty area is " << max_gap_run
              << " elements long and starts at " << max_gap_start<< std::endl;
    std::cout << "C. Largest cluster is " << max_cluster_run
              << " elements and starts at index " << max_cluster_start
              << std::endl;
    int max = 0;
    int maxIndex = 0;
    for(int i=0;i<1000;i++){
        if(hashCount[i] > max){
            max = hashCount[i];
            maxIndex = i;
        }
    }
    std::cout << "D. Index that results from greatest number of unique words is " << maxIndex << " with "
              << max << " unique words that hash to it." << std::endl;
    std::cout << "E. The word that is the furthest from its original index is " << furthest_word
              << " and is " << largest_distance << " elements away." << std::endl;


    return 0;
}
