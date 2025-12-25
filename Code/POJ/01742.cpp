#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && n && m)
    {
        vector<int> A(n + 1), C(n + 1);
        for (int i = 1; i <= n; i++)
            cin >> A[i];
        for (int i = 1; i <= n; i++)
            cin >> C[i];

        vector<bool> dp(m + 1, false);
        dp[0] = true;

        for (int i = 1; i <= n; i++)
        {
            vector<int> used(m + 1, 0);
            for (int j = A[i]; j <= m; j++)
                if (!dp[j] && dp[j - A[i]] && used[j - A[i]] < C[i])
                {
                    dp[j] = true;
                    used[j] = used[j - A[i]] + 1;
                }
        }

        int ans = count(dp.begin() + 1, dp.end(), true);
        cout << ans << '\n';
    }
    return 0;
}
