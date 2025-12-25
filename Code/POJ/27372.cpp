#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool isLeaf;

    Trie *searchPrefix(string prefix)
    {
        Trie *node = this;
        for (auto c : prefix)
        {
            if (node->children[c - 'a'] == nullptr)
                return nullptr;
            node = node->children[c - 'a'];
        }
        return node;
    }

public:
    Trie() : children(26), isLeaf(false) {}

    auto insert(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isLeaf = true;
    }

    auto startswith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<string> strs(n);
    for (int i = 0; i < n; i++)
        cin >> strs[i];

    sort(strs.begin(), strs.end());
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++)
    {
        Trie *node = new Trie();
        node->insert(strs[i]);
        for (int j = 0; j <= i; j++)
            if (!node->startswith(strs[j]))
                dp[i] += dp[j];
    }

    int sum = 1;
    for (int i = 0; i < n; i++)
        sum += dp[i];
    cout << sum << '\n';
    return 0;
}