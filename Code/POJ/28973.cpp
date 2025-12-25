#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    queue<pair<pair<int, int>, int>> q;
    vector<vector<vector<bool>>> inqueue(n, vector<vector<bool>>(n, vector<bool>(2, false)));
    int steps = 0;
    int ans = -1;

    q.push({{0, 0}, 0});
    inqueue[0][0][0] = true;
    while (!q.empty())
    {
        int sz = q.size();
        while (sz--)
        {
            pair<pair<int, int>, int> front = q.front();
            q.pop();
            int x = front.first.first;
            int y = front.first.second;
            int towards = front.second;

            if (x == n - 1 && y == n - 2 && towards == 0)
            {
                ans = steps;
                break;
            }

            if (towards == 0)
            {
                if (y + 2 < n && !arr[x][y + 2] && !inqueue[x][y + 1][0])
                {
                    q.push({{x, y + 1}, 0});
                    inqueue[x][y + 1][0] = true;
                }
                if (x + 1 < n && y + 1 < n && !arr[x + 1][y] && !arr[x + 1][y + 1])
                {
                    if (!inqueue[x + 1][y][0])
                    {
                        q.push({{x + 1, y}, 0});
                        inqueue[x + 1][y][0] = true;
                    }
                    if (!inqueue[x][y][1])
                    {
                        q.push({{x, y}, 1});
                        inqueue[x][y][1] = true;
                    }
                }
            }
            if (towards == 1)
            {
                if (x + 2 < n && !arr[x + 2][y] && !inqueue[x + 1][y][1])
                {
                    q.push({{x + 1, y}, 1});
                    inqueue[x + 1][y][1] = true;
                }
                if (x + 1 < n && y + 1 < n && !arr[x][y + 1] && !arr[x + 1][y + 1])
                {
                    if (!inqueue[x][y + 1][1])
                    {
                        q.push({{x, y + 1}, 1});
                        inqueue[x][y + 1][1] = true;
                    }
                    if (!inqueue[x][y][0])
                    {
                        q.push({{x, y}, 0});
                        inqueue[x][y][0] = true;
                    }
                }
            }
        }
        steps++;
    }
    cout << ans << '\n';
    return 0;
}