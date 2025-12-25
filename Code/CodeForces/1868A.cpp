#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;

        if (m == 1)
        {
            cout << 0 << '\n';
            for (int i = 0; i < n; i++)
                cout << 0 << '\n';
            continue;
        }

        vector<vector<int>> M(n, vector<int>(m));
        vector<int> nums;
        for (int i = 0; i < n; i++)
        {
            int it = i % (m - 1);
            int round = 0;
            while (round != m)
            {
                M[i][round] = it;
                round++;
                ++it %= m;
            }
        }
        int max = 0;
        for (int i = 0; i < m; i++)
        {
            vector<bool> exist(m, 0);
            for (int j = 0; j < n; j++)
                exist[M[j][i]] = true;
            for (int j = 0; j < m; j++)
                if (!exist[j])
                {
                    max = max > j ? max : j;
                    break;
                }
        }

        cout << max + 1 << '\n';
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                j != m - 1 ? cout << M[i][j] << ' ' : cout << M[i][j] << '\n';
    }
    return 0;
}