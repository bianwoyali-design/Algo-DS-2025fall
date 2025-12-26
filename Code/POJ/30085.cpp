#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    
    int w, n;
    cin >> w >> n;
    vector<int> p(n);
    for (int i = 0; i < n; i++)
        cin >> p[i];

    sort(p.begin(), p.end());
    int l = 0, r = p.size() - 1;
    int ans = n;
    while (l < r)
        if (p[l] + p[r] <= w)
        {
            ans--;
            l++;
            r--;
        }
        else
            r--;

    cout << ans << '\n';
    return 0;
}