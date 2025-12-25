#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums)
{
    int n = nums.size();
    if (n < 2)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    
    vector<int> dp(n);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

    int maxVal = 0;
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        maxVal = max(maxVal, dp[i]);
    }

    return maxVal;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2, 7, 9 ,3, 1};
    cout << rob(nums) << '\n';

    return 0;
}