#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> pa, sz;

void _init(int n)
{
    pa.resize(n);
    for (int i = 0; i < n; i++)
        pa[i] = i;
    sz.assign(n, 1);
}

int _find(int i)
{
    return pa[i] == i ? pa[i] : pa[i] = _find(pa[i]);
}

void _union(int i, int j)
{
    int irep = _find(pa[i]);
    int jrep = _find(pa[j]);
    if (irep != jrep)
    {
        pa[irep] = jrep;
        sz[jrep] += sz[irep];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> sc(n);
    _init(n);
    for (int i = 0; i < n; i++)
    {
        int score;
        cin >> score;
        sc[i] = score;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    set<int> cl;
    for (int i = 0; i < n; i++)
        cl.insert(_find(i));
    cout << cl.size() << '\n';
    vector<int> ans;
    for (auto i : cl)
    {
        int maxs = 0;   
        for (int j = 0; j < n; j++)
            if (_find(j) == i)
                maxs = max(maxs, sc[j]);
        ans.push_back(maxs);
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i = 0; i < ans.size(); i++)
        i == ans.size() - 1 ? cout << ans[i] : cout << ans[i] << ' ';
    return 0;
}