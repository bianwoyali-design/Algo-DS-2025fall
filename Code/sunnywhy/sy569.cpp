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

    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
            if (exist[i][j] == 1 && exist[j][i] == 1)
            {
                cout << "Yes" << endl;
                return 0;
            }
    cout << "No" << endl;
    return 0;
}