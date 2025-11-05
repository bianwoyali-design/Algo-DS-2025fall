#include <iostream>
using namespace std;

bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i < x; i++)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    int n;
    cin >> n;
    if (n < 6 || n % 2 != 0)
    {
        cout << "Error!" << endl;
        return 0;
    }
    for (int i = 3; i <= n / 2; i++)
    {
        int j = n - i;
        if (is_prime(i) && is_prime(j))
            cout << n << "=" << i << "+" << j << endl;
    }
    return 0;
}