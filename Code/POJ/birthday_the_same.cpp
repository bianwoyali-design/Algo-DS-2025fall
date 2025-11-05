#include <iostream>
#include <string>
using namespace std;

int main()
{
    string ID, date[13][32][101];
    int n, Month, Day, count[13][32] = {0};
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        cin >> ID >> Month >> Day;
        date[Month][Day][count[Month][Day]++] = ID;
    }
    for (int i = 1; i <= 12; i++)
        for (int j = 1; j <= 31; j++)
        {
            if (count[i][j] > 1)
            {
                printf("%d %d ", i, j);
                for (int k = 0; k < count[i][j]; k++)
                    cout << date[i][j][k] << " ";
                printf("\n");
            }
        }
    return 0;
}