#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> dp(N + 2);
    dp[0] = 0, dp[1] = 1, dp[2] = 2;
    for (int i = 3; i <= N; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    
    cout << dp[N] << '\n';
    return 0;
}