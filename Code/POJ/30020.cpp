#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

int main() {
    // 禁用同步，加速I/O
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // a: 披萨(5x5), b: 牛排(3x4), c: 意面(2x3), d: 鸡翅(1x2), e: 可乐(1x1)
    long long a, b, c, d, e;
    cin >> a >> b >> c >> d >> e;

    long long ans = 0;

    // --- 1. 放置披萨 (5x5) ---
    // 每个披萨占用一个箱子 (5x5=25格，剩余11格)
    ans += a;
    
    // 假设每个装披萨的箱子可以填充 5个鸡翅 (1x2=10格) 和 1个可乐 (1x1=1格)
    // 注意：这里需要检查物品数量是否足够，如果不足，则减少消耗。

    long long used_d_by_a = min(a * 5, d); // 披萨箱子消耗的鸡翅
    d -= used_d_by_a;

    long long remaining_spaces_after_d = a * 11 - used_d_by_a * 2; // 披萨箱子剩余的空间格子数
    long long used_e_by_a = min(remaining_spaces_after_d, e); // 披萨箱子消耗的可乐
    e -= used_e_by_a;

    // --- 2. 放置牛排 (3x4) ---
    // 尽可能 2个牛排 (3x4) + 2个意面 (2x3) 填满一个箱子 (24+12=36)

    long long num_boxes_for_b_pair = b / 2; // 成对牛排箱子数
    ans += num_boxes_for_b_pair;
    c -= num_boxes_for_b_pair * 2; // 消耗意面

    long long remaining_b = b % 2;

    if (remaining_b == 1) {
        // 1个牛排 (3x4) + 4个意面 (2x3) 填满一个箱子 (12+24=36)
        ans++;
        c -= 4; // 消耗意面
    }
    
    // 如果意面数量不足 (c < 0)，则需用鸡翅和可乐填充意面本应占据的空间
    if (c < 0) {
        long long required_space = -c * 6; // 意面不足导致的所需填充格子数
        c = 0;

        long long used_d_by_c = min(required_space / 2, d);
        d -= used_d_by_c;
        required_space -= used_d_by_c * 2;

        long long used_e_by_c = min(required_space, e);
        e -= used_e_by_c;
    }


    // --- 3. 放置意面 (2x3) ---
    // 尽可能 6个意面 (2x3) 填满一个箱子 (6*6=36)

    if (c > 0) {
        long long num_boxes_for_c_full = c / 6;
        ans += num_boxes_for_c_full;
        long long remaining_c = c % 6;

        if (remaining_c > 0) {
            ans++; // 最后一个意面箱子
            long long required_space = 36 - remaining_c * 6; // 剩余空间格子数
            
            // 用鸡翅和可乐填充剩余空间
            long long used_d_by_c_rem = min(required_space / 2, d);
            d -= used_d_by_c_rem;
            required_space -= used_d_by_c_rem * 2;

            long long used_e_by_c_rem = min(required_space, e);
            e -= used_e_by_c_rem;
        }
    }


    // --- 4. 放置鸡翅 (1x2) ---
    // 尽可能 18个鸡翅 (1x2) 填满一个箱子 (18*2=36)

    if (d > 0) {
        long long num_boxes_for_d_full = d / 18;
        ans += num_boxes_for_d_full;
        long long remaining_d = d % 18;

        if (remaining_d > 0) {
            ans++; // 最后一个鸡翅箱子
            long long required_space = 36 - remaining_d * 2; // 剩余空间格子数
            
            // 用可乐填充剩余空间
            long long used_e_by_d_rem = min(required_space, e);
            e -= used_e_by_d_rem;
        }
    }


    // --- 5. 放置可乐 (1x1) ---
    // 36个可乐填满一个箱子

    if (e > 0) {
        ans += (e + 35) / 36; // 向上取整
    }

    cout << ans << '\n';
    return 0;
}