#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    string str1, str2;
    cin >> str1 >> str2;
    transform(str1.begin(), str1.end(), str1.begin(), ::towlower);
    transform(str2.begin(), str2.end(), str2.begin(), ::towlower);
    for (int i = 0; i < str1.size(); i++)
    {
        if (str1[i] > str2[i])
        {
            cout << 1 << endl;
            return 0;
        }
        if (str1[i] < str2[i])
        {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << 0 << endl;
    return 0;
}