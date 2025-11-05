#include <iostream>
#include <stack>
using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if (i == '(' || i == '[' || i == '{')
            st.push(i);
        else
            if (!st.empty() && i == ')' && st.top() == '(')
                st.pop();
            else if (!st.empty() && i == ']' && st.top() == '[')
                st.pop();
            else if (!st.empty() && i == '}' && st.top() == '{')
                st.pop();
            else
                return false;
    }
    if (st.empty())
        return true;
    else
        return false;
}

int main()
{
    string s;
    cin >> s;
    cout << isValid(s) << '\n';
    return 0;
}