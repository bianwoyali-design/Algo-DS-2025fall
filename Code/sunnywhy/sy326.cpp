#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    queue<pair<int, int>> q;
    vector<vector<bool>> inqueue(n, vector<bool>(m, false));
    vector<vector<int>> step(n, vector<int>(m, -1));
    q.push({x - 1, y - 1});
    inqueue[x - 1][y - 1] = true;
    step[x - 1][y - 1] += 1;

    int steps = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !inqueue[newX][newY])
                {
                    q.push({newX, newY});
                    inqueue[newX][newY] = true;
                    step[newX][newY] = steps + 1;
                }
            }
        }
        steps++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            j == m - 1 ? cout << step[i][j] << '\n' : cout << step[i][j] << ' ';

    return 0;
}