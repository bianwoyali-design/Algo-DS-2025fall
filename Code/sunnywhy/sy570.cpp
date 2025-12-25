#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, q;
    cin >> n >> q;
    vector<vector<bool>> exist(n + 1, vector<bool>(n + 1, 0));

    while (q--)
    {
        int x, y;
        cin >> x >> y;
        exist[x][y] = 1;
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            for (int k = 1; k <= n; k++)
                if (exist[i][j] == 1 && exist[j][k] == 1 && exist[k][i] == 1 && i != j && j != k && k != i)
                {
                    cout << "Yes" << endl;
                    return 0;
                }
    cout << "No" << endl;
    return 0;
}