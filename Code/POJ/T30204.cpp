#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll m;
    if (cin >> n >> m)
    {
        vector<ll> x(n), y(n);
        ll min_s = -1;

        for (int i = 0; i < n; ++i)
        {
            cin >> x[i] >> y[i];
            ll s = x[i] + y[i];
            if (min_s == -1 || s < min_s)
            {
                min_s = s;
            }
        }
        vector<ll> v(n);
        for (int i = 0; i < n; ++i)
        {
            v[i] = 2 * x[i] - min_s;
        }

        sort(v.begin(), v.end());

        ll max_tasks = 0;
        ll current_P = 0;

        for (int r = 0; r <= n; ++r)
        {
            if (r > 0)
            {
                current_P += v[r - 1];
            }
            ll rhs = 2 * m - current_P;
            if (rhs < 0)
                break;
            ll limit = rhs / min_s;
            if (limit < r)
                continue;
            if (limit % 2 != r % 2)
            {
                limit--;
            }
            if (limit >= r)
            {
                max_tasks = max(max_tasks, limit);
            }
        }
        cout << max_tasks << endl;
    }
    return 0;
}