#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> Habb = {"pop", "no", "zip", "zotz", "tzec", "xul", "yoxkin", "mol", "chen", "yax", "zac", "ceh", "mac", "kankin", "muan", "pax", "koyab", "cumhu", "uayet"};
    string Tzolkin[] = {"ahau", "imix", "ik", "akbal", "kan", "chicchan", "cimi", "manik", "lamat", "muluk", "ok", "chuen", "eb", "ben", "ix", "mem", "cib", "caban", "eznab", "canac"};
    cout << n << endl;
    for (int i = 0; i < n; i++)
    {
        int H_Year, H_Date;
        string H_Month;
        cin >> H_Date;
        cin.ignore();
        cin >> H_Month >> H_Year;
        int days;
        for (int i = 0; i < Habb.size(); i++)
            if (Habb[i] == H_Month)
            {
                days = i * 20;
                break;
            }
        days += H_Date + H_Year * 365;
        int T_Year = days / 260;
        string T_Month = Tzolkin[(days + 1) % 260 % 20];
        int T_Date = days % 260 % 13 + 1;
        cout << T_Date << ' ' << T_Month << ' ' << T_Year << endl;
    }
    return 0;
}