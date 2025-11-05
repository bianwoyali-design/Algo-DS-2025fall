#include <iostream>
#include <unordered_map>
using namespace std;

unordered_map<int, long long> memo;

int encode(int a, int b)
{
    return a * 10000  + b;
}

long long dfs(int stack, int queue)
{
    int key = encode(stack, queue);
    if (memo[key])
        return memo[key];
    if (queue == 0)
        return memo[key] = 1;
    if (stack == 0)
        return dfs(1, queue - 1);
    return memo[key] = dfs(stack - 1, queue) + dfs(stack + 1, queue - 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    cout << dfs(0, n) << '\n';
    return 0;
}