#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n, m, k;
    scanf("%d%d%d", &n, &m, &k);
    bool matrix[1002][1002] = {0};
    for (int i = 0; i < k; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        matrix[x][y] = true;
        if ((matrix[x + 1][y] && matrix[x + 1][y + 1] && matrix[x][y + 1]) || (matrix[x + 1][y] && matrix[x + 1][y - 1] && matrix[x][y - 1]) || (matrix[x][y + 1] && matrix[x - 1][y + 1] && matrix[x - 1][y]) || (matrix[x][y - 1] && matrix[x - 1][y - 1] && matrix[x - 1][y]))
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}