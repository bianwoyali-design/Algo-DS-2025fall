#include <iostream>
#include <map>
using namespace std;

int main()
{
    string s;
    cin >> s;

    int ans = 0;
    for (int i = 0; i < s.length(); i++)
    {
        int cnt[26]{};
        for (int j = i; j < s.length(); j++)
        {
            cnt[s[j] - 'a']++;
            if (j - i + 1 >= 3)
            {
                int mn = INT_MAX, mx = 0;
                for (int k = 0; k < 26; ++k)
                    if (cnt[k] > 0)
                    {
                        mn = min(mn, cnt[k]);
                        mx = max(mx, cnt[k]);
                    }
                if (mn != INT_MAX)
                    ans += (mx - mn);
            }
        }
    }
    cout << ans << '\n';
    return 0;
}