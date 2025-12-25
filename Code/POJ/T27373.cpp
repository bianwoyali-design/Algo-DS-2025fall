#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str_max(string a, string b)
{
    if (a.length() != b.length())
        return a.length() > b.length() ? a : b;
    return a > b ? a : b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n;
    cin >> m >> n;
    vector<string> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];

    sort(nums.begin(), nums.end(), [](string a, string b)
         { return a + b > b + a; });
    vector<string> dp(m + 1);
    for (int i = 0; i < n; i++)
        for (int j = m; j >= nums[i].length(); j--)
            dp[j] = str_max(dp[j], dp[j - nums[i].length()] + nums[i]);

    cout << dp[m] << '\n';
    return 0;
}