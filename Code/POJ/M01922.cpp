#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (n == 0)
            break;
        int minTime = 2147483647;
        for (int i = 0; i < n; i++)
        {
            double v, t;
            cin >> v >> t;
            if (t < 0)
                continue;
            else
                minTime = minTime < ceil(16200 / v) + t ? minTime : ceil(16200 / v) + t;
        }
        cout << minTime << endl;
    }
    return 0;
}