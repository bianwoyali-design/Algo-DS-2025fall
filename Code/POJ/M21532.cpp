#include <iostream>
using namespace std;

int main()
{
    int sum;
    cin >> sum;
    for (int i = 6; i <= sum; i++)
    {
        if (sum % i == 0)
        {
            cout << sum / i << endl;
            return 0;
        }
    }
}