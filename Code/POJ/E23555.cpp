#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    vector<vector<int>> x(n, vector<int>(n, 0));
    vector<vector<int>> y(n, vector<int>(n, 0));

    int m1, m2;
    scanf("%d%d", &m1, &m2);
    for (int i = 0; i < m1; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        x[a][b] = v;
    }
    for (int i = 0; i < m2; i++)
    {
        int a, b, v;
        scanf("%d%d%d", &a, &b, &v);
        y[a][b] = v;
    }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
        {
            int ans = 0;
            for (int k = 0; k < n; k++)
                ans += x[i][k] * y[k][j];
            if (ans != 0)
                printf("%d %d %d\n", i, j, ans);
        }
    return 0;
}