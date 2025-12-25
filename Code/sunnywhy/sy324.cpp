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
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<int>> steps(n, vector<int>(m, -1));
    vector<vector<bool>> in_queue(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    q.push({0, 0});
    in_queue[0][0] = true;
    steps[0][0] += 1;
    
    int step = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !arr[newX][newY] && !in_queue[newX][newY])
                {
                    q.push({newX, newY});
                    in_queue[newX][newY] = true;
                    steps[newX][newY] = step + 1;
                }
            }
        }
        step++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            j == m - 1 ? cout << steps[i][j] << '\n' : cout << steps[i][j] << ' ';

    return 0;
}