#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    vector<int> arr(n + 1, 0);
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    
    map<int, int> prefixed;
    prefixed[0] = 0;
    int prefix = 0;

    int maxn = 0;
    for (int i = 1; i <= n; i++)
    {
        prefix += (arr[i] - 520);
        if (prefixed.find(prefix) != prefixed.end())
            maxn = max(maxn, i - prefixed[prefix]);
        else
            prefixed[prefix] = i;
    }

    cout << maxn * 520 << '\n';
    return 0;
}
