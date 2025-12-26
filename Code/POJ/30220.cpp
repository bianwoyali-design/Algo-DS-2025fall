#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int n, m;
    cin >> n >> m;
    bool flag = false;
    vector<vector<int>> mat(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> mat[i][j];
            if (mat[i][j] < 0)
                flag = true;
        }

    if (flag == false)
    {
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
                dp[i][j] = max(dp[i - 1][j] + mat[i - 1][j - 1], dp[i][j - 1] + mat[i - 1][j - 1]);
        cout << dp[n][m] << '\n';
    }
    else
    {
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(m + 1, vector<int>(2, -1e9)));
        dp[1][1][0] = mat[0][0];
        if (mat[0][0] < 0)
            dp[1][1][1] = -mat[0][0];
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++)
            {
                if (i == 1 && j == 1) continue; 
                dp[i][j][0] = max(dp[i - 1][j][0] + mat[i - 1][j - 1], dp[i][j - 1][0] + mat[i - 1][j - 1]);
                dp[i][j][1] = max(dp[i - 1][j][1] + mat[i - 1][j - 1], dp[i][j - 1][1] + mat[i - 1][j - 1]);
                if (mat[i - 1][j - 1] < 0)
                    dp[i][j][1] = max(dp[i][j][1], max(dp[i - 1][j][0] - mat[i - 1][j - 1], dp[i][j - 1][0] - mat[i - 1][j - 1]));
            }
        cout << max(dp[n][m][0], dp[n][m][1]) << '\n';
    }
    return 0;
}