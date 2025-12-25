#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    
    int max_glob = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> sum_col(n, 0);
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                sum_col[k] += m[j][k];
            int max_curr = sum_col[0];
            for (int k = 1; k < n; k++)
            {
                max_curr = max(sum_col[k], max_curr + sum_col[k]);
                max_glob = max(max_glob, max_curr);
            }
        }
    }

    cout << max_glob << '\n';
    return 0;
}