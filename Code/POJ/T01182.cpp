#include <iostream>
#include <vector>
using namespace std;

vector<int> pa, sz;

void _init(int n)
{
    pa.resize(3 * n);
    for (int i = 0; i < 3 * n; i++)
        pa[i] = i;
    sz.assign(3 * n, 1);
}

int _find(int i)
{
    return pa[i] == i ? pa[i] : pa[i] = _find(pa[i]);
}

void _union(int i, int j)
{
    int irep = _find(pa[i]);
    int jrep = _find(pa[j]);
    if (irep == jrep)
        return;
    if (sz[irep] < sz[jrep])
    {
        pa[irep] = jrep;
        sz[jrep] += sz[irep];
    }
    else
    {
        pa[jrep] = irep;
        sz[irep] += sz[jrep];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, K;
    cin >> N >> K;
    _init(N);
    int ans = 0;
    while (K--)
    {
        int D, X, Y;
        cin >> D >> X >> Y;
        if (X > N || Y > N)
        {
            ans++;
            continue;
        }
        if (D == 1)
        {
            if (_find(X + N - 1) == _find(Y - 1) || _find(X - 1) == _find(Y + N - 1))
            {
                ans++;
                continue;
            }
            _union(X - 1, Y - 1);
            _union(X + N - 1, Y + N - 1);
            _union(X + 2 * N - 1, Y + 2 * N - 1);
        }
        else
        {
            if (_find(X - 1) == _find(Y - 1) || _find(Y + N - 1) == _find(X - 1))
            {
                ans++;
                continue;
            }
            _union(X + N - 1, Y - 1);
            _union(Y + 2 * N - 1, X - 1);
            _union(X + 2 * N - 1, Y + N - 1);
        }
    }
    cout << ans << '\n';
    return 0;
}