#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main()
{
    cin.tie(nullptr)->sync_with_stdio(false);

    vector<string> str;
    string s;
    while (cin >> s)
        str.push_back(s);
    
    stack<double> st;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        if (str[i] == "+" || str[i] == "-" || str[i] == "*"  || str[i] == "/" )
        {
            double fir = st.top();
            st.pop();
            double sec = st.top();
            st.pop();
            if (str[i] == "+")
                st.push(fir + sec);
            if (str[i] == "-")
                st.push(fir - sec);
            if (str[i] == "*")
                st.push(fir * sec);
            if (str[i] == "/")
                st.push(fir / sec);
        }
        else
            st.push(stod(str[i]));
    }
    printf("%f\n", st.top());
    return 0;
}