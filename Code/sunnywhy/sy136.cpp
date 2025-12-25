#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vector<vector<int>> ans;
    vector<int> tmp;
    auto dfs = [&](auto&& dfs, int idx) -> void
    {
        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            tmp.push_back(nums[i]);
            dfs(dfs, i + 1);
            tmp.pop_back();
        }
    };

    dfs(dfs, 0);

    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < k; j++)
            j == k - 1 ? cout << ans[i][j] << '\n' : cout << ans[i][j] << ' ';
    return 0;
}