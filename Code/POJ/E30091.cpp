#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    int maxN = 0;
    cin >> L >> N;
    if (N == 0)
    {
        cout << "0 0\n";
        return 0;
    }
    int maxt = 0, mint = 0;
    while (N--)
    {
        int pos;
        cin >> pos;
        mint = max(mint, min(pos, L + 1 - pos));
        maxt = max(maxt, max(pos, L + 1 - pos));
    }

    cout << mint << ' ' << maxt << '\n';
    return 0;
}