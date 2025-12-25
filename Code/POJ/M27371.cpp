#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string key;
    cin >> key;
    bool used[26] = {0};
    vector<vector<char>> arr(5, vector<char>(5));
    string table;
    for (char c : key)
    {
        if (c == 'j')
            c = 'i';
        if (!used[c - 'a'])
        {
            used[c - 'a'] = true;
            table += c;
        }
    }
    for (char c = 'a'; c <= 'z'; ++c)
    {
        if (c == 'j')
            continue;
        if (!used[c - 'a'])
        {
            used[c - 'a'] = true;
            table += c;
        }
    }
    for (int i = 0; i < 25; ++i)
        arr[i / 5][i % 5] = table[i];

    int n;
    cin >> n;
    while (n--)
    {
        string text;
        cin >> text;
        string prep;
        for (char c : text)
            prep += (c == 'j' ? 'i' : c);
        string res;
        for (int i = 0; i < prep.size();)
        {
            char a = prep[i], b;
            if (i + 1 == prep.size())
            {
                b = (a == 'x' ? 'q' : 'x');
                ++i;
            }
            else if (a == prep[i + 1])
            {
                b = (a == 'x' ? 'q' : 'x');
                ++i;
            }
            else
            {
                b = prep[i + 1];
                i += 2;
            }
            int ax, ay, bx, by;
            for (int x = 0; x < 5; ++x)
                for (int y = 0; y < 5; ++y)
                {
                    if (arr[x][y] == a)
                    {
                        ax = x;
                        ay = y;
                    }
                    if (arr[x][y] == b)
                    {
                        bx = x;
                        by = y;
                    }
                }
            if (ax == bx)
            {
                res += arr[ax][(ay + 1) % 5];
                res += arr[bx][(by + 1) % 5];
            }
            else if (ay == by)
            {
                res += arr[(ax + 1) % 5][ay];
                res += arr[(bx + 1) % 5][by];
            }
            else
            {
                res += arr[ax][by];
                res += arr[bx][ay];
            }
        }
        cout << res << '\n';
    }
    return 0;
}