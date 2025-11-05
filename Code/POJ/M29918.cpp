#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> sum(n + 1, 0);
    for (int i = 1; i <= n / 2; i++)
        for (int j = i * 2; j <= n; j += i)
            sum[j] += i;
    for (int i = 2; i <= n; i++)
    {
        int tmp = sum[i];
        if (tmp > i && tmp <= n && sum[tmp] == i)
            cout << i << ' ' << tmp << endl;
    }
    return 0;
}