#include <bits/stdc++.h>

using namespace std;

void printBoard(vector<vector<int>> &board)
{
    for (auto i : board)
    {
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    cout << endl;
}

void tour(vector<vector<int>> &board, int r, int c, int n, int step)
{
    if (r >= n || c >= n || r < 0 || c < 0 || board[r][c] != 0)
        return;
    if (step == n * n)
    {
        board[r][c] = step;
        printBoard(board);
    }

    board[r][c] = step;
    // int x;
    // cin >> x;
    // printBoard(board);
    // cout << "R C " << r << " " << c << endl;
    tour(board, r - 2, c + 1, n, step + 1);
    tour(board, r - 1, c + 2, n, step + 1);
    tour(board, r + 1, c + 2, n, step + 1);
    tour(board, r + 2, c + 1, n, step + 1);
    tour(board, r + 2, c - 1, n, step + 1);
    tour(board, r + 1, c - 2, n, step + 1);
    tour(board, r - 1, c - 2, n, step + 1);
    tour(board, r - 2, c - 1, n, step + 1);
    board[r][c] = 0;
}

int main()
{
    int n, r, c;
    cin >> n >> r >> c;
    vector<vector<int>> board(n, vector<int>(n, 0));
    tour(board, r, c, n, 1);
    return 0;
}