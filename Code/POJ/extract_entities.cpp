#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    int count = 0;
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string line;
        getline(cin, line);
        int pos = 0;
        while ((pos = line.find("### ###", pos)) != string::npos)
            line.replace(pos, 7, " ");
        pos = 0;
        while ((pos = line.find("###", pos)) != string::npos)
        {
            count++;
            pos += 3;
        }
    }
    cout << count / 2 << endl;
    return 0;
}