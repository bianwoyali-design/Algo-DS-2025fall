#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> str(n);
    for (int i = 0; i < n; i++)
        cin >> str[i];
    
    int r = str[0].size();
    for (int i = 1; i < n; i++)
    {
        int it = 0;
        for (; it < r; it++)
            if (str[1][it] != str[0][it])
                break;
        r = it;
    }
    
    for (int i = 0; i < r; i++)
        cout << str[0][i];
    cout << endl;
    return 0;
}