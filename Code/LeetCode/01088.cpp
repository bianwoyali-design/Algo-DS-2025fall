#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

class Solution
{
private:
    struct Node
    {
        int x, y, z;
    };
    int R, C;
    vector<vector<int>> Height;
    vector<Node> list;

public:
    void readInput()
    {
        cin >> R >> C;
        Height.resize(R);
        for (int i = 0; i < R; i++)
        {
            Height[i].resize(C);
            for (int j = 0; j < C; j++)
            {
                cin >> Height[i][j];
                list.push_back(Node{i, j, Height[i][j]});
            }
        }
    }

    int longestSkatingPath()
    {
        vector<vector<int>> dp(R, vector<int>(C, 1));

        int dir[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
        int ans = 1;

        sort(list.begin(), list.end(), [](const Node &a, const Node &b)
             { return a.z > b.z; });
        for (const auto &a : list)
            for (const auto &xy : dir)
            {
                int newX = a.x + xy[0];
                int newY = a.y + xy[1];
                if (newX >= 0 && newX < R && newY >= 0 && newY < C && Height[newX][newY] < a.z)
                {
                    dp[newX][newY] = max(dp[newX][newY], dp[a.x][a.y] + 1);
                    ans = max(ans, dp[newX][newY]);
                }
            }
        
        return ans;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Solution Sol;
    Sol.readInput();
    cout << Sol.longestSkatingPath() << '\n';
    return 0;
}