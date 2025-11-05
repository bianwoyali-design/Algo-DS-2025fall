#include <iostream>
using namespace std;

const int MOD = 32767;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        int k;
        cin >> k;
        if (k == 1)
            cout << 1 << '\n';
        else if (k == 2)
            cout << 2 << '\n';
        else
        {
            int a = 1, b = 2;
            int res;
            for (int i = 3; i <= k; i++)
            {
                res = (2 * b + a) % MOD;
                a = b;
                b = res;
            }
            cout << res << '\n';
        }
    }
    return 0;
}