#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int xy[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);
        for (int i = 0; i < n; i++)
            cin >> matrix[i];

        auto dfs = [&](auto &&dfs, int x, int y, int cnt) -> int
        {
            matrix[x][y] = '.';
            for (int i = 0; i < 8; i++)
            {
                int newX = x + xy[i][0];
                int newY = y + xy[i][1];
                if (newX >= 0 && newX < matrix.size() && newY >= 0 && newY < matrix[0].size() && matrix[newX][newY] == 'W')
                    cnt = dfs(dfs, newX, newY, cnt + 1);
            }
            return cnt;
        };

        int maxN = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 'W')
                    maxN = max(maxN, dfs(dfs, i, j, 1));
        cout << maxN << '\n';
    }
    return 0;
}