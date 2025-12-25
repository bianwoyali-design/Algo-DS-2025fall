#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (auto &i : a)
        cin >> i;
    for (auto &i : b)
        cin >> i;
    
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());

    int ans = 1e9;
    
    for (auto i : a)
        ans = min(max(abs(b[0] - i), abs(b.back() - i)), ans);

    cout << ans << '\n';
    return 0;
}