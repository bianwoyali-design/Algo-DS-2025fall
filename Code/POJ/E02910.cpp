#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string str;
    cin >> str;
    for (int i = 0; i < str.size();)
    {
        if (str[i] >= '0' && str[i] <= '9')
        {
            string number = "";
            while(str[i] >= '0' && str[i] <= '9')
            {
                number += str[i];
                i++;
            }
                cout << stoi(number) << endl;
        }
        else i++;
    }
    return 0;
}