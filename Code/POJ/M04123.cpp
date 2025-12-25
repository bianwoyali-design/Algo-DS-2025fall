#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int xy[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    cin >> T;
    while (T--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int cnt = 0;
        vector<vector<bool>> valid(n, vector<bool>(m, false));
        auto dfs = [&](auto &&dfs, int desX, int desY, int step) -> void
        {
            if (step == n * m)
            {
                cnt++;
                return;
            }
            valid[desX][desY] = true;
            for (int i = 0; i < 8; i++)
            {
                int newX = desX + xy[i][0];
                int newY = desY + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !valid[newX][newY])
                    dfs(dfs, newX, newY, step + 1);
            }
            valid[desX][desY] = false;
        };

        dfs(dfs, x, y, 1);

        cout << cnt << '\n';
    }
    return 0;
}