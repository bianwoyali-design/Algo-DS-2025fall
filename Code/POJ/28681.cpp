#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int ID, a, b, c;
} node[301];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> node[i].a >> node[i].b >> node[i].c;
        node[i].ID = i + 1;
    }

    sort(node, node + n, [](Node a, Node b)
         {
        int tota = a.a + a.b + a.c;
        int totb = b.a + b.b + b.c;
        if (tota == totb)
        {
            if (a.a == b.a)
                return a.ID < b.ID;
            return a.a > b.a;
        }
        return tota > totb; });
    
    for (int i = 0; i < 5; i++)
        cout << node[i].ID << ' ' << node[i].a + node[i].b + node[i].c << '\n';
    return 0;
}