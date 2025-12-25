# Assignment #C: bfs & dp

Updated 1436 GMT+8 Nov 25, 2025

2025 fall, Complied by <mark>张真铭 元培学院</mark>



**说明：**

1）请把每个题目解题思路（可选），源码Python, 或者C++（已经在Codeforces/Openjudge上AC），截图（包含Accepted），填写到下面作业模版中（推荐使用 typora https://typoraio.cn ，或者用word）。AC 或者没有AC，都请标上每个题目大致花费时间。

2）提交时候先提交pdf文件，再把md或者doc文件上传到右侧“作业评论”。Canvas需要有同学清晰头像、提交文件有pdf、"作业评论"区有上传的md或者doc附件。

3）如果不能在截止前提交作业，请写明原因。



## 1. 题目

### sy321迷宫最短路径

bfs, https://sunnywhy.com/sfbj/8/2/321

思路：



代码：

```cpp
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int xy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

struct Node
{
    int x, y;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<bool>> in_queue(n, vector<bool>(m, false));
    vector<vector<Node>> pos(n, vector<Node>(m, {-1, -1}));
    auto bfs = [&](Node start) -> void
    {
        queue<Node> q;
        q.push(start);
        in_queue[start.x][start.y] = true;

        while (!q.empty())
        {
            Node front = q.front();
            q.pop();
            if (front.x == n - 1 && front.y == m - 1)
                return;
            for (int i = 0; i < 4; i++)
            {
                Node next;
                next.x = front.x + xy[i][0];
                next.y = front.y + xy[i][1];
                if (next.x >= 0 && next.x < n && next.y >= 0 && next.y < m && !arr[next.x][next.y] && !in_queue[next.x][next.y])
                {
                    q.push(next);
                    in_queue[next.x][next.y] = true;
                    pos[next.x][next.y] = {front.x, front.y};
                }
            }
        }
    };

    auto print = [&](auto &&print, Node end) -> void
    {
        Node prev = pos[end.x][end.y];
        if (prev.x == -1 && prev.y == -1)
        {
            cout << end.x + 1 << ' ' << end.y + 1 << '\n';
            return;
        }
        print(print, prev);
        cout << end.x + 1 << ' ' << end.y + 1 << '\n';
    };

    bfs({0, 0});
    print(print, {n - 1, m - 1});

    return 0;
}
```
>共用时1h


代码运行截图 <mark>（至少包含有"Accepted"）</mark>
![alt text](image-139.png)




### sy324多终点迷宫问题

bfs, https://sunnywhy.com/sfbj/8/2/324

思路：



代码：

```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    vector<vector<int>> steps(n, vector<int>(m, -1));
    vector<vector<bool>> in_queue(n, vector<bool>(m, false));

    queue<pair<int, int>> q;
    q.push({0, 0});
    in_queue[0][0] = true;
    steps[0][0] += 1;
    
    int step = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 4; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !arr[newX][newY] && !in_queue[newX][newY])
                {
                    q.push({newX, newY});
                    in_queue[newX][newY] = true;
                    steps[newX][newY] = step + 1;
                }
            }
        }
        step++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            j == m - 1 ? cout << steps[i][j] << '\n' : cout << steps[i][j] << ' ';

    return 0;
}
```
>共用时25min


代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-140.png)



### M02945: 拦截导弹

dp, greedy http://cs101.openjudge.cn/pctbook/M02945

思路：



代码：
DP:
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    vector<int> dp(n, 1);
    int maxN = 1;
    for (int i = 1; i < n; i++)
        for (int j = 0; j < i; j++)
            if (h[i] <= h[j])
            {
                dp[i] = max(dp[i], dp[j] + 1);
                maxN = max(dp[i], maxN);
            }

    cout << maxN << '\n';
    return 0;
}
```

BISECT
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> h(n);
    for (int i = 0; i < n; i++)
        cin >> h[i];

    reverse(h.begin(), h.end());
    auto bisect_algorithm = [&]() -> int
    {
        vector<int> dp(n, 1e9);
        for (auto i : h)
            *upper_bound(dp.begin(), dp.end(), i) = i;
        return upper_bound(dp.begin(), dp.end(), 1e8) - dp.begin();
    };

    cout << bisect_algorithm() << '\n';
    return 0;
}
```

