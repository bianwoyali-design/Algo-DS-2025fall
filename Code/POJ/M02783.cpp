#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int d, c;
};

bool cmp(Node a, Node b)
{
    if (a.c != b.c)
        return a.c < b.c;
    return a.d < b.d;
}

int main()
{
    int n;
    while (scanf("%d", &n) && n)
    {
        Node hotel[10001];
        for (int i = 0; i < n; i++)
            scanf("%d%d", &hotel[i].d, &hotel[i].c);
        sort(hotel, hotel + n, cmp);

        int ans = 0;
        int min_d = 1e9 + 1;
        for (int i = 0; i < n; i++)
            if (hotel[i].d < min_d)
            {
                ans++;
                min_d = hotel[i].d;
            }
        printf("%d\n", ans);
    }
    return 0;
}