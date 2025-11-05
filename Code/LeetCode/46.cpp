#include <iostream>
#include <vector>
using namespace std;

void permutation(vector<vector<int>>& res, vector<int>& nums, int first, int len)
{
    if (first == len)
    {
        res.emplace_back(nums);
        return;
    }
    for (int i = first; i < len; i++)
    {
        swap(nums[i], nums[first]);
        permutation(res, nums, first + 1, len);
        swap(nums[i], nums[first]);
    }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> res;
    permutation(res, nums, 0, nums.size());
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums;
    int ipt;
    while (cin >> ipt)
        nums.push_back(ipt);
    vector<vector<int>> ans = permute(nums);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}