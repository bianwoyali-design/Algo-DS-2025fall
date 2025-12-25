#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int l = 0, r = -1, cnt = 0;
    int maxLen = 0;
    while (r < n)
    {
        if (cnt <= k)
        {
            maxLen = max(maxLen, r - l + 1);
            r++;
            if (r < n && s[r] == '0')
                cnt++;
        }
        else
        {
            if (s[l] == '0')
                cnt--;
            l++;
        }
    }

    cout << maxLen << '\n';
    return 0;
}