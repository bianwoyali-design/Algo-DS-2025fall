#include <iostream>
using namespace std;

int main()
{
    int n;
    int i = 0, crime = 0;
    int event[100001];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> event[i];
    for (int i = n - 1; i >= 0;)
    {
        while (i > 0)
        {
            if (event[i] != -1)
                break;
            crime += event[i];
            i--;
        }
        if (crime <= 0)
            crime += event[i];
        if (crime > 0)
            crime = 0;
        i--;
    }
    
    cout << -crime << endl;
    return 0;
}