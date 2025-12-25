#include <iostream>
#include <algorithm>
#include <bitset>
#include <vector>
using namespace std;

string to_2(int n)
{
    string s;
    while (n)
    {
        char c = n % 2 + '0';
        s = c + s;
        n /= 2;
    }
    return s;
}

int to_10(string s)
{
    int n = 0;
    int t = 1;
    for (int i = s.length() - 1; i >= 0; i--)
    {
        n += (s[i] - '0') * t;
        t *= 2;
    }
    return n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    bool vis[100001]{false};
    bool hash[100001]{false};
    for (int i = 2; i <= 50000; i++)
        if (!vis[i])
            for (int j = i * 2; j <= 100000; j += i)
                vis[j] = true;
        
    pair<int, int> ans;
    for (int i = 3, x = 0; x <= n; i++)
    {
        if (vis[i])
            continue;
        if (hash[i])
            continue;
        string b = to_2(i);
        string tmp = b;
        reverse(b.begin(), b.end());
        int n = to_10(b);
        if (b == tmp)
            ans.first = i, ans.second = i, hash[i] = true, x++;
        else if (!vis[n])
            ans.first = i, ans.second = n, hash[i] = true, hash[n] = true, x++;
    }

    cout << ans.first << ' ' << ans.second << '\n';
    return 0;
}