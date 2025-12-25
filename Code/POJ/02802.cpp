#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

struct Node
{
    int x, y, seg, dir;
    bool operator>(const Node &u) const { return seg > u.seg; }
};

int dirs[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};

int dijkstra(vector<vector<int>> arr, int x1, int y1, int x2, int y2)
{
    vector<vector<vector<int>>> dist(arr.size(), vector<vector<int>>(arr[0].size(), vector<int>(5, 1e9)));
    priority_queue<Node, vector<Node>, greater<Node>> pq;

    dist[x1][y1][4] = 0;
    pq.push({x1, y1, 0, 4});

    arr[x2][y2] = 0;

    while (!pq.empty())
    {
        auto [x, y, seg, dir] = pq.top();
        pq.pop();

        if (x == x2 && y == y2)
            return seg;

        if (seg > dist[x][y][dir])
            continue;
        
        for (int i = 0; i < 4; i++)
        {
            int newX = x + dirs[i][0];
            int newY = y + dirs[i][1];
            int nseg = (i != dir ? seg + 1 : seg);
            if (newX >= 0 && newX < arr.size() && newY >= 0 && newY < arr[0].size() && arr[newX][newY] != 1)
                if (nseg < dist[newX][newY][i])
                {
                    dist[newX][newY][i] = nseg;
                    pq.push({newX, newY, nseg, i});
                }
        }
    }

    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int w, h, cnt = 0;
    while (cin >> w >> h)
    {
        if (w == 0 && h == 0)
            break;
        vector<vector<int>> arr(h + 2, vector<int>(w + 2, 0));
        cin.ignore();
        for (int i = 1; i <= h; i++)
        {
            string s;
            getline(cin, s);
            for (int j = 0; j < w; j++)
                if (s[j] == ' ')
                    arr[i][j + 1] = 0;
                else
                    arr[i][j + 1] = 1;
        }

        cout << "Board #" << ++cnt << ":\n";
        int x1, x2, y1, y2, cnt0 = 0;
        while (cin >> x1 >> y1 >> x2 >> y2)
        {
            if (x1 == 0 && x2 == 0 && y1 == 0 && y2 == 0)
                break;
            int n = dijkstra(arr, y1, x1, y2, x2);
            cout << "Pair " << ++cnt0 << ": ";
            if (n == -1)
                cout << "impossible.\n";
            else
                cout << n << " segments.\n";
        }
        cout << endl;
    }
    return 0;
}