#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, _size;

void _init(int n)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    _size.assign(n, 1);
}

int _find(int i)
{
    return parent[i] != i ? parent[i] = _find(parent[i]) : parent[i];
}

void _union(int i, int j)
{
    int irep = _find(parent[i]);
    int jrep = _find(parent[j]);
    if (irep != jrep)
    {
        parent[irep] = jrep;
        _size[jrep] += _size[irep];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    _init(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (_find(a - 1) == _find(b - 1))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}