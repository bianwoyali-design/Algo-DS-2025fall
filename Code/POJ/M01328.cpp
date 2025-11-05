#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

struct Node
{
    double l, r;
} p[1001];

bool cmp(Node x, Node y)
{
    if (x.r != y.r) return x.r < y.r;
    return x.l < y.l;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int cnt = 0;
    while (true)
    {
        int n, d;
        cin >> n >> d;
        bool flag = false;
        if (n == 0 && d == 0)
            break;
        for (int i = 0; i < n; i++)
        {
            int x, y;
            cin >> x >> y;
            if (y > d)
                flag = true;
            else
            {
                double half = sqrt((double)d * d - (double)y * y);
                p[i].l = x - half;
                p[i].r = x + half;
            }
        }
        if (flag)
            cout << "Case " << ++cnt << ": " << -1 << '\n';
        else
        {
            sort(p, p + n, cmp);
            int ans = 0;
            double it = -1e100;
            for (int i = 0; i < n; i++)
                if (i == 0 || it < p[i].l)
                {
                    ans++;
                    it = p[i].r;
                }
            cout << "Case " << ++cnt << ": " << ans << '\n';
        }
    }
    return 0;
}