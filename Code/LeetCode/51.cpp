#include <iostream>
#include <vector>
using namespace std;

vector<int> row;

bool is_Valid(int x, int y)
{
    for (int i = 0; i < x; i++)
        if (row[i] == y || abs(x - i) == abs(y - row[i]))
            return false;
    return true;
}

void solve(int n, vector<vector<string>>& q, int x)
{
    if (x == n)
    {
        vector<string> tmp(n, string(n, '.'));
        for (int i = 0; i < row.size(); i++)
            tmp[i][row[i]] = 'Q';
        q.push_back(tmp);
        return;
    }
    for (int i = 0; i < n; i++)
        if (is_Valid(x, i))
        {
            row.push_back(i);
            solve(n, q, x + 1);
            row.pop_back();
        }
}

vector<vector<string>> solveNQueens(int n)
{
    vector<vector<string>> ans;
    solve(n, ans, 0);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n = 4;
    for (auto i : solveNQueens(n))
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}