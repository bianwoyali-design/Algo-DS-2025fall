#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        long long l, r, x;
        cin >> l >> r >> x;
        long long a, b;
        cin >> a >> b;
        if (a == b)
            cout << "0\n";
        else if (abs(a - b) >= x)
            cout << "1\n";
        else if ((a + x <= r && b + x <= r) || (a - x >= l && b - x >= l))
            cout << "2\n";
        else if ((a - x >= l && b + x <= r) || (a + x <= r && b - x >= l))
            cout << "3\n";
        else cout << "-1\n";
    }
    return 0;
}