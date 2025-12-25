#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    while (n > 1)
        if (n % 2 == 0)
        {
            int tmp = n;
            n /= 2;
            cout << tmp << '/' << 2 << '=' << n << '\n';
        }
        else
        {
            int tmp = n;
            n = n * 3 + 1;
            cout << tmp << '*' << 3 << '+' << 1 << '=' << n << '\n';
        }
    cout << "End\n";
    return 0;
}