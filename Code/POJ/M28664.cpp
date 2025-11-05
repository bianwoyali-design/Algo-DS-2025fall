#include <iostream>
using namespace std;

int main()
{
    int n;
    int c[17] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
    char ref[11] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
    cin >> n;
    string ID;
    for (int i = 0; i < n; i++)
    {
        cin >> ID;
        int check = 0;
        for (int j = 0; j < ID.length() - 1; j++)
            check += (ID[j] - '0') * c[j];
        int l = check % 11;
        char end = ID.back();
        if (ref[l] == end)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}