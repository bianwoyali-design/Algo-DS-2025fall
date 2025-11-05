#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    while (cin >> n)
    {
        double x0 = 1.0, x1;
        int cnt = 0;
        while (true)
        {
            x1 = x0 - (x0 * x0 - n) / (2 * x0);
            cnt++;
            if (abs(x1 - x0) <= 1e-6)
                break;
            x0 = x1;
        }
        printf("%d %.2lf\n", cnt, x1);
    }
    return 0;
}