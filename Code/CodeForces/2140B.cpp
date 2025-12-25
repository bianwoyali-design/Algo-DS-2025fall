#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        long long ipt;
        cin >> ipt;
        cout << 2 * ipt << '\n';
    }
    return 0;
}