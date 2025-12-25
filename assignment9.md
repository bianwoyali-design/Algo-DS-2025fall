# Assignment #9: Mock Exam立冬前一天

Updated 1658 GMT+8 Nov 6, 2025

2025 fall, Complied by <mark>张真铭 元培学院</mark>



>**说明：**
>
>1. Nov⽉考： AC4<mark>（请改为同学的通过数）</mark> 。考试题⽬都在“题库（包括计概、数算题目）”⾥⾯，按照数字题号能找到，可以重新提交。作业中提交⾃⼰最满意版本的代码和截图。
>
>2. 解题与记录：对于每一个题目，请提供其解题思路（可选），并附上使用Python或C++编写的源代码（确保已在OpenJudge， Codeforces，LeetCode等平台上获得Accepted）。请将这些信息连同显示“Accepted”的截图一起填写到下方的作业模板中。（推荐使用Typora https://typoraio.cn 进行编辑，当然你也可以选择Word。）无论题目是否已通过，请标明每个题目大致花费的时间。
>
>3. 提交安排：提交时，请首先上传PDF格式的文件，并将.md或.doc格式的文件作为附件上传至右侧的“作业评论”区。确保你的Canvas账户有一个清晰可见的本人头像，提交的文件为PDF格式，并且“作业评论”区包含上传的.md或.doc附件。
> 
>4. 延迟提交：如果你预计无法在截止日期前提交作业，请提前告知具体原因。这有助于我们了解情况并可能为你提供适当的延期或其他帮助。  
>
>请按照上述指导认真准备和提交作业，以保证顺利完成课程要求。





## 1. 题目

### E29982:一种等价类划分问题

hashing, http://cs101.openjudge.cn/practice/29982

思路：



代码

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, n, k;
    char ch;
    cin >> m >> ch >> n >> ch >> k;

    vector<vector<int>> hash(100);
    int maxK = 0;
    for (int i = m + 1; i < n; i++)
    {
        int tmp = i, sum = 0;
        while (tmp)
        {
            sum += tmp % 10;
            tmp /= 10;
        }
        if (sum % k == 0)
        {
            hash[sum].push_back(i);
            maxK = max(maxK, sum);
        }
    }
    for (int i = 0; i <= maxK; i++)
    {
        if (!hash[i].empty())
        {
            for (int j = 0; j < hash[i].size(); j++)
            {
                if (j) cout << ',';
                cout << hash[i][j];
            }
            cout << '\n';
        }
    }
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-109.png)



### E30086:dance

greedy, http://cs101.openjudge.cn/practice/30086

思路：



代码

```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, d;
    cin >> n >> d;
    vector<int> a(2 * n);
    for (int i = 0; i < 2 * n; i++)
        cin >> a[i];
    sort(a.begin(), a.end());
    for (int i = 0; i < 2 * n - 1; i++)
        if (a[i + 1] - a[i] > d)
        {
            cout << "No";
            return 0;
        }
    cout << "Yes";
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-108.png)



### M25570: 洋葱

matrices, http://cs101.openjudge.cn/practice/25570

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

    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(n));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
    int maxSum = 0;
    for (int i = 0; i <= (n - 1) / 2; i++)
    {
        int start = i, end = n - 1 - i;
        int sum = 0;
        if (start == end)
            sum = a[i][i];
        else
        {
            for (int j = start; j <= end; j++)
                sum += a[start][j] + a[j][start] + a[j][end] + a[end][j];
            sum = sum - a[start][start] - a[end][end] - a[start][end] - a[end][start];
        }
        maxSum = max(maxSum, sum);
    }
    cout << maxSum << '\n';
    return 0;
}

```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-110.png)



### M28906:数的划分

dfs, dp, http://cs101.openjudge.cn/practice/28906


思路：



代码

```cpp
#include <iostream>
using namespace std;

int dp[201][7];
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, k;
    cin >> n >> k;
    dp[1][1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= k; j++)
        {
            if (i < j)
                dp[i][j] = 0;
            else if (i == j)
                dp[i][j] = 1;
            else
                dp[i][j] = dp[i - 1][j - 1] + dp[i - j][j];
        }
    cout << dp[n][k];
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-111.png)



### M29896:购物

greedy, http://cs101.openjudge.cn/practice/29896

思路：



代码

```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, n;
    cin >> x >> n;
    vector<int> val;
    for (int i = 0; i < n; i++)
    {
        int ipt;
        if (cin >> ipt && ipt <= x)
            val.push_back(ipt);
    }

    sort(val.begin(), val.end());
    if (val.empty() || val[0] != 1)
    {
        cout << -1 << '\n';
        return 0;
    }

    int reach = 0, ans = 0, idx = 0;
    while (reach < x)
    {
        while (idx < val.size() && val[idx] <= reach + 1)
            idx++;
        int coin = val[idx - 1];
        int add = (idx < val.size() ? val[idx] - 1 : x) - reach;
        int cnt = (add + coin - 1) / coin;
        reach += cnt * coin;
        ans += cnt;
    }
    cout << ans << '\n';
    return 0;
}
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-112.png)



### T25353:排队

greedy, http://cs101.openjudge.cn/practice/25353

思路：



代码

```cpp
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
```



代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-113.png)



## 2. 学习总结和收获

