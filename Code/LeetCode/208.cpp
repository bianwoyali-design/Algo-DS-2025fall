#include <iostream>
#include <vector>
using namespace std;

class Trie
{
private:
    vector<Trie*> children;
    bool isLeaf;

    Trie* searchPrefix(string prefix)
    {
        Trie* node = this;
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
        Trie* node = this;
        for (auto c : word)
        {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isLeaf = true;
    }

    auto search(string word)
    {
        return this->searchPrefix(word) != nullptr && this->searchPrefix(word)->isLeaf;
    }

    auto startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << '\n';
    cout << trie->search("app") << '\n';
    cout << trie->startsWith("app") << '\n';
    trie->insert("app");
    cout << trie->search("app") << '\n';

    return 0;
}