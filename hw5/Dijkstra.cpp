#include <algorithm>
#include <climits>
#include <cmath>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

int min_distance(std::vector<int>& distances,
                 std::vector<int>& shortest_path_set)
{

    int min = INT_MAX;
    int min_index = -1;

    for (size_t v = 0; v < distances.size(); v++)
    {
        if (shortest_path_set[v] == 0 && distances[v] <= min)
        {
            min = distances[v];
            min_index = v;
        }
    }
    return min_index;
}

void path(std::vector<int>& parent, int idx, std::vector<int>& tmp)
{
    if (parent[idx] != -1)
    {
        path(parent, parent[idx], tmp);
        tmp.push_back(idx);
    }
}

void dijkstra(int** graph, size_t size, int start, int end)
{

    std::vector<int> distances;
    std::vector<int> path_set;
    std::vector<int> parent;

    for (size_t i = 0; i < size; i++)
    {
        distances.push_back(INT_MAX);
        path_set.push_back(false);
        parent.push_back(-1);
    }

    distances[start] = 0;

    for (size_t cnt = 0; cnt < (size - 1); cnt++)
    {
        int u = min_distance(distances, path_set);

        path_set[u] = 1;
        if (u == end)
        {
            break;
        }

        for (size_t v = 0; v < size; v++)
        {
            if (path_set[v] == 0 && graph[u][v] && distances[u] != INT_MAX &&
                distances[u] + graph[u][v] < distances[v])
            {
                distances[v] = distances[u] + graph[u][v];
                parent[v] = u;
            }
        }
    }

    std::cout << "Distance: " << distances[end] << std::endl;

    std::cout << "Path: ";

    std::vector<int> shortest;
    path(parent, end, shortest);

    std::cout << start << " ";
    for (auto it = shortest.begin(); it != shortest.end(); ++it)
    {
        std::cout << *it << " ";
    }
}

int main(void)
{
    std::ifstream file;
    int temp;
    file.open("input.txt");
    file >> temp;
    int dimensions = temp;
    int** bigArr = (int**)malloc(sizeof(int*) * dimensions);
    for (int i = 0; i < dimensions; i++)
    {
        bigArr[i] = (int*)malloc(sizeof(int) * dimensions);
    }
    int x = 0;
    int y = 0;
    while (file >> temp)
    {
        bigArr[x][y] = temp;
        y++;
        if (y == 10)
        {
            x++;
            y = 0;
        }
    }
    int start = -1;
    int end = -1;
    std::cout << "pick a start node, 0-" << dimensions << std::endl;
    while (!(start < dimensions && start >= 0))
    {
        std::cin >> start;
    }
    std::cout << "pick an end node, 0-" << dimensions << std::endl;
    while (!(end < dimensions && end >= 0 && start != end))
    {
        std::cin >> end;
    }

    dijkstra(bigArr, dimensions, start, end);
    return 0;
}
