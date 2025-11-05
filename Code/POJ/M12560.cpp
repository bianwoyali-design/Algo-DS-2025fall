#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int xy[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> ipt(n, vector<bool>(m));
    vector<vector<bool>> opt(n, vector<bool>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int val;
            cin >> val;
            ipt[i][j] = val;
        }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int live = 0;
            for (int k = 0; k < 8; k++)
            {
                int newX = i + xy[k][0];
                int newY = j + xy[k][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && ipt[newX][newY])
                    live++;
            }
            if (ipt[i][j])
                if (live < 2 || live > 3)
                    opt[i][j] = 0;
                else
                    opt[i][j] = 1;
            else
                if (live == 3)
                    opt[i][j] = 1;
                else
                    opt[i][j] = 0;
        }
    
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            j == m - 1 ? cout << opt[i][j] << '\n' : cout << opt[i][j] << ' ';
    return 0;
}