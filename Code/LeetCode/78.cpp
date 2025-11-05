#include <iostream>
#include <vector>
using namespace std;

void dfs(vector<int> nums, vector<vector<int>>& subsets, vector<int> t)
{
    if (nums.empty())
    {
        subsets.push_back(t);
        return;
    }
    t.push_back(nums[0]);
    nums.erase(nums.begin());
    dfs(nums, subsets, t);
    t.pop_back();
    dfs(nums, subsets, t);
}

vector<vector<int>> subsets(vector<int>& nums)
{
    vector<vector<int>> subsets;
    vector<int> t;
    dfs(nums, subsets, t);
    return subsets;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {1, 2, 3};
    for (auto i : subsets(nums))
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}