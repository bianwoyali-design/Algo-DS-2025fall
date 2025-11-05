#include <iostream>
using namespace std;

int main()
{
    int a[7];
    while (true)
    {
        int sum = 0;
        for (int i = 0; i < 6; i++)
            cin >> a[i];
        if (a[0] == 0 && a[1] == 0 && a[2] == 0 && a[3] == 0 && a[4] == 0 && a[5] == 0)
            break;

        sum += a[5];

        sum += a[4];
        a[0] -= a[4] * 11;
        if (a[0] < 0)
            a[0] = 0;

        sum += a[3];
        a[1] -= a[3] * 5;
        if (a[1] < 0)
        {
            a[0] += a[1] * 4;
            a[1] = 0;
        }
        if (a[0] < 0)
            a[0] = 0;

        sum += a[2] / 4;
        if (a[2] % 4 > 0)
        {
            sum++;
            int left2[4] = {0, 5, 3, 1};
            int left1[4] = {0, 7, 6, 5};
            int need2 = left2[a[2] % 4];
            int need1 = left1[a[2] % 4];
            if (a[1] > need2)
            {
                a[1] -= need2;
            }
            else
            {
                need1 += (need2 - a[1]) * 4;
                a[1] = 0;
            }
            a[0] -= need1;
            if (a[0] < 0)
                a[0] = 0;
        }

        sum += a[1] / 9;
        if (a[1] % 9 > 0)
        {
            sum++;
            a[0] -= 36 - a[1] % 9 * 4;
            if (a[0] < 0)
                a[0] = 0;
        }

        sum += a[0] / 36;
        if (a[0] % 36 > 0)
            sum++;
        cout << sum << endl;
    }
    return 0;
}