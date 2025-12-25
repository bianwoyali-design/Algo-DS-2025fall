#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class Solution
{
private:
    int xy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};

public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat)
    {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, -1));
        priority_queue<pair<int, int>> q;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (mat[i][j] == 0)
                {
                    res[i][j] = 0;
                    q.push({i, j});
                }

        while (!q.empty())
        {
            auto [x, y] = q.top();
            q.pop();
            for (const auto &i : xy)
            {
                int newX = x + i[0];
                int newY = y + i[1];
                if (newX >= 0 && newX < m && newY >= 0 && newY < n && res[newX][newY] == -1)
                {
                    q.push({newX, newY});
                    res[newX][newY] = res[x][y] + 1;
                }
            }
        }

        return res;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {0, 0, 0}};
    Solution Sol;
    for (const auto &i : Sol.updateMatrix(mat))
    {
        for (const auto &j : i)
            cout << j << ' ';
        cout << '\n';
    }

    return 0;
}