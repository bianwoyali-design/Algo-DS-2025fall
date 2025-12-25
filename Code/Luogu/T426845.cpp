#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, V1, V2;
    cin >> n >> V1 >> V2;
    vector<int> cost1(n), cost2(n), price(n);
    for (int i = 0; i < n; i++)
        cin >> cost1[i] >> cost2[i] >> price[i];
    
    vector<vector<int>> dp(V1 + 1, vector<int>(V2 + 1, 0));
    for (int i = 0; i < n; i++)
        for (int c1 = V1; c1 >= cost1[i]; c1--)
            for (int c2 = V2; c2 >= cost2[i]; c2--)
                dp[c1][c2] = max(dp[c1][c2], dp[c1 - cost1[i]][c2 - cost2[i]] + price[i]);
    cout << dp[V1][V2] << '\n';
    return 0;
}