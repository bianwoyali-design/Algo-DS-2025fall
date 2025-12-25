#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    char ch;
    cin >> m >> ch >> n >> ch >> k;

    vector<vector<int>> hash(100);
    int maxK = 0;
    for (int i = m + 1; i < n; i++)
    {
        int tmp = i, sum = 0;
        while (tmp)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum % k == 0)
        {
            hash[sum].push_back(i);
            maxK = max(maxK, sum);
        }
    }
    for (int i = 0; i <= maxK; i++)
    {
        if (!hash[i].empty())
        {
            for (int j = 0; j < hash[i].size(); j++)
            {
                if (j) cout << ',';
                cout << hash[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}