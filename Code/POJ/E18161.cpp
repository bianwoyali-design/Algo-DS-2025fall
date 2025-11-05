#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int matrix[3][101][101];
    int row[3], col[3];

    for (int i = 0; i < 3; i++)
    {
        scanf("%d%d", &row[i], &col[i]);
        for (int j = 0; j < row[i]; j++)
            for (int k = 0; k < col[i]; k++)
                scanf("%d", &matrix[i][j][k]);
    }

    if (col[0] != row[1] || row[0] != row[2] || col[1] != col[2])
    {
        printf("Error!\n");
        return 0;
    }

    vector<vector<int>> product(row[0], vector<int>(col[1], 0));

    for (int i = 0; i < row[0]; i++)
        for (int j = 0; j < col[1]; j++)
            for (int k = 0; k < col[0]; k++)
                product[i][j] += matrix[0][i][k] * matrix[1][k][j];

    for (int i = 0; i < row[0]; i++)
        for (int j = 0; j < col[1]; j++)
            product[i][j] += matrix[2][i][j];

    for (int i = 0; i < row[0]; i++)
        for (int j = 0; j < col[1]; j++)
        {
            printf("%d", product[i][j]);
            j == col[1] - 1 ? printf("\n") : printf(" ");
        }
        
    return 0;
}