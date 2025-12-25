#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string footBall;
    cin >> footBall;
    if (footBall.find("0000000", 0) != string::npos || footBall.find("1111111", 0) != string::npos)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    return 0;
}