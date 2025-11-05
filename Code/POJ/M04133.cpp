#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int d, n, minN = 0, maxN = 1e9;
    cin >> d;
    static long long matrix[1025][1025] = {0};
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        cin >> matrix[x][y];
    }

    static long long sum[1026][1026] = {0};
    for (int i = 0; i < 1025; i++)
        for (int j = 0; j < 1025; j++)
            sum[i + 1][j + 1] = matrix[i][j] + sum[i + 1][j] + sum[i][j + 1] - sum[i][j];
    long long best = 0;
    int cnt = 0;
    for (int i = 0; i < 1025; i++)
        for (int j = 0; j < 1025; j++)
        {
            int r1 = max(0, i - d);
            int r2 = min(1024, i + d);
            int c1 = max(0, j - d);
            int c2 = min(1024, j + d);
            long long a = sum[r2 + 1][c2 + 1] - sum[r1][c2 + 1] - sum[r2 + 1][c1] + sum[r1][c1];
            if (a > best)
            {
                best = a;
                cnt = 1;
            }
            else if (a == best)
                cnt++;
        }

    cout << cnt << ' ' << best << endl;
    return 0;
}