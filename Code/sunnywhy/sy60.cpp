#include <iostream>
using namespace std;

int main()
{
    int a, b;
    cin >> a >> b;
    int cnt = 0;
    int ans[1000];
    for (int i = a; i <= b; i++)
    {
        int x = i / 100;
        int y = i % 100 / 10;
        int z = i % 10;
        if (x * x * x + y * y * y + z * z * z == i)
        {
            ans[cnt++] = i;
        }
    }
    if (cnt == 0)
        cout << "NO" << endl;
    else
        for (int i = 0; i < cnt; i++)
        {
            cout << ans[i];
            if (i != cnt - 1)
                cout << ' ';
        }
    return 0;
}