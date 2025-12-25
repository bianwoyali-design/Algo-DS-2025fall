# Assignment #A: 递归、田忌赛马

Updated 2355 GMT+8 Nov 4, 2025

2025 fall, Complied by <mark>同学的姓名、院系</mark>



>**说明：**
>
>1. **解题与记录：**
>
>  对于每一个题目，请提供其解题思路（可选），并附上使用Python或C++编写的源代码（确保已在OpenJudge， Codeforces，LeetCode等平台上获得Accepted）。请将这些信息连同显示“Accepted”的截图一起填写到下方的作业模板中。（推荐使用Typora https://typoraio.cn 进行编辑，当然你也可以选择Word。）无论题目是否已通过，请标明每个题目大致花费的时间。
>
>2. 提交安排：**提交时，请首先上传PDF格式的文件，并将.md或.doc格式的文件作为附件上传至右侧的“作业评论”区。确保你的Canvas账户有一个清晰可见的本人头像，提交的文件为PDF格式，并且“作业评论”区包含上传的.md或.doc附件。
> 
>4. **延迟提交：**如果你预计无法在截止日期前提交作业，请提前告知具体原因。这有助于我们了解情况并可能为你提供适当的延期或其他帮助。  
>
>请按照上述指导认真准备和提交作业，以保证顺利完成课程要求。





## 1. 题目

### M018160: 最大连通域面积

dfs similar, http://cs101.openjudge.cn/pctbook/M18160

思路：



代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int xy[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};

int dfs(int x, int y, vector<string>& m, int cnt)
{
    m[x][y] = '.';
    for (int i = 0; i < 8; i++)
    {
        int newX = x + xy[i][0];
        int newY = y + xy[i][1];
        if (newX >= 0 && newX < m.size() && newY >= 0 && newY < m[0].size() && m[newX][newY] == 'W')
            cnt = dfs(newX, newY, m, cnt + 1);
    }
    return cnt;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n, m;
        cin >> n >> m;
        vector<string> matrix(n);
        for (int i = 0; i < n; i++)
            cin >> matrix[i];
        
        int maxN = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (matrix[i][j] == 'W')
                    maxN = max(maxN, dfs(i, j, matrix, 1));
        cout << maxN << '\n';
    }
    return 0;
}
```

>共用时20min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>
![alt text](image-120.png)




### sy134: 全排列III 中等

https://sunnywhy.com/sfbj/4/3/134

思路：



代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int n;

void do_permutations(vector<vector<int>>& p, vector<int> nums, vector<int> tmp)
{
    if (tmp.size() == n)
    {
        p.push_back(tmp);
        return;
    }
    for (int i = 1; i <= 100; i++)
        if (nums[i])
        {
            nums[i]--;
            tmp.push_back(i);
            do_permutations(p, nums, tmp);
            tmp.pop_back();
            nums[i]++;
        }
}

vector<vector<int>> permute(vector<int>& nums)
{
    vector<vector<int>> permutations;
    vector<int> tmp;
    do_permutations(permutations, nums, tmp);
    return permutations;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;
    vector<int> nums(101, 0);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        cin >> ipt;
        nums[ipt]++;
    }
    vector<vector<int>> ans = permute(nums);
    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < n; j++)
            j == n - 1 ? cout << ans[i][j] << '\n' : cout << ans[i][j] << ' ';
    return 0;
}
```

>共用时20min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-121.png)



### sy136: 组合II 中等

https://sunnywhy.com/sfbj/4/3/136

给定一个长度为的序列，其中有n个互不相同的正整数，再给定一个正整数k，求从序列中任选k个的所有可能结果。

思路：
研究了一下cpp怎么写内置函数。


代码

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
        cin >> nums[i];
    
    vector<vector<int>> ans;
    vector<int> tmp;
    auto dfs = [&](auto&& dfs, int idx) -> void //C++ 11以后lambda表达式的新写法，用[&]捕获外部变量， auto&& dfs让lambda可以调用自己，返回值为void
    {
        if (tmp.size() == k)
        {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < n; i++)
        {
            tmp.push_back(nums[i]);
            dfs(dfs, i + 1);
            tmp.pop_back();
        }
    };

    dfs(dfs, 0);//注意要在参数中传递dfs()，不然无法递归

    for (int i = 0; i < ans.size(); i++)
        for (int j = 0; j < k; j++)
            j == k - 1 ? cout << ans[i][j] << '\n' : cout << ans[i][j] << ' ';
    return 0;
}
```

>共用时45min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-122.png)



### sy137: 组合III 中等

https://sunnywhy.com/sfbj/4/3/137


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

    int n, k;
    cin >> n >> k;
    vector<int> nums(101, 0);
    for (int i = 0; i < n; i++)
    {
        int ipt;
        cin >> ipt;
        nums[ipt]++;
    }

    vector<vector<int>> combination;
    vector<int> tmp;
    auto dfs = [&](auto&& dfs, int idx) -> void
    {
        if (tmp.size() == k)
        {
            combination.push_back(tmp);
            return;
        }
        for (int i = idx; i <= 100; i++)
        {
            if (nums[i])
            {
                tmp.push_back(i);
                nums[i]--;
                if (nums[i])
                    dfs(dfs, i);
                else
                    dfs(dfs, i + 1);
                nums[i]++;
                tmp.pop_back();
            }
        }
    };

    dfs(dfs, 1);

    for (auto i : combination)
        for (int j = 0; j < i.size(); j++)
            j != k - 1 ? cout << i[j] << ' ' : cout << i[j] << '\n';
    return 0;
}
```

>共用时20min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-123.png)



### M04123: 马走日

dfs, http://cs101.openjudge.cn/pctbook/M04123

