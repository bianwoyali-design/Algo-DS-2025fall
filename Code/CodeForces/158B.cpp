#include <iostream>
using namespace std;

int main()
{
    int n, input;
    cin >> n;
    int s[5] = {0};
    for (int i = 0; i < n; i++)
    {
        cin >> input;
        s[input]++;
    }
    int taxi = 0;
    
    taxi += s[4];

    taxi += s[3];
    s[1] -= s[3];
    if (s[1] < 0)
        s[1] = 0;
    
    taxi += s[2] / 2 + s[2] % 2;
    if (s[2] % 2 != 0)
        s[1] -= 2;
    if (s[1] < 0)
        s[1] = 0;
    
    taxi += s[1] / 4;
    if (s[1] % 4 > 0)
        taxi++;
    
    cout << taxi << endl;
    return 0;
}