>共用时1h

代码运行截图 <mark>（至少包含有"Accepted"）</mark>
![alt text](image-141.png)
![alt text](image-142.png)



### 189A. Cut Ribbon

brute force/dp, 1300, https://codeforces.com/problemset/problem/189/A

思路：



代码：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    int cut[3];
    for (int i = 0; i < 3; i++)
        cin >> cut[i];

    vector<int> dp(n + 1, -1e9);
    dp[0] = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j < 3; j++)
            if (i >= cut[j])
                dp[i] = max(dp[i], dp[i - cut[j]] + 1);
    
    cout << dp[n] << '\n';
    return 0;
}
```

>共用时10min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-143.png)





### M01384: Piggy-Bank

dp, http://cs101.openjudge.cn/practice/01384/

思路：



代码：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int e, f;
        cin >> e >> f;
        int n;
        cin >> n;
        vector<int> p(n);
        vector<int> w(n);
        for (int i = 0; i < n; i++)
            cin >> p[i] >> w[i];
        
        int capacity = f - e;
        vector<int> dp(capacity + 1, 1e9);
        dp[0] = 0;
        for (int i = 1; i <= capacity; i++)
            for (int j = 0; j < n; j++)
                if (w[j] <= i)
                    dp[i] = min(dp[i - w[j]] + p[j], dp[i]);
        
        if (dp[capacity] < 1e9)
            cout << "The minimum amount of money in the piggy-bank is " << dp[capacity] << ".\n";
        else
            cout << "This is impossible.\n";
    }

    return 0;
}

```

>共用时15min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-144.png)



### M02766: 最大子矩阵

dp, kadane, http://cs101.openjudge.cn/pctbook/M02766

思路：



代码：
O(n^3):
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    
    int max_glob = 0;
    for (int i = 0; i < n; i++)
        for (int j = i; j < n; j++)
        {
            int max_curr = 0;
            for (int k = 0; k < n; k++)
            {
                int sum_col = 0;
                for (int l = i; l <= j; l++)
                    sum_col += m[l][k];
                max_curr = max(sum_col, max_curr + sum_col);
                max_glob = max(max_glob, max_curr);
            }
        }
    
    cout << max_glob << '\n';
    return 0;
}
```
进行了一番优化到O(n^2):
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> m(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> m[i][j];
    
    int max_glob = 0;
    for (int i = 0; i < n; i++)
    {
        vector<int> sum_col(n, 0);
        for (int j = i; j < n; j++)
        {
            for (int k = 0; k < n; k++)
                sum_col[k] += m[j][k];
            int max_curr = sum_col[0];
            for (int k = 1; k < n; k++)
            {
                max_curr = max(sum_col[k], max_curr + sum_col[k]);
                max_glob = max(max_glob, max_curr);
            }
        }
    }

    cout << max_glob << '\n';
    return 0;
}
```
>共用时30min


代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-146.png)



## 2. 学习总结和收获

<mark>如果作业题目简单，有否额外练习题目，比如：OJ“计概2024fall每日选做”、CF、LeetCode、洛谷等网站题目。</mark>


### sy322
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[8][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}, {2, 0}, {0, 2}, {-2, 0}, {0, -2}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    queue<pair<int, int>> q;
    vector<vector<bool>> in_queue(n, vector<bool>(m, false));
    int steps = 0;
    q.push({0, 0});
    in_queue[0][0] = true;

    auto bfs = [&]() -> int
    {
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt--)
            {
                pair<int, int> front;
                front = q.front();
                q.pop();
                if (front.first == n - 1 && front.second == m - 1)
                    return steps;
                for (int i = 0; i < 8; i++)
                {
                    int newX = front.first + xy[i][0];
                    int newY = front.second + xy[i][1];
                    int HalfnewX = front.first + xy[i][0] / 2;
                    int HalfnewY = front.second + xy[i][1] / 2;
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && !in_queue[newX][newY] && !arr[newX][newY] && !arr[HalfnewX][HalfnewY])
                    {
                        q.push({newX, newY});
                        in_queue[newX][newY] = true;
                    }
                }
            }
            steps++;
        }
        return -1;
    };

    cout << bfs() << '\n';
    return 0;
}
```
![alt text](image-145.png)

### sy323
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[4][2] = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
queue<pair<int, int>> q;
bool in_queue[101][101]{false};
char arr[101][101];
pair<int, int> start, termination;

int bfs(int n, int m)
{
    q.push(start);
    in_queue[start.first][start.second] = true;

    int steps = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            if (front.first == termination.first && front.second == termination.second)
                return steps;
            for (int i = 0; i < 4; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !in_queue[newX][newY] && arr[newX][newY] != '*')
                {
                    q.push({newX, newY});
                    in_queue[newX][newY] = true;
                }
            }
        }
        steps++;
    }
    return -1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 'S')
                start = {i, j};
            if (arr[i][j] == 'T')
                termination = {i, j};
        }
    
    cout << bfs(n, m) << '\n';
    return 0;
}
```
![alt text](image-147.png)

