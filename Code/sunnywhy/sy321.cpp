#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Node
{
    int x, y;
};

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

    vector<vector<bool>> in_queue(n, vector<bool>(m, false));
    vector<vector<Node>> pos(n, vector<Node>(m, {-1, -1}));
    auto bfs = [&](Node start) -> void
    {
        queue<Node> q;
        q.push(start);
        in_queue[start.x][start.y] = true;

        while (!q.empty())
        {
            Node front = q.front();
            q.pop();
            if (front.x == n - 1 && front.y == m - 1)
                return;
            for (int i = 0; i < 4; i++)
            {
                Node next;
                next.x = front.x + xy[i][0];
                next.y = front.y + xy[i][1];
                if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m && !arr[next.x][next.y] && !in_queue[next.x][next.y])
                {
                    q.push(next);
                    in_queue[next.x][next.y] = true;
                    pos[next.x][next.y] = {front.x, front.y};
                }
            }
        }
    };

    auto print = [&](auto &&print, Node end) -> void
    {
        Node prev = pos[end.x][end.y];
        if (prev.x == -1 && prev.y == -1)
        {
            cout << end.x + 1 << ' ' << end.y + 1 << '\n';
            return;
        }
        print(print, prev);
        cout << end.x + 1 << ' ' << end.y + 1 << '\n';
    };

    bfs({0, 0});
    print(print, {n - 1, m - 1});

    return 0;
}