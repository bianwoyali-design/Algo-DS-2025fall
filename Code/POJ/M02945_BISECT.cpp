#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    reverse(h.begin(), h.end());
    auto bisect_algorithm = [&]() -> int
    {
        vector<int> dp(n, 1e9);
        for (auto i : h)
            *upper_bound(dp.begin(), dp.end(), i) = i;
        return upper_bound(dp.begin(), dp.end(), 1e8) - dp.begin();
    };

    cout << bisect_algorithm() << '\n';
    return 0;
}