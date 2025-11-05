#include <iostream>
#include <vector>
using namespace std;

int maxProfit_Greedy(vector<int>& prices)
{
    int minPrice = 1e9, maxN = 0;
    for (auto i : prices)
    {
        minPrice = min(minPrice, i);
        maxN = max(maxN, i - minPrice);
    }
    return maxN;
}

int maxProfit_DP(vector<int>& prices)
{
    if (prices.size() == 1)
        return 0;
    vector<int> sub;
    for (int i = 0; i < prices.size() - 1; i++)
        sub.push_back(prices[i + 1] - prices[i]);
    vector<int> dp(prices.size());
    dp[0] = sub[0];
    int maxN = max(0, dp[0]);
    for (int i = 1; i < dp.size(); i++)
    {
        dp[i] = max(0, dp[i - 1]) + sub[i];
        maxN = max(maxN, dp[i]); 
    }
    return maxN;
}

int main()
{
    vector<int> prices;
    int n;
    while (cin >> n)
        prices.push_back(n);
    cout << maxProfit_DP(prices) << '\n';
    return 0;
}