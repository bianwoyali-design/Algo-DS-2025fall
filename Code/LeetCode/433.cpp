#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    int it = -1;

    bool compare(string a, string b)
    {
        int res = 0;
        for (int i = 0; i < 8; i++)
            if (a[i] != b[i])
                if (++res > 1)
                    return false;
        return true;
    }

    vector<vector<int>> transGraph(vector<string> &bank, string endGene)
    {
        vector<vector<int>> g(bank.size());
        for (int i = 0; i < bank.size(); i++)
        {
            if (bank[i] == endGene)
                it = i;
            for (int j = i + 1; j < bank.size(); j++)
            {
                if (compare(bank[i], bank[j]))
                {
                    g[i].push_back(j);
                    g[j].push_back(i);
                }
            }
        }
        return g;
    }

    int bfs(vector<vector<int>> &g, int st, int de)
    {
        queue<int> q;
        vector<bool> vis(g.size(), false);
        
        q.push(st);
        vis[st] = true;
        
        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int f = q.front();
                q.pop();

                if (f == de)
                    return steps;
                
                for (const auto &u : g[f])
                    if (!vis[u])
                    {
                        vis[u] = true;
                        q.push(u);
                    }
            }
            steps++;
        }

        return -1;
    }
public:
    int minMutation(string startGene, string endGene, vector<string> &bank)
    {
        if (bank.empty())
            return -1;
        bank.push_back(startGene);
        vector<vector<int>> g = transGraph(bank, endGene);
        if (it == -1)
            return -1;
        return bfs(g, bank.size() - 1, it);
    }
};

int main()
{
    Solution sol;
    string startGene = "AAAAAAAT", endGene = "CCCCCCCC";
    vector<string> bank = {"AAAAAAAC","AAAAAAAA","CCCCCCCC"};
    cout << sol.minMutation(startGene, endGene, bank) << '\n';
    return 0;
}