#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

int xy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char m[30][30];

void dfs(int x, int y, char c)
{
    m[x][y] = '#';
    for (int i = 0; i < 4; i++)
    {
        int newX = x + xy[i][0];
        int newY = y + xy[i][1];
        if (m[newX][newY] == c)
            dfs(newX, newY, c);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        int n;
        cin >> n;
        memset(m, '\0', sizeof(m));
        for (int j = 0; j < n * n; j++)
            cin >> m[j / n][j % n];
        
        int r = 0, b = 0;
        for (int x = 0; x < n; x++)
            for (int y = 0; y < n; y++)
                if (m[x][y] == 'r')
                {
                    dfs(x, y, 'r');
                    r++;
                }
                else if (m[x][y] == 'b')
                {
                    dfs(x, y, 'b');
                    b++;
                }
        
        cout << r << ' ' << b << '\n';
    }
    return 0;
}