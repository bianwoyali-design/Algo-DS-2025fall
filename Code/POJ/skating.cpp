#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

struct Node
{
    int x;
    int y;
    int z;
} node[20000];

int maxLen[101][101];
int Height[101][101];
int xy[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

bool cmp(Node a, Node b)
{
    return a.z < b.z;
}

int main()
{
    int a, b;
    cin >> a >> b;
    for (int i = 0; i < a; i++)
        for (int j = 0; j < b; j++)
        {
            cin >> Height[i][j];
            node[i * b + j].x = i;
            node[i * b + j].y = j;
            node[i * b + j].z = Height[i][j];
            maxLen[i][j] = 1;
        }
    sort(node, node + (a * b), cmp);
    int ans = 1;
    for (int i = 0; i < a * b; i++)
    {
        int x = node[i].x;
        int y = node[i].y;
        for (int j = 0; j < 4; j++)
        {
            int newX = x + xy[j][0];
            int newY = y + xy[j][1];
            if (newX >= 0 && newX < a && newY >= 0 && newY < b && Height[newX][newY] < Height[x][y])
            {
                maxLen[x][y] = max(maxLen[x][y], maxLen[newX][newY] + 1);
                ans = max(ans, maxLen[x][y]);
            }
        }
    }
    cout << ans << endl;
    return 0;
}

