#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int p, m, n;

class Dijkstra
{
private:
    struct Node
    {
        int x;
        long long w;
        bool operator>(const Node &u) const { return w > u.w; };
    };
    vector<vector<Node>> g;

public:
    vector<vector<int>> mat;

    vector<long long> dis;

    void readInput_n_transGraph()
    {
        cin >> m >> n >> p;
        vector<vector<int>> arr(m, vector<int>(n));
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
            {
                string s;
                cin >> s;
                if (s == "#")
                    arr[i][j] = 1e9;
                else
                    arr[i][j] = stoi(s);
            }
        
        mat = arr;
        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        g.assign(m * n, vector<Node>());
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                if (arr[i][j] != 1e9)
                {
                    int x = i * n + j;
                    for (int k = 0; k < 4; k++)
                    {
                        int newX = i + dir[k][0], newY = j + dir[k][1];
                        if (newX >= 0 && newX < m && newY >= 0 && newY < n && arr[newX][newY] != 1e9)
                        {
                            int y = newX * n + newY;
                            g[x].push_back({y, abs(arr[i][j] - arr[newX][newY])});
                        }
                    }
                }
    }

    void dijkstra(int st)
    {
        dis.assign(m * n, 2e18);
        priority_queue<Node, vector<Node>, greater<Node>> pq;
        vector<bool> vis(m * n, false);

        dis[st] = 0;
        pq.push(Node{st, 0});

        while (!pq.empty())
        {
            int x = pq.top().x;
            pq.pop();
            if (vis[x])
                continue;
            vis[x] = true;
            for (const auto &u : g[x])
            {
                int y = u.x;
                long long w = u.w;
                if (dis[y] > dis[x] + w)
                {
                    dis[y] = dis[x] + w;
                    pq.push(Node{y, dis[y]});
                }
            }
        }
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Dijkstra sol;
    sol.readInput_n_transGraph();
    while (p--)
    {
        int stx, sty, dex, dey;
        cin >> stx >> sty >> dex >> dey;
        if (sol.mat[stx][sty] == 1e9 || sol.mat[dex][dey] == 1e9)
            cout << "NO\n";
        else
        {
            sol.dijkstra(stx * n + sty);
            cout << (sol.dis[dex * n + dey] == 2e18 ? "NO" : to_string(sol.dis[dex * n + dey])) << '\n';
        }
    }
    return 0;
}