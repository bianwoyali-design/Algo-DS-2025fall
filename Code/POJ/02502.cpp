#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
using namespace std;

struct Node
{
    int x, y;
};

double dist(const Node &a, const Node &b)
{
    return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int stX, stY, deX, deY;
    cin >> stX >> stY >> deX >> deY;
    vector<Node> pts;
    pts.push_back({stX, stY});
    pts.push_back({deX, deY});

    vector<vector<int>> subway_lines;
    int x, y;
    while (cin >> x >> y)
    {
        if (x == -1 && y == -1)
            break;
        vector<int> line;
        pts.push_back({x, y});
        line.push_back(pts.size() - 1);
        while (cin >> x >> y && !(x == -1 && y == -1))
        {
            pts.push_back({x, y});
            line.push_back(pts.size() - 1);
        }
        subway_lines.push_back(line);
    }

    int n = pts.size();
    vector<vector<pair<int, double>>> g(n);

    for (auto &line : subway_lines)
    {
        for (int i = 1; i < line.size(); ++i)
        {
            double t = dist(pts[line[i - 1]], pts[line[i]]) / 40000.0 * 60.0;
            g[line[i - 1]].push_back({line[i], t});
            g[line[i]].push_back({line[i - 1], t});
        }
    }
    for (int i = 0; i < n; ++i)
        for (int j = i + 1; j < n; ++j)
        {
            double t = dist(pts[i], pts[j]) / 10000.0 * 60.0;
            g[i].push_back({j, t});
            g[j].push_back({i, t});
        }

    vector<double> dis(n, 1e18);
    priority_queue<pair<double, int>, vector<pair<double, int>>, greater<>> pq;
    dis[0] = 0;
    pq.push({0, 0});
    while (!pq.empty())
    {
        auto [d, u] = pq.top();
        pq.pop();
        if (d > dis[u])
            continue;
        for (auto &[v, w] : g[u])
        {
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                pq.push({dis[v], v});
            }
        }
    }
    cout << int(dis[1] + 0.5) << '\n';
    return 0;
}