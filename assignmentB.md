# Assignment #B: dp

Updated 1448 GMT+8 Nov 18, 2025

2025 fall, Complied by <mark>张真铭 元培学院</mark>



**说明：**

1）请把每个题目解题思路（可选），源码Python, 或者C++（已经在Codeforces/Openjudge上AC），截图（包含Accepted），填写到下面作业模版中（推荐使用 typora https://typoraio.cn ，或者用word）。AC 或者没有AC，都请标上每个题目大致花费时间。

2）提交时候先提交pdf文件，再把md或者doc文件上传到右侧“作业评论”。Canvas需要有同学清晰头像、提交文件有pdf、"作业评论"区有上传的md或者doc附件。

3）如果不能在截止前提交作业，请写明原因。



## 1. 题目

### LuoguP1255 数楼梯

dp, bfs, https://www.luogu.com.cn/problem/P1255

思路：
有两种状态：1.走一级到达当前台阶；2.走两级到达当前台阶。
由此给出状态转移方程```dp[i] = d[i - 1] + dp[i - 2]```;要用高精度不然会爆。

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

    vector<string> dp(n + 1);
    auto hp = [&](string a, string b) -> string
    {
        int maxLen = max(a.length(), b.length());
        a = string(maxLen - a.length(), '0') + a;
        b = string(maxLen - b.length(), '0') + b;
        string result(maxLen, '0');
        int carry = 0;
        for (int i = maxLen - 1; i >= 0; i--)
        {
            int sum = (a[i] - '0') + (b[i] - '0') + carry;
            carry = sum / 10;
            result[i] = (sum % 10) + '0';
        }
        if (carry > 0)
            result = "1" + result;
        result.erase(0, result.find_first_not_of('0'));
        if (result.empty())
            result = "0";
        return result;
    };
    dp[1] = "1",dp[2] = "2";
    for (int i = 3; i <= n; i++)
        dp[i] = hp(dp[i - 1], dp[i - 2]);

    cout << dp[n] << '\n';
    return 0;
}
```

>共用时20min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-131.png)



### 27528: 跳台阶

dp, http://cs101.openjudge.cn/practice/27528/

思路：

有n种状态，类似上一题

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
    vector<int> dp(n + 1, 0);
    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= i; j++)
            dp[i] += dp[i - j];
    cout << dp[n] << '\n';
    return 0;
}
```

>共用时10min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-132.png)



### M23421:《算法图解》小偷背包问题

dp, http://cs101.openjudge.cn/pctbook/M23421/

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

    int n, b;
    cin >> n >> b;

    vector<vector<int>> dp(n + 1, vector<int>(b + 1, 0));
    vector<int> v(n + 1), w(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> v[i];
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    for (int i = 1 ; i <= n; i++)
        for (int j = 1; j <= b; j++)
            if (w[i] <= j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - w[i]] + v[i]);
            else
                dp[i][j] = dp[i - 1][j];
    
    cout << dp[n][b] << '\n';
    return 0;
}
```

>共用时45min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-133.png)



### M5.最长回文子串

dp, two pointers, string, https://leetcode.cn/problems/longest-palindromic-substring/

思路：



代码：

```cpp
#include <iostream>
#include <vector>
using namespace std;

string longestPalindrome(string s)
{
    int n = s.size();
    if (n < 2)
        return s;
    
    vector<vector<bool>> dp(n, vector<bool>(n, 0));
    for (int i = 0; i < n; i++)
        dp[i][i] = true;
    int maxLen = 1, begin = 0;
    for (int L = 2; L <= n; L++)
        for (int i = 0; i < n; i++)
        {
            int j = i + L - 1;
            if (j >= n)
                break;
            dp[i][j] = j - i < 3 && s[i] == s[j] || dp[i + 1][j - 1] && s[i] == s[j];
            if (dp[i][j] && L > maxLen)
            {
                begin = i;
                maxLen = L;
            }
        }
    return s.substr(begin, maxLen);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;
    cout << longestPalindrome(s) << '\n';
    return 0;
}
```

>共用时30min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-134.png)





### 474D. Flowers

dp, 1700 https://codeforces.com/problemset/problem/474/D

思路：
有两种吃法：1.吃一个R，2.吃k个W，因此递推式为```dp[i] = d[i - 1] + dp[i - k]```
用前缀和压缩时间

代码：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t, k;
    cin >> t >> k;
    int minn = 1e9, maxn = 0;
    vector<int> a(t);
    vector<int> b(t);
    for (int i = 0; i < t; i++)
    {
        cin >> a[i] >> b[i];
        minn = min(minn, a[i]);
        maxn = max(maxn, b[i]);
    }

    vector<int> dp(maxn + 1);
    for (int i = 0; i < k; i++)
        dp[i] = 1;
    for (int i = k; i <= maxn; i++)
        dp[i] = (dp[i - 1] + dp[i - k]) % int(1e9 + 7);

    vector<int> pre(maxn + 1, 0);
    for (int i = 1; i <= maxn; i++)
        pre[i] = (pre[i - 1] + dp[i]) % int(1e9 + 7);
        
    for (int i = 0; i < t; i++)
        cout << (pre[b[i]] - pre[a[i] - 1] + int(1e9 + 7)) % int(1e9 + 7) << '\n';

    return 0;
}
```

