#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<vector<string>> ans;
vector<string> t;

bool is_Valid(string s)
{
    string tmp = s;
    reverse(s.begin(), s.end());
    return tmp == s;
}

void backtrack(int curr, string& s)
{
    if (curr == s.length())
    {
        ans.push_back(t);
        return;
    }
    for (int i = 1; i <= s.length() - curr; i++)
    {
        string subs = s.substr(curr, i);
        if (is_Valid(subs))
        {
            t.push_back(subs);
            backtrack(curr + i, s);
            t.pop_back();
        }
    }
}

vector<vector<string>> partition(string s)
{
    backtrack(0, s);
    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s = "aab";
    for (auto i : partition(s))
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}