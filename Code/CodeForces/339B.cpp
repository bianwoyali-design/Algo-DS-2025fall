#include <iostream>
using namespace std;

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    int curr = 1;
    long long step = 0;
    for (int i = 0; i < m; i++)
    {
        int a;
        scanf("%d", &a);
        if (curr <= a)
            step += a - curr;
        else
            step += n - curr + a;
        curr = a;
    }
    printf("%I64d\n", step);
    return 0;
}