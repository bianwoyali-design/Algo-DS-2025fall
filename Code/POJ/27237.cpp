#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    while (cin >> n >> m)
    {
        if (n == 0 && m == 0)
            break;
        map<int, bool> inqueue;
        queue<pair<int, string>> pq;

        pq.push({n, ""});
        inqueue[n] = true;

        while (!pq.empty())
        {
            auto [f, g] = pq.front();
            pq.pop();

            if (f == m)
            {
                cout << g.size() << '\n' << g << '\n';
                break;
            }

            int newf = f * 3;
            string newg = g + 'H';
            if (!inqueue[newf])
            {
                inqueue[newf] = true;
                pq.push({newf, newg});
            }

            newf = f / 2;
            newg = g + 'O';
            if (newf > 0 && !inqueue[newf])
            {
                inqueue[newf] = true;
                pq.push({newf, newg});
            }
        }
    }
    return 0;
}