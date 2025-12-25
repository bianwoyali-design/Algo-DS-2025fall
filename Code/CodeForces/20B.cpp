#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double a, b, c;
    scanf("%lf%lf%lf", &a, &b, &c);
    if (a == 0)
    {
        if (b == 0)
            if (c == 0)
                printf("-1\n");
            else 
                printf("0\n");
        else
            printf("1\n%lf\n", -c / b);
        return 0;
    }
    double delta = b * b - 4 * a * c;
    if (delta < 0)
        printf("0\n");
    else if (delta == 0)
        printf("1\n%lf\n", -b / (2 * a));
    else if (a > 0)
        printf("2\n%lf\n%lf\n", (-b - sqrt(delta)) / (2 * a), (-b + sqrt(delta)) / (2 * a));
    else
        printf("2\n%lf\n%lf\n", (-b + sqrt(delta)) / (2 * a), (-b - sqrt(delta)) / (2 * a));
    return 0;
}