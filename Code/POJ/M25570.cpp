#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int maxSum = 0;
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        int start = i, end = n - 1 - i;
        int sum = 0;
        if (start == end)
            sum = a[i][i];
        else
        {
            for (int j = start; j <= end; j++)
                sum += a[start][j] + a[j][start] + a[j][end] + a[end][j];
            sum = sum - a[start][start] - a[end][end] - a[start][end] - a[end][start];
        }
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << '\n';
    return 0;
}
