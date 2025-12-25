#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    int price[7] = {50, 100, 250, 500, 1000, 2500, 5000};
    int cnt[7];
    for (int i = 0; i < 7; i++)
        cin >> cnt[i];
    
    vector<int> dp(n + 1, 1e9);
    dp[0] = 0;
    for (int i = 0; i < 7; i++)
    {
        int k = 1;
        while (cnt[i] > 0)
        {
            int c = min(cnt[i], k);
            for (int j = n; j >= c * price[i]; j--)
                    dp[j] = min(dp[j], dp[j - c * price[i]] + c);
            cnt[i] -= c;
            k *= 2;
        }
    }

    if (dp[n] == 1e9)
        cout << "Fail\n";
    else
        cout << dp[n] << '\n';
    return 0;
}