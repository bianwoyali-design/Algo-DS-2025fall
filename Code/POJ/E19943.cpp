#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> L(n, vector<int>(n, 0));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        L[a][a]++;
        L[b][b]++;
        L[a][b]--;
        L[b][a]--;
    }

    for (auto i : L)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}