#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    int cnt[128]{};
    int ans = 0, n = s.size();
    for (int l = 0, r = 0; r < n; ++r)
    {
        ++cnt[s[r]];
        while (cnt[s[r]] > 1)
        {
            --cnt[s[l++]];
        }
        ans = max(ans, r - l + 1);
    }

    cout << ans << '\n';
    return 0;
}