#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n != 0)
    {
        queue<pair<string, int>> q;
        vector<bool> vis(n, false);
        q.push({"1", 1 % n});
        vis[1 % n] = true;

        while (!q.empty())
        {
            auto [s, r] = q.front();
            q.pop();

            if (r == 0)
            {
                cout << s << '\n';
                break;
            }

            int newR = r * 10 % n;
            if (!vis[newR] && s.size() < 100)
            {
                vis[newR] = true;
                q.push({s + '0', newR});
            }
            newR = (r * 10 + 1) % n;
            if (!vis[newR] && s.size() < 100)
            {
                vis[newR] = true;
                q.push({s + '1', newR});
            }
        }
    }
    return 0;
}