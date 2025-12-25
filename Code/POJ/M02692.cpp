#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        string l[3], r[3], stat[3];
        for (int i = 0; i < 3; i++)
            cin >> l[i] >> r[i] >> stat[i];

        for (char c = 'A'; c <= 'L'; ++c)
        {
            for (int fakeType = 0; fakeType < 2; fakeType++)
            {
                bool ok = true;
                for (int i = 0; i < 3; ++i)
                {
                    int left = 0, right = 0;
                    for (char x : l[i])
                        if (x == c)
                            left += (fakeType ? 1 : -1);
                    for (char x : r[i])
                        if (x == c)
                            right += (fakeType ? 1 : -1);
                    if (stat[i] == "even" && left != right)
                        ok = false;
                    if (stat[i] == "up" && left <= right)
                        ok = false;
                    if (stat[i] == "down" && left >= right)
                        ok = false;
                }
                if (ok)
                {
                    cout << c << " is the counterfeit coin and it is " << (fakeType ? "heavy." : "light.") << '\n';
                    goto next_case;
                }
            }
        }
    next_case:;
    }
    return 0;
}