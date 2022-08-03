#include <bits/stdc++.h>
using namespace std;
vector<vector<vector<int>>> ans;

void nQueen(vector<vector<int>> board, int n, int row)
{
    if (row == n)
    {
        ans.push_back(board);
        return;
    }
    
    for (int col = 0; col < n; col++)
    {
        // Check towards upward 
        bool flag = true;
        for (int i = row-1; i >= 0; i--)
        {
            if(board[i][col] == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
            continue;

        // check towards left upward
        for (int i = row-1, j = col-1; i>=0 && j >= 0; i--, j--)
        {
            if(board[i][j] == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
            continue;
        
        // check towards right upward
        for (int i = row-1, j = col+1; i>=0 && j < n; i--, j++)
        {
            if(board[i][j] == 1)
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
            continue;

        board[row][col] = 1;
        nQueen(board, n, row + 1);
        board[row][col] = 0;
    }
    return;
}
int main()
{
    int n;
    cin >> n;
    vector<vector<int>> board(n, vector<int>(n, 0));

    nQueen(board, n, 0);
    for (int k = 0; k < ans.size(); k++)
    {
        cout<<k+1<<endl;
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                cout << ans[k][i][j] << " ";
            }
            cout << endl;
        }
        cout<<endl;
    }

    return 0;
}