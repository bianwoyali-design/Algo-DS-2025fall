#include <iostream>
#include <vector>
using namespace std;

int n;

void do_permutations(vector<vector<int>>& p, vector<int> nums, vector<int> tmp)
{
    if (tmp.size() == n)
    {
        p.push_back(tmp);
        return;
    }
    for (int i = 1; i <= 100; i++)
        if (nums[i])
        {
            nums[i]--;
            tmp.push_back(i);
            do_permutations(p, nums, tmp);
            tmp.pop_back();
            nums[i]++;
        }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> permutations;
    vector<int> tmp;
    do_permutations(permutations, nums, tmp);
    return permutations;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> nums(101, 0);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        cin >> ipt;
        nums[ipt]++;
    }
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < n; j++)
            j == n - 1 ? cout << ans[i][j] << '\n' : cout << ans[i][j] << ' ';
    return 0;
}