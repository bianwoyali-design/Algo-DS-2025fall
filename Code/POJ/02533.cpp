//二分写法，非dp
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
    vector<int> arr(n);
    vector<int> dp(n, 1e9);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    
    for (auto i : arr)
    {
        auto it = lower_bound(dp.begin(), dp.end(), i);
        *it = i;
    }
    cout << lower_bound(dp.begin(), dp.end(), 1e8) - dp.begin() << '\n';
    return 0;
}