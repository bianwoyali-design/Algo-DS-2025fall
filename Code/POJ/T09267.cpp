#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<long long> dp(n + 1, 0);
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        if (i < m)
            dp[i] = 2 * dp[i - 1];
        else if (i == m)
            dp[i] = 2 * dp[i - 1] - 1;
        else
            dp[i] = 2 * dp[i - 1] - dp[i - m - 1];
    
    cout << dp[n] << '\n';
    return 0;
}