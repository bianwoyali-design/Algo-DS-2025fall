#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        int length;
        int ants;
        cin >> length >> ants;
        int maxP = 0, minP = 0;
        while (ants--)
        {
            int pos;
            cin >> pos;
            int dismax = max(pos, length - pos);
            int dismin = min(pos, length - pos);
            maxP = maxP > dismax ? maxP : dismax;
            minP = minP > dismin ? minP : dismin;
        }
        cout << minP << ' ' << maxP << '\n';
    }
    return 0;
}