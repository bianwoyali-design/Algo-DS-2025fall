#include <iostream>
using namespace std;

int main()
{
    int n;
    int T[31] = {0, 1, 1};
    cin >> n;
    if (n >= 1 && n <= 2)
    {
        cout << T[n] << endl;
        return 0;
    }
    for (int i = 3; i <= n; i++)
    {
        T[i] = T[i - 1] + T[i - 2] + T[i - 3];
    }
    cout << T[n] << endl;
    return 0;
}