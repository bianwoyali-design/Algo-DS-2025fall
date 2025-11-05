#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    unordered_map<string, vector<int>> mp;
    
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        while (a--)
        {
            string s;
            cin >> s;
            if (mp[s].empty() || mp[s].back() != i)
                mp[s].push_back(i);
        }
    }

    int m;
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        string str;
        cin >> str;
        if (mp[str].empty())
            cout << "NOT FOUND\n";
        else
            for (auto j : mp[str])
                j != mp[str].back() ? cout << j << ' ' : cout << j << endl;
    }

    return 0;
}