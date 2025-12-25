#include <iostream>
#include <climits>
#include <queue>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k, s;
    cin >> n >> k >> s;
    vector<vector<int>> arr(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> arr[i][j];

    vector<int> steps_p(n, INT_MAX);
    vector<int> steps_q(n, INT_MAX);
    queue<int> q, p;

    steps_q[k] = 0;
    q.push(k);

    steps_p[s] = 0;
    p.push(s);

    int min_dis = INT_MAX;
    auto expand_and_check = [&](queue<int> &curr, vector<int> &steps_a, vector<int> &steps_b)
    {
        int u = curr.front();
        curr.pop();
        int u_step = steps_a[u];

        if (u_step >= min_dis)
            return;

        for (int v = 0; v < n; v++)
            if (arr[u][v])
            {
                if (steps_a[v] == INT_MAX)
                {
                    curr.push(v);
                    steps_a[v] = u_step + 1;
                }
                if (steps_b[v] != INT_MAX)
                    if (steps_a[v] == steps_b[v])
                        min_dis = min(min_dis, steps_a[v]);
            }
    };

    while (!q.empty() || !p.empty())
    {
        if (!q.empty())
            expand_and_check(q, steps_q, steps_p);
        if (!p.empty())
            expand_and_check(p, steps_p, steps_q);
    }

    if (min_dis == INT_MAX)
        cout << "-1\n";
    else
        cout << min_dis << '\n';
    return 0;
}