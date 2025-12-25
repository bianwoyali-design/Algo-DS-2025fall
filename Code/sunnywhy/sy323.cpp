#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;
bool in_queue[101][101]{false};
char arr[101][101];
pair<int, int> start, termination;

int bfs(int n, int m)
{
    q.push(start);
    in_queue[start.first][start.second] = true;

    int steps = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            if (front.first == termination.first && front.second == termination.second)
                return steps;
            for (int i = 0; i < 4; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !in_queue[newX][newY] && arr[newX][newY] != '*')
                {
                    q.push({newX, newY});
                    in_queue[newX][newY] = true;
                }
            }
        }
        steps++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
                start = {i, j};
            if (arr[i][j] == 'T')
                termination = {i, j};
        }
    
    cout << bfs(n, m) << '\n';
    return 0;
}