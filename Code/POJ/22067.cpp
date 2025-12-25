#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string s;
    int n;
    stack<int> st;
    map<int, int> list;
    while (cin >> s)
    {
        if (s == "push")
        {
            cin >> n;
            st.push(n);
            list[n]++;
        }
        else if (s == "pop")
        {
            if (!st.empty())
            {
                list[st.top()]--;
                st.pop();
            }
        }
        else if (s == "min")
        {
            if (!st.empty())
            {
                for (const auto &m : list)
                    if (m.second != 0)
                    {
                        cout << m.first << '\n';
                        break;
                    }
            }
        }
    }
    return 0;
}