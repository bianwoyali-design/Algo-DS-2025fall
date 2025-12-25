#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    string s;
    cin >> s;
    int n = s.length();
    vector<vector<int>> dp(n + 1, vector<int>(2, 0));
    for (int i = 1; i <= n; i++)
    {
        dp[i][0] = (s[i - 1] == 'R' ? dp[i - 1][0] : min(dp[i - 1][1] + 1, dp[i - 1][0] + 1));
        dp[i][1] = (s[i - 1] == 'B' ? dp[i - 1][1] : min(dp[i - 1][0] + 1, dp[i - 1][1] + 1));
    }

    cout << dp[n][0] << '\n';
    return 0;
}