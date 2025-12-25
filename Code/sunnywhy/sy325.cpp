#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<pair<int, int>> tp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                tp.push_back({i, j});
        }

    queue<pair<int, int>> q;
    vector<vector<int>> inqueue(n, vector<int>(m, false));
    q.push({0, 0});
    inqueue[0][0] = true;

    auto bfs = [&]() -> int
    {
        int steps = 0;
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt--)
            {
                pair<int, int> front = q.front();
                q.pop();
                if (front.first == n - 1 && front.second == m - 1)
                    return steps;
                for (int i = 0; i < 4; i++)
                {
                    int newX = front.first + xy[i][0];
                    int newY = front.second + xy[i][1];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && arr[newX][newY] != 1 && !inqueue[newX][newY])
                    {
                        if (arr[newX][newY] == 2)
                            for (auto i : tp)
                            {
                                q.push(i);
                                inqueue[i.first][i.second] = true;
                            }
                        else
                        {
                            q.push({newX, newY});
                            inqueue[newX][newY] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    };

    cout << bfs() << '\n';
    return 0;
}