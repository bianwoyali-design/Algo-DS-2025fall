#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    size_t n, m = 0;
    cin >> n;
    map<size_t, size_t> a;
    for (size_t i = 0; i < n; i++)
    {
        size_t num;
        cin >> num;
        m = max(m, num);
        a[num]++;
    }
    vector<vector<size_t>> dp(m + 1, vector<size_t>(2, 0));
    for (size_t i = 1; i <= m; i++)
    {
        dp[i][0] = max(dp[i - 1][0], dp[i - 1][1]);
        dp[i][1] = dp[i - 1][0] + a[i] * i;
    }

    cout << max(dp[m][0], dp[m][1]) << '\n';
    return 0;
}