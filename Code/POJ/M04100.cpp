#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<pair<int, int>> t(n);
        for (auto &i : t)
            cin >> i.first >> i.second;
        sort(t.begin(), t.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.second < b.second; });
        int curr = 0, cnt = 0;
        for (const auto &i : t)
            if (i.first > curr)
            {
                curr = i.second;
                cnt++;
            }
        cout << cnt << '\n';
    }
    return 0;
}