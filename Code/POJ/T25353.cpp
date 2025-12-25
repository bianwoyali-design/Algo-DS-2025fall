#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int prev;
    int height;
    int next;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<Node> nodes(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nodes[i].height;
        nodes[i].prev = i - 1;
        nodes[i].next = i + 1;
    }

    int start = 0, tail = n;
    vector<int> ans;
    while (start != tail)
    {
        vector<int> tmp;
        int curr = start;
        int maxn = nodes[curr].height;
        int minn = nodes[curr].height;
        while (curr != tail)
        {
            int rec = nodes[curr].height;
            if (maxn - rec <= d && rec - minn <= d)
            {
                tmp.push_back(rec);
                int prev_rec = nodes[curr].prev;
                int next_rec = nodes[curr].next;
                if (prev_rec != -1)
                    nodes[prev_rec].next = next_rec;
                else
                    start = next_rec;
                if (next_rec != n)
                    nodes[next_rec].prev = prev_rec;
                curr = next_rec;
            }
            else
                curr = nodes[curr].next;
            if (rec > maxn)
                maxn = rec;
            if (rec < minn)
                minn = rec;
            if (maxn - minn > 2 * d)
                break;
        }
        sort(tmp.begin(), tmp.end());
        for (auto i : tmp)
            ans.push_back(i);
    }

    for (auto i : ans)
        cout << i << '\n';
    return 0;
}