>共用时1h

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-135.png)



### M198.打家劫舍

dp, https://leetcode.cn/problems/house-robber/

思路：两种状态：1.偷第i家，总金额为```dp[i - 2] + nums[i]```，2.不偷第i家，总金额为```dp[i - 1]```，取两者的最大值



代码：

```cpp
#include <iostream>
#include <vector>
using namespace std;

int rob(vector<int>& nums)
{
    int n = nums.size();
    if (n < 2)
        return nums[0];
    if (n == 2)
        return max(nums[0], nums[1]);
    
    vector<int> dp(n);
    dp[0] = nums[0], dp[1] = max(nums[0], nums[1]);

    int maxVal = 0;
    for (int i = 2; i < n; i++)
    {
        dp[i] = max(dp[i - 2] + nums[i], dp[i - 1]);
        maxVal = max(maxVal, dp[i]);
    }

    return maxVal;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<int> nums = {2, 7, 9 ,3, 1};
    cout << rob(nums) << '\n';

    return 0;
}
```

>共用时30min

代码运行截图 <mark>（至少包含有"Accepted"）</mark>

![alt text](image-136.png)



## 2. 学习总结和收获

<mark>如果作业题目简单，有否额外练习题目，比如：OJ“计概2024fall每日选做”、CF、LeetCode、洛谷等网站题目。</mark>

### LC 208
```cpp
#include <iostream>
#include <vector>
using namespace std;

class Trie
{
private:
    vector<Trie*> children;
    bool isLeaf;

    Trie* searchPrefix(string prefix)
    {
        Trie* node = this;
        for (auto c : prefix)
        {
            if (node->children[c - 'a'] == nullptr)
                return nullptr;
            node = node->children[c - 'a'];
        }
        return node;
    }

public:
    Trie() : children(26), isLeaf(false) {}

    auto insert(string word)
    {
        Trie* node = this;
        for (auto c : word)
        {
            if (node->children[c - 'a'] == nullptr)
                node->children[c - 'a'] = new Trie();
            node = node->children[c - 'a'];
        }
        node->isLeaf = true;
    }

    auto search(string word)
    {
        return this->searchPrefix(word) != nullptr && this->searchPrefix(word)->isLeaf;
    }

    auto startsWith(string prefix)
    {
        return this->searchPrefix(prefix) != nullptr;
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Trie* trie = new Trie();
    trie->insert("apple");
    cout << trie->search("apple") << '\n';
    cout << trie->search("app") << '\n';
    cout << trie->startsWith("app") << '\n';
    trie->insert("app");
    cout << trie->search("app") << '\n';

    return 0;
}
```

![alt text](image-137.png)


### 04089
```cpp
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Trie
{
private:
    vector<Trie *> children;
    bool isLeaf;

public:
    Trie() : children(10), isLeaf(false) {}

    auto insert_and_check(string word)
    {
        Trie *node = this;
        for (auto c : word)
        {
            c -= '0';
            if (node->isLeaf)
                return false;
            if (node->children[c] == nullptr)
                node->children[c] = new Trie();
            node = node->children[c];
        }
        if (node->isLeaf)
            return false;
        for (int i = 0; i < 10; i++)
            if (node->children[i] != nullptr)
                return false;
        node->isLeaf = true;
        return true;
    }
};

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
        bool check = false;
        vector<string> phone_num(n);
        for (int i = 0; i < n; i++)
            cin >> phone_num[i];

        sort(phone_num.begin(), phone_num.end());
        Trie *trie = new Trie();
        for (auto s : phone_num)
            if (!trie->insert_and_check(s))
            {
                cout << "NO\n";
                goto next;
            }
        cout << "YES\n";
    next:;
    }

    return 0;
}
```

![alt text](image-138.png)
