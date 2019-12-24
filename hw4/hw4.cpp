#include <iostream>
#include <algorithm>

void mostPreciousPath(int path[8][2], int *totalGems, int *vaultNum){
    int const rowLength = 8;
    int gemLayoutArr[rowLength][rowLength] = {
            {89, 70, 73, 83, 90, 22, 44, 92},
            {46, 23, 99, 77, 10, 42, 1, 72},
            {85, 52, 27, 5, 94, 91, 82, 62},
            {22, 93, 68, 11, 56, 63, 49, 35},
            {13, 78, 48, 19, 78, 11, 90, 94},
            {31, 5, 63, 10, 32, 40, 14, 13},
            {73, 38, 24, 49, 18, 6, 40, 74},
            {79, 71, 18, 20, 34, 51, 93, 65}
    };
    int cellValues[rowLength][rowLength];

    // Fill in all the values for each cell coordinate
    for(int i = rowLength-1;i >= 0; i--){ //start at the bottom and work up
        for(int j=0;j<rowLength;j++){ //go from left to right
            int valBot = 0;
            int valBotLeft = 0;
            int valBotRight = 0;
            if(i+1 < 8){
                valBot = cellValues[i+1][j];
                if(j > 0){
                    valBotLeft = cellValues[i+1][j-1];
                }
                if(j < rowLength-1){
                    valBotRight = cellValues[i+1][j+1];
                }
            }

            cellValues[i][j] = std::max(std::max(valBot, valBotLeft), valBotRight) + gemLayoutArr[i][j];
        }
    }

    // finds the total number of gems collected and the last cell Billbo ends up in
    int destinationX = 0;
    int max = 0;
    for(int i=0;i<rowLength;i++){
        if(max < cellValues[0][i]){
            max = cellValues[0][i];
            destinationX = i;
        }
    }

    // set last place in the path
    path[7][1] = destinationX;

    // Finds the path by backtracking from the destination
    int currXPos = destinationX;
    int index = 6;
    for(int i=1;i<rowLength;i++){
        int largestIndexX = 0;
        if(cellValues[i][currXPos] > cellValues[i][currXPos-1])
            largestIndexX = currXPos;
        else
            largestIndexX = currXPos - 1;
        if (cellValues[i][largestIndexX] < cellValues[i][currXPos+1])
            largestIndexX = currXPos + 1;
        currXPos = largestIndexX;
        path[index][1] = currXPos;
        index--;
    }

    *totalGems = max;
    *vaultNum = destinationX + 1;
}

int main() {
    // path array initialized with y values and 0s
    int path[8][2] = {{1, 0}, {2, 0}, {3, 0}, {4, 0}, {5, 0}, {6, 0}, {7, 0}, {8, 0}};
    int totalGemsCollected = 0;
    int vaultNumber = 0;
    mostPreciousPath(path, &totalGemsCollected, &vaultNumber);

    printf("Starting Square Coordinates: (Row %d, Col %d)\n", path[0][0], path[0][1]+1);
    printf("Path: ");
    for(int i=0;i<8;i++){
        printf("(Row %d, Col %d) ",path[i][0],path[i][1]+1);
    }
    printf("\nTotal Number of Gems Collected: %d\n", totalGemsCollected);
    printf("Vault Number: %d\n", vaultNumber);


    return 0;
}