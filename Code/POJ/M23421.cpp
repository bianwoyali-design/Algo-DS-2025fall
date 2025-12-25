#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, b;
    cin >> n >> b;

    vector<vector<int>> dp(n + 1, vector<int>(b + 1, 0));
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= b; j++)
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
    
    cout << dp[n][b] << '\n';
    return 0;
}