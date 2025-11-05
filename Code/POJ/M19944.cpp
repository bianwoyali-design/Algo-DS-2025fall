#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int input;
        cin >> input;
        int c = input / 1000000;
        int y = input % 1000000 / 10000;
        int d = input % 100;
        int m;
        if (input % 10000 / 100 == 1 || input % 10000 / 100 == 2)
        {
            m = input % 10000 / 100 + 12;
            y -= 1;
        }
        else
            m = input % 10000 / 100;
        if (y == -1)
        {
            c -= 1;
            y = 99;
        }
        int w = ((y + y / 4 + c / 4 - 2 * c + (13 * (m + 1)) / 5 + d - 1) + 700) % 7;
        switch (w)
        {
        case 1:
            cout << "Monday" << endl;
            break;
        case 2:
            cout << "Tuesday" << endl;
            break;
        case 3:
            cout << "Wednesday" << endl;
            break;
        case 4:
            cout << "Thursday" << endl;
            break;
        case 5:
            cout << "Friday" << endl;
            break;
        case 6:
            cout << "Saturday" << endl;
            break;
        case 0:
            cout << "Sunday" << endl;
            break;
        }
    }
    return 0;
}