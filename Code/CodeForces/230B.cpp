#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);

    bool vis[1000001] = {false};
    for (int i = 2; i <= 1000; i++)
        if (!vis[i])
            for (int j = i * i; j <= 1000000; j += i)
                vis[j] = true;

    while (n--)
    {
        long long x;
        scanf("%I64d", &x);
        long long s = sqrt(x);
        if (x == s * s && !vis[s] && s > 1)
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
