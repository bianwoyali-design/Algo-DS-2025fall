#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    const int INF = 1e9;
    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1][0] = 0; // 只从0号城市出发

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + mat[u][v]);
            }
        }
    }

    int res = INF;
    for (int i = 1; i < n; i++)
        res = min(res, dp[N - 1][i] + mat[i][0]); // 回到0号城市
    cout << res << '\n';
    return 0;
}