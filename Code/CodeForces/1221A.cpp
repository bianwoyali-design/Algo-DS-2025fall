#include <iostream>
using namespace std;

int main()
{
    int q;
    cin >> q;
    while (q--)
    {
        int n;
        int dic[2049] = {0};
        cin >> n;
        while (n--)
        {
            int s;
            cin >> s;
            if (s <= 2048)
                dic[s]++;
        }
        for (int i = 1; i < 2048; i *= 2)
            if(dic[i] >= 2)
            {
                dic[i * 2] += dic[i] / 2;
                dic[i] %= 2;
            }
        if (dic[2048] > 0)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}