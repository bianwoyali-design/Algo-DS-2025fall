#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, a, b;
    cin >> n >> a >> b;
    vector<int> p(n);
    for (auto &i : p)
        cin >> i;
    int l = 0, r = p.size() - 1;
    int wl = a, wr = b;
    int ans = 0;
    while (l <= r)
    {
        if (l == r)
            if (wl >= wr)
            {
                wl -= p[l];
                if (wl < 0)
                {
                    ans++;
                    wl = a - p[l];
                }
                l++;
            }
            else
            {
                wr -= p[r];
                if (wr < 0)
                {
                    ans++;
                    wr = b - p[r];
                }
                r--;
            }
        else
        {
            wl -= p[l];
            if (wl < 0)
            {
                ans++;
                wl = a - p[l];
            }
            wr -= p[r];
            if (wr < 0)
            {
                ans++;
                wr = b - p[r];
            }
            l++, r--;
        }
    }
    cout << ans << '\n';
    return 0;
}