### sy325
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> arr(n, vector<int>(m));
    vector<pair<int, int>> tp;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
            if (arr[i][j] == 2)
                tp.push_back({i, j});
        }

    queue<pair<int, int>> q;
    vector<vector<int>> inqueue(n, vector<int>(m, false));
    q.push({0, 0});
    inqueue[0][0] = true;

    auto bfs = [&]() -> int
    {
        int steps = 0;
        while (!q.empty())
        {
            int cnt = q.size();
            while (cnt--)
            {
                pair<int, int> front = q.front();
                q.pop();
                if (front.first == n - 1 && front.second == m - 1)
                    return steps;
                for (int i = 0; i < 4; i++)
                {
                    int newX = front.first + xy[i][0];
                    int newY = front.second + xy[i][1];
                    if (newX >= 0 && newX < n && newY >= 0 && newY < m && arr[newX][newY] != 1 && !inqueue[newX][newY])
                    {

                        if (arr[newX][newY] == 2)
                            for (auto i : tp)
                            {
                                q.push(i);
                                inqueue[i.first][i.second] = true;
                            }
                        else
                        {
                            q.push({newX, newY});
                            inqueue[newX][newY] = true;
                        }
                    }
                }
            }
            steps++;
        }
        return -1;
    };

    cout << bfs() << '\n';
    return 0;
}
```
![alt text](image-148.png)

### sy326
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y;
    cin >> n >> m >> x >> y;

    queue<pair<int, int>> q;
    vector<vector<bool>> inqueue(n, vector<bool>(m, false));
    vector<vector<int>> step(n, vector<int>(m, -1));
    q.push({x - 1, y - 1});
    inqueue[x - 1][y - 1] = true;
    step[x - 1][y - 1] += 1;

    int steps = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !inqueue[newX][newY])
                {
                    q.push({newX, newY});
                    inqueue[newX][newY] = true;
                    step[newX][newY] = steps + 1;
                }
            }
        }
        steps++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            j == m - 1 ? cout << step[i][j] << '\n' : cout << step[i][j] << ' ';

    return 0;
}
```
![alt text](image-149.png)

### sy327
```cpp
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int xy[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {2, -1}, {-2, 1}, {1, -2}, {-2, -1}, {-1, -2}};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, x, y;
    cin >> n >> m >> x >> y;
    int k;
    cin >> k;
    vector<vector<bool>> barrier(n, vector<bool>(m, false));
    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        barrier[a - 1][b - 1] = true;
    }
    
    queue<pair<int, int>> q;
    vector<vector<bool>> inqueue(n, vector<bool>(m, false));
    vector<vector<int>> step(n, vector<int>(m, -1));
    q.push({x - 1, y - 1});
    inqueue[x - 1][y - 1] = true;
    step[x - 1][y - 1] += 1;

    int steps = 0;
    while (!q.empty())
    {
        int cnt = q.size();
        while (cnt--)
        {
            pair<int, int> front = q.front();
            q.pop();
            for (int i = 0; i < 8; i++)
            {
                int newX = front.first + xy[i][0];
                int newY = front.second + xy[i][1];
                int HalfnewX = front.first + xy[i][0] / 2;
                int HalfnewY = front.second + xy[i][1] / 2;
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !inqueue[newX][newY] && !barrier[newX][newY] && !barrier[HalfnewX][HalfnewY])
                {
                    q.push({newX, newY});
                    inqueue[newX][newY] = true;
                    step[newX][newY] = steps + 1;
                }
            }
        }
        steps++;
    }

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            j == m - 1 ? cout << step[i][j] << '\n' : cout << step[i][j] << ' ';

    return 0;
}
```
![alt text](image-150.png)

