#include <iostream>
using namespace std;

int dp[201][7];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (i < j)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    cout << dp[n][k];
    return 0;
}