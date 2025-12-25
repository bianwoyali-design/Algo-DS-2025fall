#include <iostream>
#include <vector>
using namespace std;

int vis[10000000];

int main()
{
    int n;
    cin >> n;
    for (int j = 2; j <= 10000; j++)
        if (vis[j] == 0)
            for (int k = j * j; k <= 10000000; k += j)
                vis[k] = j;
    vector<vector<int>> matrix(n, vector<int>(2, -1));
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        if (vis[a] == 0)
            continue;
        matrix[i][0] = a;
        int prime = vis[a];
        matrix[i][1] = 1;
        while (matrix[i][0] % prime == 0)
        {
            matrix[i][0] /= prime;
            matrix[i][1] *= prime;
        }
        if (matrix[i][0] == 1)
        {
            matrix[i][0] = -1;
            matrix[i][1] = -1;
        }
    }
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < n; j++)
            cout << matrix[j][i] << ' ';
        cout << endl;
    }
    return 0;
}