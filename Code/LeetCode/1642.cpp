#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution
{
public:
    int furthestBuilding(vector<int> &heights, int bricks, int ladders)
    {
        int n = heights.size();
        priority_queue<int, vector<int>, greater<int>> Heap;
        for (int i = 0; i < n - 1; i++)
        {
            int diff = heights[i + 1] - heights[i];
            if (diff > 0)
            {
                Heap.push(diff);
                if (Heap.size() > ladders)
                {
                    bricks -= Heap.top();
                    Heap.pop();
                }
            }
            if (bricks < 0)
                return i;
        }
        return n - 1;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> heights = {4, 12, 2, 7, 3, 18, 20, 3, 19};
    int bricks = 17;
    int ladders = 0;
    Solution Sol;
    cout << Sol.furthestBuilding(heights, bricks, ladders);

    return 0;
}