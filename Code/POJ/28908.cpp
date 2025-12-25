#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int val[3]{0};
    char var, ch1, ch2, chT;
    int i = 0;
    while (cin >> var >> ch1 >> ch2 >> val[var - 'a'] >> chT);
    for (int i = 0; i < 3; i++)
        cout << val[i] << ' ';
    return 0;
}