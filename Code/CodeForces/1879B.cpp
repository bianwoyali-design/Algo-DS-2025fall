#include <iostream>
#include <cmath>
using namespace std;
 
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long n;
        cin >> n;
        int a, b;
        long long aMin = 2000000000, bMin = 2000000000;
        long long sum1 = 0, sum2 = 0;
        for (int j = 0; j < n; j++)
        {
            cin >> a;
            sum1 += a;
            aMin = aMin < a ? aMin : a;
        }
        for (int j = 0; j < n; j++)
        {
            cin >> b;
            sum2 += b;
            bMin = bMin < b ? bMin : b;
        }
        long long ans = sum1 + n * bMin < sum2 + n * aMin ? sum1 + n * bMin : sum2 + n * aMin;
        cout << ans << endl;
    }
    return 0;
}