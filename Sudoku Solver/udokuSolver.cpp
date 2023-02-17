#include <iostream>
#include <cstring>

const int N = 9;

int grid[N][N];

bool isValid(int row, int col, int num)
{
    // check if 'num' is not already placed in current row, current column and current 3x3 box
    for (int i = 0; i < N; i++)
        if (grid[row][i] == num || grid[i][col] == num)
            return false;

    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = startRow; i < startRow + 3; i++)
        for (int j = startCol; j < startCol + 3; j++)
            if (grid[i][j] == num)
                return false;

    return true;
}

bool findUnassignedLocation(int& row, int& col)
{
    for (row = 0; row < N; row++)
        for (col = 0; col < N; col++)
            if (grid[row][col] == 0)
                return true;

    return false;
}


bool solveSudoku()
{
    int row, col;

    // if there are no unassigned locations, the puzzle is solved
    if (!findUnassignedLocation(row, col))
        return true;

    // try different values in an unassigned location
    for (int num = 1; num <= N; num++)
    {
        // if placing 'num' at (row, col) is valid
        if (isValid(row, col, num))
        {
            // make tentative assignment
            grid[row][col] = num;

            // return true if sudoku is solved
            if (solveSudoku())
                return true;

            // failure, unmake & try again
            grid[row][col] = 0;
        }
    }

    return false; // this triggers backtracking
}

int main()
{
    // example puzzle
    int puzzle[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                       {5, 2, 0, 0, 0, 0, 0, 0, 0},
                       {0, 8, 7, 0, 0, 0, 0, 3, 1},
                       {0, 0, 3, 0, 1, 0, 0, 8, 0},
                       {9, 0, 0, 8, 6, 3, 0, 0, 5},
                       {0, 5, 0, 0, 9, 0, 6, 0, 0},
                       {1, 3, 0, 0, 0, 0, 2, 5, 0},
                       {0, 0, 0, 0, 0, 0, 0, 7, 4},
                       {0, 0, 5, 2, 0, 6, 3, 0, 0}};
                       
     for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                std::cout << puzzle[i][j] << " ";
            std::cout << std::endl;
        }

std::cout << std::endl<< std::endl;
    // copy puzzle to grid
    memcpy(grid, puzzle, sizeof puzzle);

    if (solveSudoku())
    {
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
                std::cout << grid[i][j] << " ";
            std::cout << std::endl;
        }
    }
    else
        std::cout << "No solution exists." << std::endl;

    return 0;
}