### 01742
思路：
这题数据给的非常极限，如果用多重背包常用的常规二进制拆分，大约就在3000ms左右（这还是C++，py显然过不了）。所以我写完第一版之后是很不满意的。

暴力二进制拆分+01背包，十分丑陋。

时间复杂度：O(n × log max(C) × m)；
空间复杂度：O(m + n log max(C))
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && n != 0 && m != 0)
    {
        vector<int> A(n);
        vector<int> C(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> C[i];
        
        vector<int> w;
        for (int i = 0; i < n; i++)
        {
            int k = 1;
            while (k <= C[i])
            {
                w.push_back(A[i] * k);
                C[i] -= k;
                k *= 2;
            }
            if (C[i] > 0)
                w.push_back(A[i] * C[i]);
        }

        vector<int> dp(m + 1, -1e9);
        dp[0] = 0;
        for (int i = 0; i < w.size(); i++)
            for (int j = m; j >= w[i]; j--)
                dp[j] = max(dp[j], dp[j - w[i]] + 1);
        int ans = 0;
        for (auto i : dp)
            if (i > 0)
                ans++;
        
        cout << ans << '\n';
    }
    return 0;
}
```
![alt text](image-152.png)

于是想着能不能用完全背包的思路去做，然后试了一下，发现快多了

这里用了一个数组记录当前面值的coin在不同状态所用的次数
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && n && m)
    {
        vector<int> A(n), C(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> C[i];
        
        vector<bool> dp(m + 1, false);
        dp[0] = true;
        
        for (int i = 0; i < n; i++)
        {
            vector<int> used(m + 1, 0);
            for (int j = A[i]; j <= m; j++)
                if (!dp[j] && dp[j - A[i]] && used[j - A[i]] < C[i])
                {
                    dp[j] = true;
                    used[j] = used[j - A[i]] + 1;
                }
        }
        
        int ans = count(dp.begin() + 1, dp.end(), true);
        cout << ans << '\n';
    }
    return 0;
}
```
![alt text](image-151.png)

但是还是不满意，在D老师的启发下使用了bitset用二进制表示状态

这个思路可用于一般的多重背包问题，应该是极限优化了
```cpp
#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    while (cin >> n >> m && n && m)
    {
        vector<int> A(n), C(n);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        for (int i = 0; i < n; i++)
            cin >> C[i];
        
        bitset<100001> dp;
        dp[0] = 1;
        for (int i = 0; i < n; i++)
        {
            int k = 1;
            while (k <= C[i])
            {
                dp |= dp << A[i] * k;
                C[i] -= k;
                k *= 2;
            }
            if (C[i] > 0)
                dp |= dp << A[i] * C[i];
        }

        int ans = 0;
        for (int i = 1; i <= m; i++)
            ans += dp[i];
        
        cout << ans << '\n';
    }
    return 0;
}
```

