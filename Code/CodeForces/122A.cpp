#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    int num;
    int Lucky_Num[14] = {4, 7, 44, 47, 74, 77, 444, 447, 477, 474, 744, 747, 777, 774};
    cin >> num;
    for (int i = 0; i < 14; i++)
    {
        if (num == Lucky_Num[i])
        {
            cout << "YES" << endl;
            return 0;
        }
        if (num % Lucky_Num[i] == 0)
        {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}