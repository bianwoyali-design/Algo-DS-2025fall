#include <vector>
#include <iostream>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int ans = 0;
    int k = 0;
    for (int i = 0; i <= n; i++)
    {
        while (arr[k] < i && k < n)
            k++;
        if (k == i && (k == n || arr[k] > i))
            ans++;
    }
    cout << ans << '\n';
    return 0;
}