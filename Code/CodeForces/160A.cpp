#include <iostream>
#include <algorithm>
using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}

int main()
{
    int n;
    int sum = 0, sum1 = 0, sum2 = 0;
    int a[101];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    sort(a, a + n, cmp);
    for (int i = 0; i < n; i++)
    {
        sum1 += a[i];
        sum2 = sum - sum1;
        if (sum1 > sum2)
        {
            cout << i + 1 << endl;
            return 0;
        }
    }
}