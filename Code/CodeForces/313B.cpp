#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string str;
    cin >> str;
    int n;
    cin >> n;
    vector<int> pre(str.length(), 0);
    for (int i = 1; i < str.length(); i++)
        pre[i] = pre[i - 1] + (str[i] == str[i - 1] ? 1 : 0);
    while (n--)
    {
        int l, r;
        cin >> l >> r;
        cout << pre[r - 1] - pre[l - 1] << endl;
    }
    return 0;
}