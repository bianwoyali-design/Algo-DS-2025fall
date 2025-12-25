#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool dfs(string word, string str[], bool vis[], int pos)
{
    if (word.length() == pos)
        return true;
    for (int i = 0; i < 4; i++)
    {
        if (!vis[i] && count(str[i].begin(), str[i].end(), word[pos]))
        {
            vis[i] = true;
            if (dfs(word, str, vis, pos + 1))
                return true;
            vis[i] = false;
        }
    }
    return false;
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    int n;
    cin >> n;
    string str[4];
    for (int i = 0; i < 4; i++)
        cin >> str[i];
    while (n--)
    {
        string word;
        cin >> word;
        bool vis[4] = {false, false, false, false};
        if (dfs(word, str, vis, 0))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}