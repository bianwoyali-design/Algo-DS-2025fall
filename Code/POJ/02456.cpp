#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, c;
    cin >> n >> c;
    vector<int> list(n);
    for (int i = 0; i < n; i++)
        cin >> list[i];
    int l = 1, r = list.back() - list[0], mid;
    
    int ans;
    while (l < r)
    {
        mid = l + (r - l) / 2;
        int curr = list[0];
        int cnt = 1;
        for (int i = 1; i < n; i++)
        {
            if (list[i] - curr >= mid)
            {
                curr = list[i];
                cnt++;
                if (cnt >= c)
                    break;
            }
        }
        if (cnt >= c)
        {
            ans = mid;
            l = mid + 1;
        }
        else
            r = mid;
    }
    cout << ans << '\n';
    return 0;
}