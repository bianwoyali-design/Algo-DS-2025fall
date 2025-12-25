#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int x;
    int y;
} dragon[1001];

bool cmp(Node a, Node b)
{
    return a.x < b.x;
}

int main()
{
    int s, n;
    cin >> s >> n;
    for (int i = 0; i < n; i++)
        cin >> dragon[i].x >> dragon[i].y;
    sort(dragon, dragon + n, cmp);
    for (int i = 0; i < n; i++)
    {
        if (s <= dragon[i].x)
        {
            cout << "NO" << endl;
            return 0;
        }
        else
            s += dragon[i].y;
    }
    cout << "YES" << endl;
    return 0;
}