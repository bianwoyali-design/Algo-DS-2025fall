#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cut[3];
    for (int i = 0; i < 3; i++)
        cin >> cut[i];

    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            if (i >= cut[j])
                dp[i] = max(dp[i], dp[i - cut[j]] + 1);
    
    cout << dp[n] << '\n';
    return 0;
}