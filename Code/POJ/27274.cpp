#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    string str;
    cin >> str;
    int n = str.length(), m = floor(log2(n));
    string ans;
    for (int i = 0; i <= m / 2; i++)
    {
        ans += str[int(pow(2, i)) - 1];
        ans += str[int(pow(2, m - i)) - 1];
    }
    if (m % 2 == 0)
        ans.pop_back();
    cout << ans << '\n';
    return 0;
}