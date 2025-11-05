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
        cout << (1 / sqrt(5)) * (pow((1 + sqrt(5)) / 2, input) - pow((1 - sqrt(5)) / 2, input)) << endl;
    }
    return 0;
}