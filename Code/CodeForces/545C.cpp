#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<pair<long long, long long>> range;
    while (n--)
    {
        long long x, h;
        cin >> x >> h;
        range.emplace_back(x - h, x + h);
    }

    long long currR = -1e9;
    int ans = 0;
    for (int i = 0; i < range.size(); i++)
    {
        if (i == 0 || range[i].first > currR)
        {
            ans++;
            currR = (range[i].first + range[i].second) / 2;
        }
        else if (i == range.size() - 1 || range[i].second < (range[i + 1].first + range[i + 1].second) / 2)
        {
            ans++;
            currR = range[i].second;
        }
        else
            currR = (range[i].first + range[i].second) / 2;
    }
    cout << ans << endl;
    return 0;
}