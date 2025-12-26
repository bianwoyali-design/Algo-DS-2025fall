#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n, m;
    cin >> n >> m;
    vector<bool> a(n, false);
    for (int i = 0; i < m; i++)
    {
        int ipt;
        cin >> ipt;
        a[ipt] = true;
    }

    int cnt = count(a.begin(), a.end(), true);
    if (cnt == n)
        cout << n;
    else
        for (int i = 0; i < n; i++)
            if (a[i] == false)
                cout << i << ' ';
    
    return 0;
}