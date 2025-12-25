#include <iostream>
#include <cmath>
using namespace std;
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int num, b;
        int a = 1, cnt = 0;
        int round[6];
        cin >> num;
        do
        {
            b = pow(10, a);
            if (num % b != 0)
                round[cnt++] = num % b;
            num -= num % b;
            a++;
        } while (num != 0);
        cout << cnt << endl;
        for (int i = 0; i < cnt; i++)
            cout << round[i] << " ";
        cout << endl;
    }
    return 0;
}