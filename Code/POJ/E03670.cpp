#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int matrix[5][5];
    for (int i = 0; i < 5; ++i)
        for (int j = 0; j < 5; ++j)
            cin >> matrix[i][j];

    for (int i = 0; i < 5; ++i)
    {
        int maxVal = matrix[i][0], col = 0;
        for (int j = 1; j < 5; ++j)
        {
            if (matrix[i][j] > maxVal)
            {
                maxVal = matrix[i][j];
                col = j;
            }
        }
        bool isSaddle = true;
        for (int k = 0; k < 5; ++k)
        {
            if (matrix[k][col] < maxVal)
            {
                isSaddle = false;
                break;
            }
        }
        if (isSaddle)
        {
            cout << i + 1 << ' ' << col + 1 << ' ' << maxVal << '\n';
            return 0;
        }
    }
    cout << "not found\n";
    return 0;
}