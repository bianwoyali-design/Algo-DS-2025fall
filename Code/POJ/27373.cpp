#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

string str_max(string a, string b)
{
    if (a.length() != b.length())
        return a.length() > b.length() ? a : b;
    return max(a, b);
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int m, n;
    cin >> m >> n;
    vector<string> nums;
    for (int i = 0; i < n; i++)
    {
        string s;
        cin >> s;
        if (s.length() <= m)
            nums.push_back(s);
    }

    vector<string> dp(m + 1, "");
    sort(nums.begin(), nums.end(), [](const string &a, const string &b) { return a + b > b + a; });

    for (int i = 0; i < nums.size(); i++)
        for (int j = m; j >= nums[i].size(); j--)
            dp[j] = str_max(dp[j], dp[j - nums[i].size()] + nums[i]);
    
    cout << dp[m] << '\n';
    return 0;
}