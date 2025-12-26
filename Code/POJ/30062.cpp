#include <iostream>
#include <set>
#include <vector>
using namespace std;

set<vector<int>> vis;

void backtrack(int pos, vector<int> sub, const vector<int> &nums)
{
    if (pos == nums.size())
        return;
    for (int i = pos; i < nums.size(); i++)
        if (sub.empty() || sub.back() <= nums[i])
        {
            sub.push_back(nums[i]);
            if (sub.size() >= 2)
                vis.insert(sub);
            backtrack(i + 1, sub, nums);
            sub.pop_back();
        }
}

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<int> nums;
    int n;
    while (cin >> n)
        nums.push_back(n);
    vector<int> sub;

    backtrack(0, sub, nums);

    cout << vis.size() << '\n';
    return 0;
}