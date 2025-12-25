# Assignment #D: Mock Exam下元节

Updated 1729 GMT+8 Dec 4, 2025

2025 fall, Complied by <mark>张真铭 元培学院</mark>



>**说明：**
>
>1. Dec⽉考： AC6<mark>（请改为同学的通过数）</mark> 。考试题⽬都在“题库（包括计概、数算题目）”⾥⾯，按照数字题号能找到，可以重新提交。作业中提交⾃⼰最满意版本的代码和截图。
>
>2. 解题与记录：对于每一个题目，请提供其解题思路（可选），并附上使用Python或C++编写的源代码（确保已在OpenJudge， Codeforces，LeetCode等平台上获得Accepted）。请将这些信息连同显示“Accepted”的截图一起填写到下方的作业模板中。（推荐使用Typora https://typoraio.cn 进行编辑，当然你也可以选择Word。）无论题目是否已通过，请标明每个题目大致花费的时间。
>
>3. 提交安排：提交时，请首先上传PDF格式的文件，并将.md或.doc格式的文件作为附件上传至右侧的“作业评论”区。确保你的Canvas账户有一个清晰可见的本人头像，提交的文件为PDF格式，并且“作业评论”区包含上传的.md或.doc附件。
> 
>4. 延迟提交：如果你预计无法在截止日期前提交作业，请提前告知具体原因。这有助于我们了解情况并可能为你提供适当的延期或其他帮助。  
>
>请按照上述指导认真准备和提交作业，以保证顺利完成课程要求。





## 1. 题目

### E29945:神秘数字的宇宙旅行 

implementation, http://cs101.openjudge.cn/practice/29945

思路：



代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n;
    cin >> n;
    while (n > 1)
        if (n % 2 == 0)
        {
            int tmp = n;
            n /= 2;
            cout << tmp << '/' << 2 << '=' << n << '\n';
        }
        else
        {
            int tmp = n;
            n = n * 3 + 1;
            cout << tmp << '*' << 3 << '+' << 1 << '=' << n << '\n';
        }
    cout << "End\n";
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>


![alt text](image-154.png)


### E29946:删数问题

monotonic stack, greedy, http://cs101.openjudge.cn/practice/29946

思路：



代码

```cpp
#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string n;
    int k;
    cin >> n >> k;

    stack<char> st;
    for (auto c : n)
    {
        while (k && !st.empty() && st.top() > c)
        {
            st.pop();
            k--;
        }
        st.push(c);
    }
    while (k && !st.empty())
    {
        st.pop();
        k--;
    }

    string ans;
    while (!st.empty())
    {
        ans = st.top() + ans;
        st.pop();
    }
    while (ans[0] == '0')
        ans.erase(ans.begin());
    if (ans.empty())
        ans = '0';
    
    cout << ans;
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-155.png)



### E30091:缺德的图书馆管理员

greedy, http://cs101.openjudge.cn/practice/30091

思路：



代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int L, N;
    int maxN = 0;
    cin >> L >> N;
    if (N == 0)
    {
        cout << "0 0\n";
        return 0;
    }
    int maxt = 0, mint = 0;
    while (N--)
    {
        int pos;
        cin >> pos;
        mint = max(mint, min(pos, L + 1 - pos));
        maxt = max(maxt, max(pos, L + 1 - pos));
    }

    cout << mint << ' ' << maxt << '\n';
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>


![alt text](image-156.png)


### M27371:Playfair密码

simulation，string，matrix, http://cs101.openjudge.cn/practice/27371


思路：



代码

```cpp
#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string key;
    cin >> key;
    bool used[26] = {0};
    vector<vector<char>> arr(5, vector<char>(5));
    string table;
    for (char c : key) {
        if (c == 'j') c = 'i';
        if (!used[c - 'a']) {
            used[c - 'a'] = true;
            table += c;
        }
    }
    for (char c = 'a'; c <= 'z'; ++c) {
        if (c == 'j') continue;
        if (!used[c - 'a']) {
            used[c - 'a'] = true;
            table += c;
        }
    }
    for (int i = 0; i < 25; ++i)
        arr[i / 5][i % 5] = table[i];

    int n;
    cin >> n;
    while (n--) {
        string text;
        cin >> text;
        string prep;
        for (char c : text)
            prep += (c == 'j' ? 'i' : c);

        string res;
        for (int i = 0; i < prep.size(); ) {
            char a = prep[i], b;
            if (i + 1 == prep.size()) {
                b = (a == 'x' ? 'q' : 'x');
                ++i;
            } else if (a == prep[i + 1]) {
                b = (a == 'x' ? 'q' : 'x');
                ++i;
            } else {
                b = prep[i + 1];
                i += 2;
            }
            int ax, ay, bx, by;
            for (int x = 0; x < 5; ++x)
                for (int y = 0; y < 5; ++y) {
                    if (arr[x][y] == a) { ax = x; ay = y; }
                    if (arr[x][y] == b) { bx = x; by = y; }
                }
            if (ax == bx) {
                res += arr[ax][(ay + 1) % 5];
                res += arr[bx][(by + 1) % 5];
            } else if (ay == by) {
                res += arr[(ax + 1) % 5][ay];
                res += arr[(bx + 1) % 5][by];
            } else {
                res += arr[ax][by];
                res += arr[bx][ay];
            }
        }
        cout << res << '\n';
    }
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>


![alt text](image-157.png)


### T30201:旅行售货商问题

dp,dfs, http://cs101.openjudge.cn/practice/30201

思路：



