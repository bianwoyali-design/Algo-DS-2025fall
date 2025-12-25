#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int e, f;
        cin >> e >> f;
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> p[i] >> w[i];
        
        int capacity = f - e;
        vector<int> dp(capacity + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= capacity; i++)
            for (int j = 0; j < n; j++)
                if (w[j] <= i)
                    dp[i] = min(dp[i - w[j]] + p[j], dp[i]);
        
        if (dp[capacity] < 1e9)
            cout << "The minimum amount of money in the piggy-bank is " << dp[capacity] << ".\n";
        else
            cout << "This is impossible.\n";
    }

    return 0;
}