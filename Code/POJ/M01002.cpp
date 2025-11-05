#include <iostream>
#include <algorithm>
#include <map>
using namespace std;

int main()
{
    int n;
    map<string, int> num_cnt;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string phone_num;
        cin >> phone_num;
        int pos = 0;
        while ((pos = phone_num.find('-', pos)) != string::npos)
            phone_num.erase(phone_num.begin() + pos);
        phone_num.insert(phone_num.begin() + 3, '-');
        transform(phone_num.begin(), phone_num.end(), phone_num.begin(), ::towupper);
        for (int j = 0; j < phone_num.size(); j++)
        {
            switch(phone_num[j])
            {
                case 'A':
                case 'B':
                case 'C':
                    phone_num[j] = '2';
                    break;
                case 'D':
                case 'E':
                case 'F':
                    phone_num[j] = '3';
                    break;
                case 'G':
                case 'H':
                case 'I':
                    phone_num[j] = '4';
                    break;
                case 'J':
                case 'K':
                case 'L':
                    phone_num[j] = '5';
                    break;
                case 'M':
                case 'N':
                case 'O':
                    phone_num[j] = '6';
                    break;
                case 'P':
                case 'R':
                case 'S':
                    phone_num[j] = '7';
                    break;
                case 'T':
                case 'U':
                case 'V':
                    phone_num[j] = '8';
                    break;
                case 'W':
                case 'X':
                case 'Y':
                    phone_num[j] = '9';
                    break;
            }
        }
        num_cnt[phone_num]++;
    }
    bool is_empty = false;
    for (const auto& pair : num_cnt)
        if (pair.second > 1)
        {
            cout << pair.first << " " << pair.second << endl;
            is_empty = 1;
        }
    if (is_empty == false)
        cout << "No duplicates." << endl;
    return 0;
}