># 代码详细解释：使用bitset优化的多重背包
>
>这是一个使用 **bitset优化** 和 **二进制拆分** 的多重背包解决方案，用于计算能够组成多少种不同的金额（从1到m）。
>
>## 代码逻辑分解
>
>### 1. **数据结构**
>```cpp
>bitset<100001> dp;
>```
>- 创建大小为100001的bitset（因为m最大为100000，加上索引0）
>- 每个位表示对应金额是否可达（1=可达，0=不可达）
>- `dp[0] = 1` 表示金额0总是可达（不使用任何硬币）
>
>### 2. **核心算法：二进制拆分+bitset优化**
>
>对于每种硬币 `(A[i], C[i])`：
>```cpp
>int k = 1;
>while (k <= C[i]) {
>    dp |= dp << A[i] * k;
>    C[i] -= k;
>    k *= 2;
>}
>if (C[i] > 0)
>    dp |= dp << A[i] * C[i];
>```
>
>**示例**：假设当前硬币面值3，数量5
>```
>初始数量 C[i] = 5
>第一次：k = 1, val = 3×1 = 3, C[i] = 4, k = 2
>第二次：k = 2, val = 3×2 = 6, C[i] = 2, k = 4
>第三次：k = 4 > C[i] (2)，跳出循环
>剩余：C[i] = 2 > 0, val = 3×2 = 6
>```
>
>这样将5个3元硬币拆分为：3, 6, 6（对应1个、2个、2个）
>
>### 3. **bitset操作：`dp |= dp << val`**
>
>假设当前dp状态：金额0和3可达
>```
>dp = 00001001  (位0和位3为1)
>          ↓
>金额: 0 1 2 3 4 5 6 7
>```
>
>执行 `dp |= dp << 6`：
>```
>dp << 6 = 01001000  (位6和位9为1)
>          ↓
>dp | (dp << 6) = 01001001  (位0,3,6,9为1)
>```
>
>现在金额0,3,6,9可达。
>
>### 4. **为什么这样可行？**
>
>**二进制拆分原理**：
>- 任何整数都可以表示为2的幂次和（如5=1+2+2）
>- 通过拆分，将C[i]个相同物品转换为O(log C[i])个不同物品
>- 每个拆分后的物品只能用一次（0/1背包）
>
>**bitset优化原理**：
>- `dp << val`：将所有可达金额增加val
>- `|=`：合并新旧状态
>- 位运算的并行性使其非常高效
>
>### 5. **完整示例**
>
>输入：
>```
>n=2, m=10
>A = {2, 3}
>C = {2, 2}
>```
>
>执行过程：
>
>**初始**：`dp[0] = 1`
>```
>金额: 0 1 2 3 4 5 6 7 8 9 10
>dp:   1 0 0 0 0 0 0 0 0 0 0
>```
>
>**处理第一种硬币(2元,2个)**：
>- 拆分：2 = 1 + 1
>- 第一次：`dp |= dp << 2`
>  ```
>  dp << 2:  0 0 1 0 0 0 0 0 0 0 0
>  dp:       1 0 1 0 0 0 0 0 0 0 0  (金额0,2可达)
>  ```
>- 第二次：`dp |= dp << 2`
>  ```
>  dp << 2:  0 0 1 0 1 0 0 0 0 0 0
>  dp:       1 0 1 0 1 0 0 0 0 0 0  (金额0,2,4可达)
>  ```
>
>**处理第二种硬币(3元,2个)**：
>- 拆分：2 = 1 + 1
>- 第一次：`dp |= dp << 3`
>  ```
>  dp << 3:  0 0 0 1 0 1 0 1 0 0 0
>  dp:       1 0 1 1 1 1 0 1 0 0 0  (金额0,2,3,4,5,7可达)
>  ```
>- 第二次：`dp |= dp << 3`
>  ```
>  dp << 3:  0 0 0 1 0 1 1 1 0 1 0
>  dp:       1 0 1 1 1 1 1 1 0 1 0  (金额0,2,3,4,5,6,7,9可达)
>  ```
>
>**结果**：
>- 可达金额：0,2,3,4,5,6,7,9
>- 1~10中可达的：2,3,4,5,6,7,9 共7种
>
>### 6. **时间复杂度分析**
>
>- 二进制拆分：每种硬币 O(log C[i])
>- bitset操作：每次 `dp |= dp << val` 是 O(m/word_size)
>- 总复杂度：O(n × log(max(C)) × m/word_size)
>- 其中 word_size 通常是32或64（位运算并行度）
>
>### 7. **优点**
>1. **高效**：位运算并行处理多个状态
>2. **简洁**：代码量少
>3. **常数小**：比传统DP快很多
>
>### 8. **潜在问题**
>1. **bitset大小固定**：如果m>100000会越界
>2. **整数溢出**：`A[i] * k` 可能溢出（但题目中通常不会）
>3. **硬币面值0**：如果A[i]=0，左移0位无意义
>
这种方法是解决硬币组合问题的非常高效的技巧，特别适合只需要判断可达性的情况。

![alt text](image-153.png)