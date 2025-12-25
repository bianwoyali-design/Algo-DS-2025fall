#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, long long> diff;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            diff[a - i]++;
        }

        long long ans = 0;
        for (auto i : diff)
            if (i.second >= 2)
                ans += (i.second * (i.second - 1) / 2);

        cout << ans << '\n';
    }
    return 0;
}