#include <iostream>
using namespace std;

int main()
{
    int k;
    string password;
    cin >> k >> password;
    k = k % 26; 
    for (int i = 0; i < password.length(); i++)
    {
        if (password[i] >= 'A' && password[i] <= 'Z')
        {
            password[i] = (password[i] - 'A' - k + 26) % 26 + 'A';
        }
        else if (password[i] >= 'a' && password[i] <= 'z')
        {
            password[i] = (password[i] - 'a' - k + 26) % 26 + 'a';
        }
    }
    cout << password << endl;
    return 0;
}