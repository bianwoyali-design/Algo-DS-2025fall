#include <iostream>
#include <algorithm>
#include <vector>
#include <unordered_map>
using namespace std;

int minTime, MaxVal;

struct Node
{
    int r, l, h;
};

bool cmp(Node a, Node b)
{
    return a.h > b.h;
}

unordered_map<long long, int> memo;

long long encode(int x, int y, int it)
{
    return ((long long)x << 32) | ((long long)y << 16) | it;
}

int dfs(vector<Node>& p, int x, int y, int it)
{
    long long key = encode(x, y, it);
    if (memo.count(key))
        return memo[key];
    for (int i = it + 1; i < p.size(); i++)
    {
        if (y - p[i].h > MaxVal)
            return memo[key] = 1e9;
        else if (x >= p[i].l && x <= p[i].r)
        {
            int l = x - p[i].l + dfs(p, p[i].l, p[i].h, i);
            int r = p[i].r - x + dfs(p, p[i].r, p[i].h, i);
            return memo[key] = l < r ? l : r;
        }
    }
    return memo[key] = 0;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    while (k--)
    {
        int n, inix, iniy;
        cin >> n >> inix >> iniy >> MaxVal;
        vector<Node> plat;
        Node floor;
        floor.l = inix, floor.r = inix, floor.h = iniy;
        plat.push_back(floor);
        while (n--)
        {
            Node ipt;
            cin >> ipt.l >> ipt.r >> ipt.h;
            plat.push_back(ipt);
        }
        sort(plat.begin(), plat.end(), cmp);
        cout << iniy + dfs(plat, inix, iniy, 0) << '\n';
    }
    return 0;
}