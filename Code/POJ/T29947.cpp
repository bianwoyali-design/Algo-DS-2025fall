#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int l, r;
} metro[101];

bool cmp(Node a, Node b)
{
    return a.l < b.l;
}

int main()
{
    int l, m;
    cin >> l >> m;
    for (int i = 0; i < m; i++)
        cin >> metro[i].l >> metro[i].r;
    sort(metro, metro + m, cmp);
    int itl = metro[0].l, itr = metro[0].r;
    for (int i = 1; i < m; i++)
    {
        if (metro[i].l <= itr + 1)
            itr = itr > metro[i].r ? itr : metro[i].r;
        else
        {
            l -= ((itr - itl) + 1);
            itl = metro[i].l, itr = metro[i].r;
        }
    }
    cout << l + 1 - (itr - itl) - 1 << endl;
    return 0;
}