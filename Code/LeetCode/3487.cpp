#include <iostream>
#include <set>
#include <vector>
using namespace std;

int main()
{
    vector<int> nums = {1, 2, -1, -2, 1, 0, -1};
    set<int> n;
    for (int i = 0; i < nums.size(); i++)
        n.insert(nums[i]);
    auto i = n.rbegin();
    int sum = *i;
    i++;
    for (; i != n.rend(); i++)
    {
        if (sum >= sum + *i)
            break;
        sum += *i;
    }
    return sum;
}