代码

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<vector<int>> mat(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> mat[i][j];

    const int INF = 1e9;
    int N = 1 << n;
    vector<vector<int>> dp(N, vector<int>(n, INF));
    dp[1][0] = 0;

    for (int mask = 1; mask < N; mask++) {
        for (int u = 0; u < n; u++) {
            if (!(mask & (1 << u))) continue;
            for (int v = 0; v < n; v++) {
                if (mask & (1 << v)) continue;
                dp[mask | (1 << v)][v] = min(dp[mask | (1 << v)][v], dp[mask][u] + mat[u][v]);
            }
        }
    }

    int res = INF;
    for (int i = 1; i < n; i++)
        res = min(res, dp[N - 1][i] + mat[i][0]);
    cout << res << '\n';
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-158.png)



### T30204:小P的LLM推理加速

greedy, http://cs101.openjudge.cn/practice/30204

思路：
## 1. 题目概要
**题目编号**: 30204
**核心问题**: 在给定总能量预算 $m$ 的情况下，通过合理调度 $n$ 个异构计算核（具有冷启动能耗 $x_i$ 和热运行能耗 $y_i$），最大化总推理周期数。

## 2. 算法思路：贪心 + 数学推导

### 2.1 能耗模式分析
每个计算核 $i$ 的能耗遵循 $x_i, y_i, x_i, y_i \dots$ 的交替模式。
我们将一次 $x_i + y_i$ 视为一个完整的**循环单元**，其总能耗为 $S_i = x_i + y_i$。

为了效益最大化，只要我们决定进行“成对”的循环计算（即跑完 $x$ 紧接着跑 $y$），我们一定只选择**全局 $S_i$ 最小**的那个核心来承担所有的循环任务。记这个最小值为 $min\_S$。

### 2.2 任务拆分
任何一种调度方案，最终完成的总任务数 $K$ 都可以拆分为：
1.  **奇数部分**：有 $r$ 个核心，它们最终停留在“冷启动”状态（只跑了 $x$，或 $x, y, \dots, x$）。这些核心贡献了 $r$ 个任务。
2.  **偶数部分**：剩下的 $K - r$ 个任务。这部分任务一定是可以凑成 $(x, y)$ 对子的。为了省电，这部分全部用代价为 $min\_S$ 的核心来跑。

### 2.3 数学推导
假设我们选定了 $r$ 个特定的核心作为“奇数结尾”的核心，且总任务数为 $mid$。
总能耗限制公式为：
$$
\sum_{j \in Selected} x_j + \frac{mid - r}{2} \times min\_S \le m
$$

为了消除分母，两边同时乘以 2：
$$
2 \sum x_j + (mid - r) \times min\_S \le 2m
$$

展开并整理项：
$$
\sum (2x_j) - r \times min\_S + mid \times min\_S \le 2m
$$

$$
\sum (2x_j - min\_S) + mid \times min\_S \le 2m
$$

### 2.4 贪心策略
观察上述不等式，为了让 $mid$ 最大，我们需要让左边的求和项 $\sum (2x_j - min\_S)$ 尽可能小。

定义每个核心的**边际代价** $v_i = 2x_i - min\_S$。
1.  计算所有核心的 $v_i$ 并**从小到大排序**。
2.  枚举 $r$（从 $0$ 到 $n$），表示我们选择前 $r$ 个 $v_i$ 最小的核心作为奇数结尾。
3.  利用不等式反推当前 $r$ 下的最大 $mid$。

**注意奇偶性约束**：计算出的 $mid$ 必须满足 $(mid - r)$ 是非负偶数。如果不满足（即 $(mid - r)$ 是奇数），说明最后一个半周期无法凑整，必须将 $mid$ 减 1。



代码


```cpp
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

int main() {
    // 优化 I/O 效率
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    ll m;
    if (cin >> n >> m) {
        vector<ll> x(n), y(n);
        ll min_s = -1; // 记录全局最小的 (x + y)

        for (int i = 0; i < n; ++i) {
            cin >> x[i] >> y[i];
            ll s = x[i] + y[i];
            if (min_s == -1 || s < min_s) {
                min_s = s;
            }
        }

        // 计算价值 v[i] = 2*x[i] - min_s
        vector<ll> v(n);
        for (int i = 0; i < n; ++i) {
            v[i] = 2 * x[i] - min_s;
        }

        // 贪心：优先选择 v 值小的核心
        sort(v.begin(), v.end());

        ll max_tasks = 0;
        ll current_P = 0; // 前缀和：记录前 r 个 v[i] 的总和

        // 枚举 r：表示有 r 个核心处于“奇数任务”状态
        for (int r = 0; r <= n; ++r) {
            if (r > 0) {
                current_P += v[r - 1];
            }

            // 根据公式： mid * min_s <= 2*m - current_P
            ll rhs = 2 * m - current_P;

            // 预算不足以支撑这 r 个启动
            if (rhs < 0) break;

            // 计算理论最大任务数
            ll limit = rhs / min_s;

            // 约束1：总任务数 limit 必须 >= 奇数核心数 r
            if (limit < r) continue;

            // 约束2：奇偶性修正
            // limit - r 必须是偶数（因为剩下的是成对的）
            if ((limit - r) % 2 != 0) {
                limit--; 
            }

            if (limit >= r) {
                max_tasks = max(max_tasks, limit);
            }
        }

        cout << max_tasks << endl;
    }

    return 0;
}
```

Gemini辅助做的，我是真不会

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-159.png)



## 2. 学习总结和收获

如果作业题目简单，有否额外练习题目，比如：OJ“计概2025fall每日选做”、CF、LeetCode、洛谷等网站题目。





