#include <iostream>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    cin >> s;

    stack<int> st;
    int maxLen = 0;
    st.push(-1);
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(')
            st.push(i);
        else
        {
            st.pop();
            if (st.empty())
                st.push(i);
            else
                maxLen = max(maxLen, i - st.top());
        }
    }

    cout << maxLen << '\n';
    return 0;
}