#include <iostream>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    int n;
    cin >> n;
    vector<size_t> h1(n), h2(n);
    for (size_t i = 0; i < n; i++)
        cin >> h1[i];
    for (size_t i = 0; i < n; i++)
        cin >> h2[i];
    
    vector<size_t> dp1(n + 1, 0), dp2(n + 1, 0);
    for (int i = 1; i <= n; i++)
    {
        dp1[i] = max(dp1[i - 1], dp2[i - 1] + h1[i - 1]);
        dp2[i] = max(dp2[i - 1], dp1[i - 1] + h2[i - 1]);
    }

    cout << max(dp1[n], dp2[n]) << '\n';
    return 0;
}