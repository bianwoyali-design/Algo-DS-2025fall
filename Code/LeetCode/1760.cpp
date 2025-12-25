#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
public:
    int minimumSize(vector<int> &nums, int maxOperations)
    {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        int mid;
        while (l < r)
        {
            mid = l + (r - l) / 2;
            int cnt = 0;
            for (const auto &n : nums)
            {
                cnt += (n - 1) / mid;
                if (cnt > maxOperations)
                    break;
            }
            if (cnt > maxOperations)
                l = mid + 1;
            else
                r = mid;
        }
        return l;
    }
};

int main()
{
    cin.tie(0)->sync_with_stdio(false);
    Solution sol;
    vector<int> nums = {2, 4, 8, 2};
    cout << sol.minimumSize(nums, 4) << '\n';
    return 0;
}