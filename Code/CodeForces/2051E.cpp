#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<pair<size_t, size_t>> events;
        size_t ipt;
        for (int i = 0; i < n; i++)
        {
            cin >> ipt;
            events.push_back({ipt, 1});
        }
        for (int i = 0; i < n; i++)
        {
            cin >> ipt;
            events.push_back({ipt, 2});
        }

        sort(events.begin(), events.end());

        int i = 0, bad = 0;
        size_t cost = 0, p = n;
        while (i < 2 * n)
        {
            int curr = events[i].first;

            if (bad <= k)
                cost = max(cost, p * events[i].first);
            
            while (i < 2 * n && events[i].first == curr)
            {
                bad += (events[i].second == 1);
                bad -= (events[i].second == 2);
                p -= (events[i].second == 2);
                i++;
            }
        }
        cout << cost << '\n';
    }
    return 0;
}