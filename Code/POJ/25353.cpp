#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, D;
    cin >> N >> D;
    deque<int> q;
    for (int i = 0; i < N; i++)
    {
        int ipt;
        cin >> ipt;
        q.push_back(ipt);
    }

    vector<vector<int>> ans;
    while (!q.empty())
    {
        vector<int> inlist;
        int maxv = q.front(), minv = q.front();
        int curr = q.size();
        for (int i = 0; i < curr; i++)
        {
            int f = q.front();
            q.pop_front();
            if (abs(f - maxv) <= D && abs(f - minv) <= D)
                inlist.push_back(f);
            else
                q.push_back(f);
            minv = min(minv, f);
            maxv = max(maxv, f);
        }
        sort(inlist.begin(), inlist.end(), [](int a, int b){ return a < b; });
        for (auto i : inlist)
            cout << i << '\n';
    }
    return 0;
}