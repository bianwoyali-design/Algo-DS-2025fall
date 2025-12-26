#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

void fillBlock(vector<vector<int>> &mat, int r, int c, int size)
{
    if (size == 0)
        return;

    for (int i = r; i < r + size; i++)
        for (int j = c; j < c + size; j++)
            mat[i][j] = 0;

    int half = size / 2;
    fillBlock(mat, r + size, c, half);
    fillBlock(mat, r, c + size, half);
    fillBlock(mat, r + size, c + size, half);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;

    int size = pow(2, n);
    vector<vector<int>> mat(size, vector<int>(size, 1));

    fillBlock(mat, 0, 0, size / 2);

    for (const auto &row : mat)
    {
        for (int val : row)
            cout << val << ' ';
        cout << '\n';
    }

    return 0;
}