#include <iostream>
using namespace std;

int main()
{
    int n;
    int problem_to_be_solved = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == b && a == 1 || b == c && b == 1 || c == a && c == 1) problem_to_be_solved++;
    }
    cout << problem_to_be_solved << endl;
    return 0;
}