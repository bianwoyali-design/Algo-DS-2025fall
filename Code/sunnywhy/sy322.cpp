#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {2, 0}, {0, 2}, {-2, 0}, {0, -2}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    queue<pair<int, int>> q;
    vector<vector<bool>> in_queue(n, vector<bool>(m, false));
    int steps = 0;
    q.push({0, 0});
    in_queue[0][0] = true;

    auto bfs = [&]() -> int
    {
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt--)
            {
                pair<int, int> front;
                front = q.front();
                q.pop();
                if (front.first == n - 1 && front.second == m - 1)
                    return steps;
                for (int i = 0; i < 8; i++)
                {
                    int newX = front.first + xy[i][0];
                    int newY = front.second + xy[i][1];
                    int HalfnewX = front.first + xy[i][0] / 2;
                    int HalfnewY = front.second + xy[i][1] / 2;
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && !in_queue[newX][newY] && !arr[newX][newY] && !arr[HalfnewX][HalfnewY])
                    {
                        q.push({newX, newY});
                        in_queue[newX][newY] = true;
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