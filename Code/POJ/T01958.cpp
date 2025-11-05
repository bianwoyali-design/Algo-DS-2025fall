#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n = 0;
    while (n++ < 12)
    {
        int t = round(sqrt(2 * n));
        cout << 1 - pow(2, t - 2) * (t * t - 3 * t - 2 * n + 4) << '\n';
    }
    return 0;
}