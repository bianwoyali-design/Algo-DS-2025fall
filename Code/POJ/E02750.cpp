#include <iostream>
using namespace std;

int main()
{
    int a;
    int maxNum = 0, minNum = 0;
    cin >> a;
    if (a % 2 != 0)
    {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    maxNum += a / 2;
    minNum += a / 4;
    minNum += a % 4 / 2;
    cout << minNum << " " << maxNum << endl;
    return 0;
}