如果作业题目简单，有否额外练习题目，比如：OJ“计概2025fall每日选做”、CF、LeetCode、洛谷等网站题目。

### sy360
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Node
{
    int parent;
    int size;
};

vector<Node> self;

void _init(int n)
{
    self = vector<Node>(n);
    for (int i = 0; i < n; i++)
    {
        self[i].parent = i;
        self[i].size = 1;
    }
}

int _find(int i)
{
    if (self[i].parent != i)
        self[i].parent = _find(self[i].parent);
    return self[i].parent;
}

void _union(int i, int j)
{
    int irep = _find(i);
    int jrep = _find(j);
    if (irep == jrep)
        return;
    if (self[irep].size < self[jrep].size)
    {
        self[irep].parent = jrep;
        self[jrep].size += self[irep].size;
    }
    else
    {
        self[jrep].parent = irep;
        self[irep].size += self[jrep].size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    _init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    set<int> cnt;
    for (int i = 0; i < n; i++)
        cnt.insert(_find(i));
    cout << cnt.size() << '\n';
    return 0;
}
```
![alt text](image-114.png)
### sy361
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

struct Node
{
    int parent;
    int size;
};

vector<Node> self;

void _init(int n)
{
    self = vector<Node>(n);
    for (int i = 0; i < n; i++)
    {
        self[i].parent = i;
        self[i].size = 1;
    }
}

int _find(int i)
{
    if (self[i].parent != i)
        self[i].parent = _find(self[i].parent);
    return self[i].parent;
}

void _union(int i, int j)
{
    int irep = _find(i);
    int jrep = _find(j);
    if (irep == jrep)
        return;
    if (self[irep].size < self[jrep].size)
    {
        self[irep].parent = jrep;
        self[jrep].size += self[irep].size;
    }
    else
    {
        self[jrep].parent = irep;
        self[irep].size += self[jrep].size;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n, m;
    cin >> n >> m;
    _init(n);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    set<int> cnt;
    for (int i = 0; i < n; i++)
        cnt.insert(_find(i));
    cout << cnt.size() << '\n';
    vector<int> size;
    for (auto i : cnt)
        size.push_back(self[i].size);
    sort(size.begin(), size.end(), greater<int>());
    for (int i = 0; i < size.size(); i++)
        i == size.size() - 1 ? cout << size[i] : cout << size[i] << ' ';
    return 0;
}
```
![alt text](image-116.png)
### sy362
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, _size;

void _init(int n)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    _size.assign(n, 1);
}

int _find(int i)
{
    return parent[i] != i ? parent[i] = _find(parent[i]) : parent[i];
}

void _union(int i, int j)
{
    int irep = _find(parent[i]);
    int jrep = _find(parent[j]);
    if (irep != jrep)
    {
        parent[irep] = jrep;
        _size[jrep] += _size[irep];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    _init(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }
    int k;
    cin >> k;
    while (k--)
    {
        int a, b;
        cin >> a >> b;
        if (_find(a - 1) == _find(b - 1))
            cout << "Yes\n";
        else
            cout << "No\n";
    }
    return 0;
}
```
![alt text](image-117.png)
### sy363
```cpp
#include <iostream>
#include <vector>
using namespace std;

vector<int> parent, _size;

void _init(int n)
{
    parent.resize(n);
    for (int i = 0; i < n; i++)
        parent[i] = i;
    _size.assign(n, 1);
}

int _find(int i)
{
    return parent[i] != i ? parent[i] = _find(parent[i]) : parent[i];
}

void _union(int i, int j)
{
    int irep = _find(parent[i]);
    int jrep = _find(parent[j]);
    if (irep != jrep)
    {
        parent[irep] = jrep;
        _size[jrep] += _size[irep];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    _init(n);
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    bool linked = true;
    for (int i = 1; i < n; i++) {
        if (_find(i) != _find(0)) {
            linked = false;
        }
    }
    printf(linked ? "Yes" : "No");
    return 0;
}
```
![alt text](image-118.png)
### sy364
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

vector<int> pa, sz;

void _init(int n)
{
    pa.resize(n);
    for (int i = 0; i < n; i++)
        pa[i] = i;
    sz.assign(n, 1);
}

int _find(int i)
{
    return pa[i] == i ? pa[i] : pa[i] = _find(pa[i]);
}

void _union(int i, int j)
{
    int irep = _find(pa[i]);
    int jrep = _find(pa[j]);
    if (irep != jrep)
    {
        pa[irep] = jrep;
        sz[jrep] += sz[irep];
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<int> sc(n);
    _init(n);
    for (int i = 0; i < n; i++)
    {
        int score;
        cin >> score;
        sc[i] = score;
    }
    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        _union(a - 1, b - 1);
    }

    set<int> cl;
    for (int i = 0; i < n; i++)
        cl.insert(_find(i));
    cout << cl.size() << '\n';
    vector<int> ans;
    for (auto i : cl)
    {
        int maxs = 0;   
        for (int j = 0; j < n; j++)
            if (_find(j) == i)
                maxs = max(maxs, sc[j]);
        ans.push_back(maxs);
    }
    sort(ans.begin(), ans.end(), greater<int>());
    for (int i = 0; i < ans.size(); i++)
        i == ans.size() - 1 ? cout << ans[i] : cout << ans[i] << ' ';
    return 0;
}
```
![alt text](image-119.png)


