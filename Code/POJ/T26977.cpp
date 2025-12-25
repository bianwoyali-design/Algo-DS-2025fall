#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> height(n);
    int maxh = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> height[i];
        maxh = max(maxh, height[i]);
    }
    
    long long dp = 0;
    int l = 0, r = n - 1;
    int lh = 0, rh = 0;
    while (l < r)
    {
        lh = max(lh, height[l]);
        rh = max(rh, height[r]);
        if (lh < rh)
        {
            dp += lh - height[l];
            l++;
        }
        else
        {
            dp += rh - height[r];
            r--;
        }
    }
    cout << dp << '\n';
    return 0;
}