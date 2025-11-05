#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

int main()
{
    int n;
    vector<int> nums;
    while (cin >> n)
        nums.push_back(n);
    
    unordered_set<int> nums_set(nums.begin(), nums.end());
    int maxLen = 0;
    for (auto num : nums_set)
        if (!nums_set.count(num - 1))
        {
            int curr = num;
            int currLen = 1;
            while (nums_set.count(curr + 1))
            {
                curr++;
                currLen++;
            }
            maxLen = maxLen > currLen ? maxLen : currLen;
        }
    
    cout << maxLen << '\n';
    return 0;
}