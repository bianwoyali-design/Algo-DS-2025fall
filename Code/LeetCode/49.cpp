#include <iostream>
#include <vector>
#include <map>
#include <array>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> strs;
    string str;
    while (cin >> str)
        strs.push_back(str);
    
    map<array<int,128>, vector<string>> Hmap;
    for (auto &i : strs)
    {
        array<int,128> dic{};
        for (auto j : i)
            dic[j]++;
        Hmap[dic].push_back(i);
    }

    vector<vector<string>> aStrs;
    for (auto i : Hmap)
        aStrs.push_back(i.second);
    return 0;
}
