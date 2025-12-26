#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        int ans = 0;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (i > 0 && i < n)
                ans += abs(a[i] - a[i - 1]);
        }
        
        int maxn = 0;
        for (int i = 0; i < n; i++)
        {
            if (i == 0)
                maxn = max(abs(a[i] - a[i + 1]), maxn);
            else if (i == n - 1)
                maxn = max(abs(a[i] - a[i - 1]), maxn);
            else
                maxn = max(maxn, abs(a[i - 1] - a[i]) + abs(a[i] - a[i + 1]) - abs(a[i - 1] - a[i + 1]));
        }
        cout << ans - maxn << '\n';
    }

    return 0;
}