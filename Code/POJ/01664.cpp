#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int maxm = 0, maxn = 0;
    vector<vector<int>> apple(n, vector<int>(2));
    for (int i = 0; i < n; i++)
    {
        cin >> apple[i][0] >> apple[i][1];
        maxm = max(maxm, apple[i][0]);
        maxn = max(maxn, apple[i][1]);
    }

    vector<vector<int>> dp(maxm + 1, vector<int>(maxn + 1, 0));
    dp[1][1] = 1;
    for (int i = 1; i <= maxm; i++)
        for (int j = 1; j <= maxn; j++)
        {
            if (i < j)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i][j - 1] + dp[i - 1][j - 1] + dp[i - j][j];
        }
    
    for (const auto &i : apple)
    {
        int ans = 0;
        for (int j = 1; j <= i[1]; j++)
            ans += dp[i[0]][j];
        cout << ans << '\n';
    }
    
    return 0;
}