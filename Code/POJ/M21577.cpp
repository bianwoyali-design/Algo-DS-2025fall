#include <iostream>
#include <vector>
#include <stack>
using namespace std;

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
    
    vector<int> height(m + 1, 0);
    int ans = 0;
    for (const auto &i : arr)
    {
        for (int j = 0; j < m; j++)
            if (i[j] == 0)
                height[j]++;
            else
                height[j] = 0;
        
        stack<int> st;
        st.push(-1);
        for (int j = 0; j <= m; j++)
        {
            while (st.top() != -1 && height[st.top()] > height[j])
            {
                int top = st.top();
                st.pop();
                ans = max(ans, height[top] * (j - st.top() - 1));
            }
            st.push(j);
        }
    }

    cout << ans << '\n';
    return 0;
}