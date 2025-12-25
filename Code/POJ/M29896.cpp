#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    vector<int> val;
    cin >> x >> n;
    for (int i = 0; i < n; i++)
    {
        int ipt;
        cin >> ipt;
        if (ipt <= x)
            val.push_back(ipt);
    }
    
    sort(val.begin(), val.end());
    if (val.empty() || val[0] != 1)
    {
        cout << -1 << '\n';
        return 0;
    }
    int ans = 0, pre = 0, idx = 0;
    while (pre < x)
    {
        while (idx < val.size() && val[idx] <= pre + 1)
            idx++;
        int next = idx < val.size() ? val[idx] - 1 : x;
        int add = (next - pre - 1 + val[idx - 1]) / val[idx - 1];
        pre += add * val[idx - 1];
        ans += add;
    }

    cout << ans << '\n';
    return 0;
}