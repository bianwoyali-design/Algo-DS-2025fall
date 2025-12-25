#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> tag(n);
    for (int i = 0; i < n; i++)
        cin >> tag[i];
    map<string, int> list;
    while (m--)
    {
        string fr;
        cin >> fr;
        list[fr]++;
    }

    vector<int> trans_list;
    for (auto a : list)
        trans_list.push_back(a.second);

    sort(tag.begin(), tag.end());
    sort(trans_list.begin(), trans_list.end());
    int maxN = 0, minN = 0;
    for (int i = 0, j = trans_list.size() - 1; i < trans_list.size(); i++, j--)
        minN += trans_list[i] * tag[j];
    for (int i = tag.size() - 1, j = trans_list.size() - 1; j >= 0; i--, j--)
        maxN += trans_list[j] * tag[i];

    cout << minN << ' ' << maxN << '\n';
    return 0;
}