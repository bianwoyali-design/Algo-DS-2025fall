#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool isLeaf;

public:
    Trie() : children(10), isLeaf(false) {}

    auto insert_and_check(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            c -= '0';
            if (node->isLeaf)
                return false;
            if (node->children[c] == nullptr)
                node->children[c] = new Trie();
            node = node->children[c];
        }
        if (node->isLeaf)
            return false;
        for (int i = 0; i < 10; i++)
            if (node->children[i] != nullptr)
                return false;
        node->isLeaf = true;
        return true;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        bool check = false;
        vector<string> phone_num(n);
        for (int i = 0; i < n; i++)
            cin >> phone_num[i];

        sort(phone_num.begin(), phone_num.end());
        Trie *trie = new Trie();
        for (auto s : phone_num)
            if (!trie->insert_and_check(s))
            {
                cout << "NO\n";
                goto next;
            }
        cout << "YES\n";
    next:;
    }

    return 0;
}