思路：只能dfs暴力，记忆化dp只适用于```n * m < 20```的情况:(



代码

```cpp
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    int xy[8][2] = {{2, 1}, {2, -1}, {-2, 1}, {-2, -1}, {1, 2}, {1, -2}, {-1, 2}, {-1, -2}};
    cin >> T;
    while (T--)
    {
        int n, m, x, y;
        cin >> n >> m >> x >> y;

        int cnt = 0;
        vector<vector<bool>> valid(n, vector<bool>(m, false));
        auto dfs = [&](auto &&dfs, int desX, int desY, int step) -> void
        {
            if (step == n * m)
            {
                cnt++;
                return;
            }
            valid[desX][desY] = true;
            for (int i = 0; i < 8; i++)
            {
                int newX = desX + xy[i][0];
                int newY = desY + xy[i][1];
                if (newX >= 0 && newX < n && newY >= 0 && newY < m && !valid[newX][newY])
                    dfs(dfs, newX, newY, step + 1);
            }
            valid[desX][desY] = false;
        };

        dfs(dfs, x, y, 1);

        cout << cnt << '\n';
    }
    return 0;
}
```

>共用时40min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>


![alt text](image-124.png)


### T02287: Tian Ji -- The Horse Racing

greedy, dfs http://cs101.openjudge.cn/pctbook/T02287

思路：



代码

```CPP
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    while (cin >> n && n)
    {
        vector<int> a(n), b(n);
        for (int i = 0; i < n; i++)
            cin >> a[i];
        for (int i = 0; i < n; i++)
            cin >> b[i];
        
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());

        int score = 0;
        int mina = 0, minb = 0, maxa = a.size() - 1, maxb = b.size() - 1;
        while (n--)
        {
            if (a[maxa] > b[maxb])
            {
                score++;
                maxa--;
                maxb--;
            }
            else if (a[maxa] < b[maxb])
            {
                score--;
                mina++;
                maxb--;
            }
            else if (a[mina] > b[minb])
            {
                score++;
                mina++;
                minb++;
            }
            else
            {
                if (a[mina] < b[maxb])
                    score--;
                mina++;
                maxb--;
            }
        }

        cout << score * 200 << '\n';
    }
    return 0;
}
```

>共用时2h

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-125.png)



## 2. 学习总结和收获

<mark>如果作业题目简单，有否额外练习题目，比如：OJ“计概2025fall每日选做”、CF、LeetCode、洛谷等网站题目。</mark>

### sy578
```cpp
#include <iostream>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    string s;
    cin >> n >> k >> s;

    int l = 0, r = -1, cnt = 0;
    int maxLen = 0;
    while (r < n)
    {
        if (cnt <= k)
        {
            maxLen = max(maxLen, r - l + 1);
            r++;
            if (r < n && s[r] == '0')
                cnt++;
        }
        else
        {
            if (s[l] == '0')
                cnt--;
            l++;
        }
    }

    cout << maxLen << '\n';
    return 0;
}
```
![alt text](image-126.png)

### E19943
```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;
    cin >> n >> m;
    vector<vector<int>> L(n, vector<int>(n, 0));
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        L[a][a]++;
        L[b][b]++;
        L[a][b]--;
        L[b][a]--;
    }

    for (auto i : L)
    {
        for (auto j : i)
            cout << j << ' ';
        cout << '\n';
    }
    return 0;
}
```
![alt text](image-127.png)

### 1520D
```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        unordered_map<int, long long> diff;
        for (int i = 1; i <= n; i++)
        {
            int a;
            cin >> a;
            diff[a - i]++;
        }

        long long ans = 0;
        for (auto i : diff)
            if (i.second >= 2)
                ans += (i.second * (i.second - 1) / 2);

        cout << ans << '\n';
    }
    return 0;
}
```
![alt text](image-128.png)

### M02692
```cpp
#include <iostream>
#include <string>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    while (n--)
    {
        string l[3], r[3], stat[3];
        for (int i = 0; i < 3; i++)
            cin >> l[i] >> r[i] >> stat[i];

        for (char c = 'A'; c <= 'L'; ++c)
            for (int fakeType = 0; fakeType < 2; fakeType++)
            {
                bool ok = true;
                for (int i = 0; i < 3; ++i)
                {
                    int left = 0, right = 0;
                    for (char x : l[i])
                        if (x == c)
                            left += (fakeType ? 1 : -1);
                    for (char x : r[i])
                        if (x == c)
                            right += (fakeType ? 1 : -1);
                    if (stat[i] == "even" && left != right)
                        ok = false;
                    if (stat[i] == "up" && left <= right)
                        ok = false;
                    if (stat[i] == "down" && left >= right)
                        ok = false;
                }
                if (ok)
                {
                    cout << c << " is the counterfeit coin and it is " << (fakeType ? "heavy." : "light.") << '\n';
                    goto next_case;
                }
            }
    next_case:;
    }
    return 0;
}
```

![alt text](image-129.png)

### M04100
```cpp
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node
{
    int s, d;
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int k;
    cin >> k;
    while (k--)
    {
        int n;
        cin >> n;
        vector<Node> p(n);
        for (int i = 0; i < n; i++)
            cin >> p[i].s >> p[i].d;

        int testCounter = 0;
        sort(p.begin(), p.end(), [](Node &a, Node &b) -> bool
             { return a.s < b.s; });
        int it = 0;
        while (it < n)
        {
            int j = it;
            int maxs = p[it].s, mind = p[it].d;
            while (j < n && p[j].s >= maxs && p[j].s <= mind)
            {
                maxs = max(maxs, p[j].s);
                mind = min(mind, p[j].d);
                j++;
            }
            it = j;
            testCounter++;
        }

        cout << testCounter << '\n';
    }
    return 0;
}
```
![alt text](image-130.png)