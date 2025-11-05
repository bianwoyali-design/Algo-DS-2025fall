#include <iostream>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    string strFind;
    cin >> strFind;
    cin.ignore();
    string strText;
    getline(cin, strText);
    transform(strFind.begin(), strFind.end(), strFind.begin(), ::towlower);
    transform(strText.begin(), strText.end(), strText.begin(), ::towlower);
    int cnt = 0;
    int pos = 0, posFirst;
    while ((pos = strText.find(strFind, pos)) != string::npos)
    {
        if (pos == 0)
        {
            cnt++;
            posFirst = pos;
        }
        else if ((strText[pos - 1] < 'a' || strText[pos - 1] > 'z') && (strText[pos + strFind.size()] < 'a' || strText[pos + strFind.size()] > 'z'))
        {
            cnt++;
            if (cnt == 1)
                posFirst = pos;
        }
        pos += strFind.size();
    }
    if (cnt == 0)
        cout << -1 << endl;
    else
    {
        cout << cnt << ' ' << posFirst << endl;
    }
    return 0;
}