#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    if (n < 2)
        return s;
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    int maxLen = 1, begin = 0;
    for (int L = 2; L <= n; L++)
        for (int i = 0; i < n; i++)
        {
            int j = i + L - 1;
            if (j >= n)
                break;
            dp[i][j] = j - i < 3 && s[i] == s[j] || dp[i + 1][j - 1] && s[i] == s[j];
            if (dp[i][j] && L > maxLen)
            {
                begin = i;
                maxLen = L;
            }
        }
    return s.substr(begin, maxLen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << longestPalindrome(s) << '\n';
    return 0;
}