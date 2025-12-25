#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution {
private:
    int minCam(const vector<int> &ranges) {
        int n = ranges.size(), m = *max_element(ranges.begin(), ranges.end());
        int curr = 0, next = 0, cnt = 0;
        while (curr < n) {
            next = curr + ranges[curr] + 1;
            for (int i = max(0, curr - m); i < min(n, curr + m + 1); i++)
                if (i - ranges[i] <= curr)
                    next = max(next, i + ranges[i] + 1);
            cnt++;
            curr = next;
        }
        return cnt;
    }
public:
    void init_out()
    {
        int n;
        cin >> n;
        vector<int> ranges(n);
        for (auto &a : ranges)
            cin >> a;
        cout << minCam(ranges) << '\n';
    }
};

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);
    Solution sol;
    sol.init_out();
    return 0;
}