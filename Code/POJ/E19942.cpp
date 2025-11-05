#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int m, n, p, q;
    scanf("%d%d%d%d", &m, &n, &p, &q);
    vector<vector<int>> matrix(m, vector<int>(n));
    vector<vector<int>> kernel(p, vector<int>(q));
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &matrix[i][j]);
    for (int i = 0; i < p; i++)
        for (int j = 0; j < q; j++)
            scanf("%d", &kernel[i][j]);

    int row_limit = m + 1 - p;
    int col_limit = n + 1 - q;
    for (int i = 0; i < row_limit; i++)
    {
        for (int j = 0; j < col_limit; j++)
        {
            int sum = 0;
            for (int k = 0; k < p; k++)
                for (int l = 0; l < q; l++)
                    sum += matrix[i + k][j + l] * kernel[k][l];
            printf("%d%c", sum, (j == col_limit - 1) ? '\n' : ' ');
        }
    }
    return 0;
}