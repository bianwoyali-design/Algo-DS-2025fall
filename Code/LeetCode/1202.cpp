#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;

class Disjoint
{
private:
    vector<int> pa, sz;

public:
    void _init(int n)
    {
        pa.resize(n);
        for (int i = 0; i < n; i++)
            pa[i] = i;
        sz.assign(n, 1);
    }

    int _find(int i)
    {
        return pa[i] == i ? i : _find(pa[i]);
    }

    void _union(int i, int j)
    {
        int irep = _find(pa[i]);
        int jrep = _find(pa[j]);
        if (irep == jrep)
            return;
        if (sz[irep] < sz[jrep])
        {
            pa[irep] = jrep;
            sz[jrep] += sz[irep];
        }
        else
        {
            pa[jrep] = irep;
            sz[irep] += sz[jrep];
        }
    }
};

class Solution
{
public:
    string smallestStringWithSwaps(string s, vector<vector<int>> &pairs)
    {
        Disjoint dsu;
        int n = s.length();
        dsu._init(n);
        for (const auto &i : pairs)
            dsu._union(i[0], i[1]);

        map<int, priority_queue<char, vector<char>, greater<char>>> hash;
        for (int i = 0; i < n; i++)
            hash[dsu._find(i)].push(s[i]);

        string ans;
        for (int i = 0; i < n; i++)
        {
            int irep = dsu._find(i);
            ans += hash[irep].top();
            hash[irep].pop();
        }

        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    string s = "dcab";
    vector<vector<int>> pairs = {{0, 3}, {1, 2}};
    Solution Sol;
    cout << Sol.smallestStringWithSwaps(s, pairs);
    return 0;
}