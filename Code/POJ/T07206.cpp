#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

const int N = 11;

class Solution
{
private:
    vector<pair<int, int>> bfs(const pair<int, int> &start, const pair<int, int> &end, const vector<vector<bool>> &obs)
    {
        vector<tuple<int, int, int, int>> moves = {
            {2, 1, 1, 0}, {2, -1, 1, 0},
            {-2, 1, -1, 0}, {-2, -1, -1, 0},
            {1, 2, 0, 1}, {-1, 2, 0, 1},
            {1, -2, 0, -1}, {-1, -2, 0, -1}};

        vector<vector<int>> dist(N, vector<int>(N, -1));
        vector<vector<int>> ways(N, vector<int>(N, 0));
        vector<vector<pair<int, int>>> prev(N, vector<pair<int, int>>(N, {-1, -1}));

        queue<pair<int, int>> q;
        
        auto [sx, sy] = start;
        auto [ex, ey] = end;
        
        dist[sx][sy] = 0;
        ways[sx][sy] = 1;
        prev[sx][sy] = {sx, sy};
        q.push(start);

        while (!q.empty())
        {
            auto [x, y] = q.front();
            q.pop();
            int d = dist[x][y];

            for (auto [dx, dy, bx, by] : moves)
            {
                int legx = x + bx;
                int legy = y + by;
                if (legx >= 0 && legx < N && legy >= 0 && legy < N && obs[legx][legy])
                    continue;

                int nx = x + dx;
                int ny = y + dy;
                if (nx < 0 || nx >= N || ny < 0 || ny >= N)
                    continue;
                if (obs[nx][ny])
                    continue;

                int nd = d + 1;

                if (dist[nx][ny] == -1)
                {
                    dist[nx][ny] = nd;
                    ways[nx][ny] = ways[x][y];

                    if (ways[x][y] == 1)
                        prev[nx][ny] = {x, y};
                    else
                        prev[nx][ny] = {-2, -2};

                    q.push({nx, ny});
                }
                else if (nd == dist[nx][ny])
                {
                    ways[nx][ny] += ways[x][y];
                    prev[nx][ny] = {-2, -2};
                }
            }
        }

        vector<pair<int, int>> path;
        
        if (dist[ex][ey] == -1)
            return path;
        
        if (ways[ex][ey] > 1)
        {
            path.push_back({ways[ex][ey], 0});
            return path;
        }

        pair<int, int> cur = {ex, ey};
        while (cur.first != -2 && !(cur.first == sx && cur.second == sy))
        {
            path.push_back(cur);
            cur = prev[cur.first][cur.second];
        }
        path.push_back({sx, sy});
        reverse(path.begin(), path.end());

        return path;
    }

public:
    void solve()
    {
        int sx, sy, ex, ey;
        cin >> sx >> sy >> ex >> ey;

        int M;
        cin >> M;

        vector<vector<bool>> obs(N, vector<bool>(N, false));
        for (int i = 0; i < M; i++)
        {
            int r, c;
            cin >> r >> c;
            obs[r][c] = true;
        }

        vector<pair<int, int>> result = bfs({sx, sy}, {ex, ey}, obs);

        if (result.size() == 1 && result[0].first > 0 && result[0].second == 0)
        {
            cout << result[0].first << '\n';
            return;
        }

        for (size_t i = 0; i < result.size(); i++)
        {
            cout << "(" << result[i].first << "," << result[i].second << ")";
            if (i != result.size() - 1)
                cout << "-";
        }
        cout << '\n';
    }
};

int main()
{
    Solution sol;
    sol.solve();
    return 0;
}