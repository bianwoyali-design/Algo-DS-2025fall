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