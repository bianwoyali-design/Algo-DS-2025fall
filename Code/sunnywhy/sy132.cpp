#include <iostream>
#include <vector>
using namespace std;

void permute(vector<bool>& valid, vector<int>& nums, int first, int n)
{
    if (first == n + 1)
    {
        for (int i = 0; i < n; i++)
            i < n - 1 ? cout << nums[i] << ' ' : cout << nums[i] << '\n';
        return;
    }
    for (int i = 1; i <= n; i++)
        if (valid[i])
        {
            valid[i] = false;
            nums.push_back(i);
            permute(valid, nums, first + 1, n);
            valid[i] = true;
            nums.pop_back();
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> nums;
    vector<bool> valid(n + 1, true);
    permute(valid, nums, 1, n);
    return 0;
}