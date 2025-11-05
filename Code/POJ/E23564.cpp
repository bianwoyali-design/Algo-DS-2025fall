#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 1)
    {
        cout << (n == 1 ? 1 : 0) << endl;
        return 0;
    }
    vector<bool> prime(n + 1, false);
    for (int i = 2; i * i <= n; i++)
    {
        if (!prime[i])
        {
            for (int j = i * i; j <= n; j += i)
            {
                prime[j] = true;
            }
        }
    }
    int tmp = n;
    int cnt_prime = 0;
    for (int i = 2; i <= n && tmp != 1; i++)
    {
        if (!prime[i] && tmp % i == 0)
        {
            int square = 0;
            while (tmp % i == 0)
            {
                tmp /= i;
                cnt_prime++;
                square++;
                if (square == 2)
                {
                    cout << 0 << endl;
                    return 0;
                }
            }
        }
    }
    if (cnt_prime % 2 == 0)
        cout << 1 << endl;
    else
        cout << -1 << endl;

    return 0;
}