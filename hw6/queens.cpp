#include <iostream>
#include <stdlib.h>
#include <string.h>


/**
 * Prints out the board.
 * @param board 2d array of 1s and 0s
 * @param n the size of the board
 */
void printArray(int** board, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {

        for (size_t j = 0; j < n; j++)
        {
            std::cout << board[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

/**
 * Prints out the positions of the queens on the board.
 * (Indexes start at 1.)
 * @param board 2d array of 1s and 0s.
 * @param n size if the board
 */
void printIndexes(int** board, size_t n){
    std::cout << "(";
    for (size_t i = 0; i < n; i++)
    {

        for (size_t j = 0; j < n; j++)
        {
            if(board[i][j] == 1)
                std::cout << j+1 << " ";
        }
    }
    std::cout << ")";
}

/**
 * Checks if a column has any move violations.
 * @param board The chessboard.
 * @param col Column to search.
 * @param n Board dimension.
 * @param max Maximum number of queens allowed in this search, used to
 * differentiate pre and post placement.
 * @return True if the section is legal.
 */
bool _legal_col(int** board, int col, size_t n, int max)
{
    int count = 0;
    for (int i = 0; (size_t)i < n; i++)
    {
        if (board[i][col])
        {
            count++;
        }
        if (count > max)
        {
            return false;
        }
    }
    return true;
}

/**
 * Checks if a row has any move violations.
 * @param board The chessboard.
 * @param row Row to search.
 * @param n Board dimension.
 * @param max Maximum number of queens allowed in this search, used to
 * differentiate pre and post placement.
 * @return True if the section is legal.
 */
bool _legal_row(int** board, int row, size_t n, int max)
{
    int count = 0;
    for (int i = 0; (size_t)i < n; i++)
    {
        if (board[row][i])
        {
            count++;
        }
        if (count > max)
        {
            return false;
        }
    }
    return true;
}

/**
 * Checks if a leftward diagonal has any move violations.
 * TODO: Check the full diag, including above this position.
 *
 * @param board The chessboard.
 * @param row Row position
 * @param col Column position.
 * @param n Board dimension.
 * @param max Maximum number of queens allowed in this search, used to
 * differentiate pre and post placement.
 * @return True if the section is legal.
 */
bool _legal_left_diag(int** board, int row, int col, int max)
{
    int count = 0;
    for (int i = row, j = col; i >= 0 && j >= 0; i--, j--)
    {
        if (board[i][j])
        {
            count++;
        }
        if (count > max)
        {
            return false;
        }
    }
    return true;
}

/**
 * Checks if a rightward diagonal has any move violations.
 * TODO: Check the full diag, including above us.
 *
 * @param board The chessboard.
 * @param row Row position
 * @param col Column position.
 * @param n Board dimension.
 * @param max Maximum number of queens allowed in this search, used to
 * differentiate pre and post placement.
 * @return True if the section is legal.
 */
bool _legal_right_diag(int** board, int row, int col, size_t n, int max)
{
    int count = 0;
    for (int i = row, j = col; i >= 0 && j < (int)n; j++, i--)
    {
        if (board[i][j])
        {
            count++;
        }
        if (count > max)
        {
            return false;
        }
    }
    return true;
}

/**
 * Determines if a board position is legal.
 *
 * @param board The chessboard in its current state.
 * @param row Row to check.
 * @param col Column to check.
 * @param n Board dimension.
 * @param placed True if the queen has already been placed.
 * @return True if the position is legal.
 */
bool legal(int** board, int row, int col, size_t n, bool placed)
{
    int max = 1;
    if (!placed)
    {
        max = 0;
    }
    bool ret = true;
    if (!_legal_row(board, row, n, max))
    {
        ret = false;
    }
    else if (!_legal_col(board, col, n, max))
    {
        ret = false;
    }
    else if (!_legal_left_diag(board, row, col, max))
    {
        ret = false;
    }
    else if (!_legal_right_diag(board, row, col, n, max))
    {
        ret = false;
    }
    return ret;
}

/**
 * Checks if the board for the n queens problem is in a legal position.
 * @param board 2d array of 1s and 0s.
 * @param n size of the board
 * @return false of the board is illegal, true if legal
 */
bool is_legal_position(int** board, size_t n)
{
    for (size_t i = 0; i < n; i++)
    {
        for (size_t j = 0; j < n; j++)
        {
            if (!legal(board, i, j, n, true))
            {
                return false;
            }
        }
    }
    return true;
}

/**
 * Finds the row index of the last queen placed.
 * @param board 2d array of 1s and 0s
 * @param n size of the board
 * @return row index of the last queen on the board or -1 if
 * the board is empty.
 */
int findRowIndex(int** board, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if (board[i][j] == 1)
            {
                return i;
            }
        }
    }

    return -1;
}

/**
 * Finds the col index of the last queen placed.
 * @param board 2d array of 1s and 0s
 * @param n size of the board
 * @return col index of the last queen on the board or -1 if
 * the board is empty.
 */
int findColIndex(int** board, int n)
{
    for (int i = n-1; i >= 0; i--)
    {
        for (int j = n-1; j >= 0; j--)
        {
            if (board[i][j] == 1)
            {
                return j;
            }
        }
    }

    return -1;
}

/**
 * Removes last queen placed.
 * @param board 2d array of 1s and 0s
 * @param n size of the board
 * @return board after the queen has been removed
 */
int** removeLastQueen(int** board, size_t n)
{
    board[findRowIndex(board,n)][findColIndex(board,n)] = 0;
    return board;
}

/**
 * Finds the next legal position of the board in n queens problem.
 * @param board 2d array of 1s and 0s
 * @param n the size of the board
 * @return The board with the next legal position or an empty board if
 * it does not exist.
 */
int** nextLegalPosition(int** board, size_t n)
{
    size_t j = 0;
    bool is_legal = is_legal_position(board, n);

    // Not legal remove last queen placed until the board is legal.
    while(!is_legal){
        // Keep track of last queen placement
        j = findColIndex(board, n)+1;
        removeLastQueen(board, n);
        is_legal = is_legal_position(board, n);
    }

    size_t curRow = findRowIndex(board, n);

    //checks if full
    if (curRow == n-1) {
        j = findColIndex(board, n)+1;
        removeLastQueen(board, n);
    }
    else
        curRow++;

    while(true)
    {
        //works on next row after last queen
        //false flag, if nothing is changed on current row then...
        bool flag = false;
        for (;j < n; j++)
        {
            if (legal(board, curRow, j, n, false))
            {
                board[curRow][j] = 1;
                flag = true;
            }
        }

        // removes last placed queen
        // if a queen was not placed
        if (!flag) {
            j = findColIndex(board, n) + 1;

            if(findRowIndex(board, n) == -1){
                std::cout << "Next legal position does not exist.\n";
                return board;
            }

            removeLastQueen(board, n);
            curRow--;
        }
        else {
            // A queen was placed return the board.
            return board;
        }
    }
}

/**
 * Checks if the board is empty.
 * @param board 2d array of 1s and 0s
 * @param n size of the board.
 * @return false if the board has queens on it,
 * true if the board is empty.
 */
bool empty(int** board, size_t n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(board[i][j] == 1){
                return false;
            }
        }
    }
    return true;
}

/**
 * Prints all solutions of a board of size n.
 * @param n: size of the board
 * @return number of solutions
 */
int findAllSolutions(size_t n){
    // Initialize the board
    int** arr = new int*[n];
    for (size_t i = 0; i < n; i++)
    {
        arr[i] = new int[n];
        memset(arr[i], 0, n * sizeof(int));
    }

    int count = 0;
    while(true){
        // Find next legal position until the board is full.
        nextLegalPosition(arr, n);
        if(findRowIndex(arr, n) == n-1){
            std::cout << "Solution board:\n";
            printArray(arr, n);
            std::cout << "Solution indexes: ";
            printIndexes(arr, n);
            std::cout << std::endl;
            count ++;
        }

        // There are no more legal positions when nextLegalPosition
        // returns an empty board.
        if(empty(arr, n)){
            break;
        }
    }

    for (size_t i = 0; i < n; i++)
    {
        delete[] arr[i];
    }

    delete[] arr;

    return count;
}

int main(void)
{

    size_t n;
    std::cout << "Find all solutions for board size(4<=n<=20):";
    std::cin >> n;
    int numSolutions = findAllSolutions(n);
    std::cout << "There are " << numSolutions << " solutions for board size of " << n << ".\n";

    return 0;
}
