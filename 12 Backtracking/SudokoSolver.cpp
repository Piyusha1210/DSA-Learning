#include <bits/stdc++.h>
using namespace std;

bool isValid(vector<vector<int>> sudoku, int row, int col, int k)
{
    for (int i = 1; i < 9; i++)
    {
        // Row Check
        if (sudoku[row][i] == k)
            return false;

        // Col Check
        if (sudoku[i][col] == k)
            return false;
    }
    for (int i = 3 * (row / 3); i < 3 * (row / 3 + 1); i++)
    {
        for (int j = 3 * (col / 3); j < 3 * (col / 3 + 1); j++)
        {
            if (sudoku[i][j] == k)
                return false;
        }
    }
    return true;
}

bool sudokuSolver(vector<vector<int>> &sudoku)
{
    for (int i = 0; i < 9; i++)
    {
        for (int j = 0; j < 9; j++)
        {
            if (sudoku[i][j] != 0)
                continue;

            for (int k = 1; k <= 9; k++)
            {
                if (isValid(sudoku, i, j, k))
                {
                    sudoku[i][j] = k;
                    bool possible = sudokuSolver(sudoku);
                    if (possible)
                        return true;
                    else
                        sudoku[i][j] = 0;
                }
            }
            return false;
        }
    }
    return true;
}

int main()
{
    int n = 9;
    vector<vector<int>> sudoku(9, vector<int>(9, 0));
    cout << "ENTER SUDOKU INPUT ->\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> sudoku[i][j];
        }
    }
    cout << endl;
    if (sudokuSolver(sudoku))
    {
        for (int i = 0; i < n; i++)
        {
            if (i % 3 == 0)
            {
                for (int j = 0; j < 25; j++)
                {
                    cout << "-";
                }
                cout << endl;
            }
            for (int j = 0; j < n; j++)
            {
                if (j % 3 == 0)
                    cout << "| ";
                cout << sudoku[i][j] << " ";
                if (j + 1 == 9)
                    cout << "|";
            }
            cout << endl;
        }
    }
    else
    {
        cout << "INVALID SUDOKU\n";
        return 0;
    }
    for (int j = 0; j < 25; j++)
    {
        cout << "-";
    }
    cout << endl
         << endl;
    return 0;
}

/*
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
*/