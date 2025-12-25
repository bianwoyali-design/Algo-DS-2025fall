#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    vector<int> c(n);
    for (auto &i : c)
        cin >> i;
    map<int, int> hash;
    int l = 0;
    long long cnt = 0;
    for (int r = 0; r < n; r++)
    {
        hash[c[r]]++;
        while (hash.size() > k)
        {
            hash[c[l]]--;
            if (!hash[c[l]])
                hash.erase(c[l]);
            l++;
        }
        cnt += r - l + 1;
    }
    cout << cnt << '\n';
    return 0;
}