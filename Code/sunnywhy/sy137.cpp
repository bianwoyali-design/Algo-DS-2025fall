#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(101, 0);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        cin >> ipt;
        nums[ipt]++;
    }

    vector<vector<int>> combination;
    vector<int> tmp;
    auto dfs = [&](auto&& dfs, int idx) -> void
    {
        if (tmp.size() == k)
        {
            combination.push_back(tmp);
            return;
        }
        for (int i = idx; i <= 100; i++)
        {
            if (nums[i])
            {
                tmp.push_back(i);
                nums[i]--;
                if (nums[i])
                    dfs(dfs, i);
                else
                    dfs(dfs, i + 1);
                nums[i]++;
                tmp.pop_back();
            }
        }
    };

    dfs(dfs, 1);

    for (auto i : combination)
        for (int j = 0; j < i.size(); j++)
            j != k - 1 ? cout << i[j] << ' ' : cout << i[j] << '\n';
    return 0;
}