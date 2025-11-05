#include <iostream>
using namespace std;

int main()
{
    int a;
    cin >> a;
    for (int i = 0; i < a; i++)
    {
        int n;
        bool cell[101] = {false};
        cin >> n;
        for (int j = 1; j <= n; j++)
            for (int k = j; k <= n; k += j)
            {
                if (cell[k] == true) cell[k] = false;
                else cell[k] = true;
            }
        int cnt = 0;
        for (int j = 1; j <= n; j++)
            if (cell[j] == true)
                cnt++;
        cout << cnt << endl;
    }
    return 0;
}