#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> arr(n);
    int l = 0, r = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        r += arr[i];
        l = max(l, arr[i]);
    }

    while (l < r)
    {
        int mid = l + (r - l) / 2;
        int tmp = 0;
        int cnt = 1;
        for (const auto &c : arr)
        {
            if (tmp + c > mid)
            {
                cnt++;
                tmp = c;
                if (cnt > m)
                    break;
            }
            else
                tmp += c;
        }
        if (cnt > m)
            l = mid + 1;
        else
            r = mid;
    }

    cout << l << '\n';
    return 0;
}