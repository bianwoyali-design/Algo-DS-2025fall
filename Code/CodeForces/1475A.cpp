#include <iostream>
using namespace std;

bool judgement(unsigned long long a)
{
    if (a == 1)
        return false;
    while (a % 2 == 0)
        a /= 2;
    if (a > 1)
        return true;
    else
        return false;
}

int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < t; i++)
    {
        unsigned long long n;
        cin >> n;
        if (judgement(n))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}