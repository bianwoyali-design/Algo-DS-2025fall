#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Node
{
    int parent;
    int size;
};

vector<Node> self;

void _init(int n)
{
    self = vector<Node>(n);
    for (int i = 0; i < n; i++)
    {
        self[i].parent = i;
        self[i].size = 1;
    }
}

int _find(int i)
{
    if (self[i].parent != i)
        self[i].parent = _find(self[i].parent);
    return self[i].parent;
}

void _union(int i, int j)
{
    int irep = _find(i);
    int jrep = _find(j);
    if (irep == jrep)
        return;
    if (self[irep].size < self[jrep].size)
    {
        self[irep].parent = jrep;
        self[jrep].size += self[irep].size;
    }
    else
    {
        self[jrep].parent = irep;
        self[irep].size += self[jrep].size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    _init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    set<int> cnt;
    for (int i = 0; i < n; i++)
        cnt.insert(_find(i));
    cout << cnt.size() << '\n';
    return 0;
}