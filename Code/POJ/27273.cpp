#include <iostream>
#include <cmath>
using namespace std;

typedef  long long ll;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        cout << ll((n + 1) * n / 2 - 2 * (pow(2, ll(log2(n)) + 1) - 1)) << '\n';
    }
    return 0;
}