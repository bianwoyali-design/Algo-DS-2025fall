#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;
    int minn = 1e9, maxn = 0;
    vector<int> a(t);
    vector<int> b(t);
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> b[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, b[i]);
    }

    vector<int> dp(maxn + 1);
    for (int i = 0; i < k; i++)
        dp[i] = 1;
    for (int i = k; i <= maxn; i++)
        dp[i] = (dp[i - 1] + dp[i - k]) % int(1e9 + 7);

    vector<int> pre(maxn + 1, 0);
    for (int i = 1; i <= maxn; i++)
        pre[i] = (pre[i - 1] + dp[i]) % int(1e9 + 7);
        
    for (int i = 0; i < t; i++)
        cout << (pre[b[i]] - pre[a[i] - 1] + int(1e9 + 7)) % int(1e9 + 7) << '\n';

    return 0;
}