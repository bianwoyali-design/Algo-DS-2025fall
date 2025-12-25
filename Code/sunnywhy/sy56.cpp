#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;
        if (num < tmp)
        {
            cout << "NO" << endl;
            return 0;
        }
        tmp = num;
    }
    cout << "YES" << endl;
    return 0;
}