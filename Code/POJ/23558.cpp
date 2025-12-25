#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
private:
    int n, m, l, st;
    vector<int> g[100];
    vector<int> ans;
    void dfs(vector<bool> &vis, int st, int depth)
    {
        if (depth == l)
            return;
        for (const auto &u : g[st])
            if (!vis[u])
            {
                vis[u] = true;
                ans.push_back(u);
                dfs(vis, u, depth + 1);
            }
    }

public:
    void readInput()
    {
        cin >> n >> m >> l;
        for (int i = 0; i < m; i++)
        {
            int a, b;
            cin >> a >> b;
            g[a].push_back(b);
            g[b].push_back(a);
        }
        for (auto &u : g)
            sort(u.begin(), u.end());
        cin >> st;
    }
    void outPut()
    {
        vector<bool> vis(100, false);
        vis[st] = true;
        ans.push_back(st);
        dfs(vis, st, 0);
        for (const auto &a : ans)
            cout << a << ' ';
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    Solution sol;
    sol.readInput();
    sol.outPut();
    return 0;
}