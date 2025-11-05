#include <iostream>
using namespace std;

int main()
{
    string str;
    int i = 0;
    int a = 1, b = 0;
    int ans = 0;
    while (getline(cin, str, '+'))
    {
        auto c_str = str.data();
        if (str[0] == 'n')
            b = stoi(str.substr(2));
        else
            sscanf(c_str, "%dn^%d", &a, &b);
        if (a >= 1)
            ans = ans > b ? ans : b;
    }
    printf("n^%d\n", ans);
    return 0;
}