#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    while (true)
    {
        if (n % 2 == 0)
        {
            printf("%d/2=%d\n", n, n / 2);
            n /= 2;
        }
        else
        {
            printf("%d*3+1=%d\n", n, n * 3 + 1);
            n = n * 3 + 1;
        }
        if (n == 1)
            break;
    }
    return 0;
}