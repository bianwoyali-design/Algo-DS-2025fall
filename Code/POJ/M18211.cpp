#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    int p;
    vector<int> s;
    cin >> p;
    int ipt;
    while (cin >> ipt)
        s.push_back(ipt);

    sort(s.begin(), s.end());
    int left = 0, right = s.size() - 1;
    int own = 0, ene = 0;
    while (left <= right && p - s[left] >= 0)
    {
        p -= s[left];
        left++;
        own++;
    }
    int ans = own;
    while (left <= right && own > ene)
    {
        p += s[right--];
        ene++;
        while (left <= right && p - s[left] >= 0)
        {
            p -= s[left];
            left++;
            own++;
        }
        ans = ans > own - ene ? ans : own - ene;
    }

    cout << ans << endl;
    return 0;
}