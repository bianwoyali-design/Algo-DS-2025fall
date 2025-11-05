#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        if (nums[left] > target)
            return 0;
        if (nums[right] < target)
            return nums.size();
        while (left < right)
        {
            if (nums[left] < target)
                left++;
            if (nums[right] > target)
                right++;
        }
        return right;
};