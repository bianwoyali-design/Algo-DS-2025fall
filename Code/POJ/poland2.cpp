#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
struct pol
{
    double num;
    char exe;
    bool is_num;
};
vector<pol> p;
void init()
{
    string tmp;
    while (cin >> tmp)
    {
        if (tmp == "+" || tmp == "-" || tmp == "*" || tmp == "/")
        {
            p.push_back({0, tmp[0], false});
        }
        else
        {
            p.push_back({stod(tmp), 0, true});
        }
    }
}
double solve(int st, int ed)
{
    if (st == ed)
        return p[st].num;
    char exe = p[st].exe;
    int cnt_exe = 0;
    int cnt_num = 0;
    int mid;
    for (int i = st + 1; i <= ed; i++)
    {
        if (p[i].is_num)
            cnt_num++;
        else
            cnt_exe++;
        if (cnt_exe == cnt_num - 1)
        {
            mid = i;
            break;
        }
    }
    double fir = solve(st + 1, mid);
    double sec = solve(mid + 1, ed);
    switch (exe)
    {
    case '+':
        return fir + sec;
    case '-':
        return fir - sec;
    case '*':
        return fir * sec;
    case '/':
        return fir / sec;
    }
}
int main()
{
    init();
    printf("%f\n", solve(0, p.size() - 1));
    return 0;
}