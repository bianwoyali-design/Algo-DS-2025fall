#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> dp(n + 1);
    auto hp = [&](string a, string b) -> string
    {
        int maxLen = max(a.length(), b.length());
        a = string(maxLen - a.length(), '0') + a;
        b = string(maxLen - b.length(), '0') + b;
        string result(maxLen, '0');
        int carry = 0;
        for (int i = maxLen - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 10;
            result[i] = (sum % 10) + '0';
        }
        if (carry > 0)
            result = "1" + result;
        result.erase(0, result.find_first_not_of('0'));
        if (result.empty())
            result = "0";
        return result;
    };
    dp[1] = "1",dp[2] = "2";
    for (int i = 3; i <= n; i++)
        dp[i] = hp(dp[i - 1], dp[i - 2]);

    cout << dp[n] << '\n';
    return 0;
}