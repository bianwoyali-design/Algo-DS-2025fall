#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
private:
    vector<int> transFormation(vector<vector<int>> &board)
    {
        vector<int> g;
        g.push_back(0);
        bool flag = false;
        for (int i = board.size() - 1; i >= 0; i--)
            if (!flag)
            {
                for (int j = 0; j < board[i].size(); j++)
                    g.push_back(board[i][j]);
                flag = true;
            }
            else
            {
                for (int j = board[i].size() - 1; j >= 0; j--)
                    g.push_back(board[i][j]);
                flag = false;
            }
        return g;
    }

    int bfs(vector<int> &g)
    {
        queue<int> q;
        vector<bool> vis(g.size(), false);

        q.push(1);
        vis[1] = true;

        int steps = 0;
        while (!q.empty())
        {
            int sz = q.size();
            while (sz--)
            {
                int f = q.front();
                q.pop();

                if (f == g.size() - 1)
                    return steps;

                int curr;
                for (int i = 1; i <= 6; i++)
                {
                    curr = f + i;
                    if (curr > g.size() - 1)
                        break;
                    int next = (g[curr] == -1) ? curr : g[curr];
                    if (!vis[next])
                    {
                        vis[next] = true;
                        q.push(next);
                    }
                }
            }
            steps++;
        }
        return -1;
    }

public:
    int snakesAndLadders(vector<vector<int>> &board)
    {
        vector<int> g = transFormation(board);
        return bfs(g);
    }
};