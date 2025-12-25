#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n;
    cin >> n;
    vector<int> a(n + 1);
    a[0] = 3;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    
    vector<vector<int>> dp(n + 1, vector<int>(3, 1e9));
    dp[0][0] = 0, dp[0][1] = 0, dp[0][2] = 0;
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = min(dp[i - 1][0], min(dp[i - 1][1], dp[i - 1][2])) + 1;
        if (a[i] == 1)
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
        else if (a[i] == 2)
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
        else if (a[i] == 3)
        {
            dp[i][1] = min(dp[i - 1][2], dp[i - 1][0]);
            dp[i][2] = min(dp[i - 1][1], dp[i - 1][0]);
        }
    }

    cout << min(dp[n][0], min(dp[n][1], dp[n][2])) << '\n';
    return 0;
}