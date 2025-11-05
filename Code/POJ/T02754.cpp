#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

bool is_valid(string& queen, int x, int y)
{
    for (int i = 1; i < x; i++)
        if (int(queen[i] - '0') == y || abs(i - x) == abs(int(queen[i] - '0') - y))
            return false;
    return true;
}

void sovle_8_queens(vector<string>& sol, string& queen, int n)
{
    if (n == 9)
        sol.push_back(queen);
    else
        for (int i = 1; i <= 8; i++)
            if (is_valid(queen, n, i))
            {
                queen[n] = i + '0';
                sovle_8_queens(sol, queen, n + 1);
                queen[n] = '0';
            }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<string> solutions;
    string queen = "000000000";
    sovle_8_queens(solutions, queen, 1);
    vector<int> sol;
    for (auto i : solutions)
        sol.push_back(stoi(i));
    sort(sol.begin(), sol.end());

    while (n--)
    {
        int k;
        cin >> k;
        cout << sol[k - 1] << '\n';
    }
    return 0;
}