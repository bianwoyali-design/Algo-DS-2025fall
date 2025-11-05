#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string eMail;
    while (cin >> eMail)
    {
        if (eMail[0] == '@' || eMail.back() == '@' || eMail[0] == '.' || eMail.back() == '.')
        {
            cout << "NO" << endl;
            continue;
        }
        int pos = 0, lpos;
        int cnt = 0;
        while ((pos = eMail.find('@', pos)) != string::npos)
        {
            eMail.erase(eMail.begin() + pos);
            cnt++;
            if (cnt > 1)
                continue;
            lpos = pos;
        }
        if (cnt > 1 || cnt == 0)
        {
            cout << "NO" << endl;
            continue;
        }
        if (eMail.find('.', lpos) == string::npos || eMail[lpos] == '.' || eMail[lpos - 1] == '.')
        {
            cout << "NO" << endl;
            continue;
        }
        cout << "YES" << endl;
    }
    return 0;
}