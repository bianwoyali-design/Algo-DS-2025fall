#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; ++i)
        cin >> ratings[i];

    vector<int> left(n, 1);
    for (int i = 1; i < n; ++i)
    {
        if (ratings[i] > ratings[i - 1])
            left[i] = left[i - 1] + 1;
    }

    long long ans = 0;
    int right_len = 1;
    for (int i = n - 1; i >= 0; --i)
    {
        if (i < n - 1 && ratings[i] > ratings[i + 1])
            right_len += 1;
        else
            right_len = 1;
        ans += max(left[i], right_len);
    }

    cout << ans << '\n';
    return 0;
}