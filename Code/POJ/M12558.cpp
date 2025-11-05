#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> matrix[i][j];
    
    int c = 0;
    int xy[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (matrix[i][j])
                for (int k = 0; k < 4; k++)
                {
                    int newX = i + xy[k][0];
                    int newY = j + xy[k][1];
                    if (newX < 0 || newX >= n || newY < 0 || newY >= m || !matrix[newX][newY])
                        c++;
                }
    
    cout << c << '\n';
    return 0;
}