#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    string a, b;
    cin >> a >> b;
    int maxLen = max(a.length(), b.length());
    a = string(maxLen - a.length(), '0') + a;
    b = string(maxLen - b.length(), '0') + b;
    string result(maxLen, '0');
    int carry = 0;
    for (int i = maxLen - 1; i >= 0; i--)
    {
        int sum = (a[i] - '0') + (b[i] - '0') + carry;
        carry = sum / 10;
        result[i] = (sum % 10) + '0';
    }
    if (carry > 0)
        result = "1" + result;
    result.erase(0, result.find_first_not_of('0'));
    if (result.empty())
        result = "0";
    cout << result << endl;
    return 0;
}