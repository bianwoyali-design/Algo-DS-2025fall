#include <iostream>
using namespace std;

int main()
{
    int m, n;
    cin >> m >> n;
    int sum = 0;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
        {
            int a;
            cin >> a;
            if (i == 1 || i == m)
                sum += a;
            else if (j == 1 || j == n)
                sum += a;
        }
    cout << sum << endl;
    return 0;
}