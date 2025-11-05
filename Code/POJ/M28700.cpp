#include <iostream>
using namespace std;

string intToRoman(int input)
{
    string roman[] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
    int num[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
    string res;
    for (int i = 0; i < 13; i++)
        while (input >= num[i])
        {
            input -= num[i];
            res += roman[i];
        }
    return res;
}

int RomanToint(string input)
{
    int num[256];
    num['I'] = 1; num['V'] = 5; num['X'] = 10;
    num['L'] = 50; num['C'] = 100; num['D'] = 500; num['M'] = 1000;
    int res = num[input.back()];
    for (int i = input.length() - 2; i >= 0; i--)
        if (num[input[i]] >= num[input[i + 1]])
            res += num[input[i]];
        else
            res -= num[input[i]];
    return res;
}
int main()
{
    string input;
    cin >> input;
    if (input[0] >= '0' && input[0] <= '9')
        cout << intToRoman(stoi(input)) << endl;
    else
        cout << RomanToint(input) << endl;
    return 0;
}