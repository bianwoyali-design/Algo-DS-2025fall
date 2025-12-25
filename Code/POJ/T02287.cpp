#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n)
    {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int score = 0;
        int mina = 0, minb = 0, maxa = a.size() - 1, maxb = b.size() - 1;
        while (n--)
        {
            if (a[maxa] > b[maxb])
            {
                score++;
                maxa--;
                maxb--;
            }
            else if (a[maxa] < b[maxb])
            {
                score--;
                mina++;
                maxb--;
            }
            else if (a[mina] > b[minb])
            {
                score++;
                mina++;
                minb++;
            }
            else
            {
                if (a[mina] < b[maxb])
                    score--;
                mina++;
                maxb--;
            }
        }

        cout << score * 200 << '\n';
    }
    return 0;
}