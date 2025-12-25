#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    bool matrix[8][8];
    int queens[8];
    for (int i = 0; i < 8; i++)
        for (int j = 0; j < 8; j++)
        {
            cin >> matrix[i][j];
            if (matrix[i][j])
                queens[i] = j;
        }
    
    for (int i = 0; i < 8; i++)
        for (int j = i + 1; j < 8; j++)
        {
            if (queens[i] == queens[j])
            {
                cout << "NO";
                return 0;
            }
            if (abs(i - j) == abs(queens[i] - queens[j]))
            {
                cout << "NO";
                return 0;
            }
        }
    
    cout << "YES";
    return 0;
}