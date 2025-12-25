#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m;
    int a[101], b[101];

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);
    scanf("%d", &m);
    for (int i = 0; i < m; i++)
        scanf("%d", &b[i]);
    
    sort(a, a + n);
    sort(b, b + m);

    int ans = 0;
    int i = 0, j = 0;
    while (i < n && j < m)
    {
        if (abs(a[i] - b[j]) <= 1)
        {
            ans++;
            i++;
            j++;
        }
        else if (a[i] < b[j])
            i++;
        else
            j++;
    }
    printf("%d\n", ans);
    return 0;
}