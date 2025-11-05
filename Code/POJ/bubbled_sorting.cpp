#include <iostream>
#include <set>    // 包含set头文件
using namespace std;

int main()
{
    int n;
    cin >> n;
    if (n <= 0) return 0;

    // multiset 会自动按从小到大排序，允许重复元素
    multiset<int> nums;
    
    // 读取输入并自动排序
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        nums.insert(x);  // 插入时自动排序
    }
    
    // 输出已排序的结果
    for (const auto& num : nums) {
        cout << num << endl;
    }
    
    return 0;
}