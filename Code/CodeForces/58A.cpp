#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;
    cin >> str;
    string target = "hello";
    int i = 0;
    for (auto c : str)
        if (i < target.length() && c == target[i])
            i++;
    if (i == target.length())
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}