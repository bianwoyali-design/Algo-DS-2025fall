#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int n, m;
    while(true)
    {
        cin >> n >> m;
        if (n == 0 && m == 0)
            break;
        queue<int> q;
        for (int i = 1; i <= n; i++)
            q.push(i);
        int flag = 1;
        while (q.size() > 1)
        {
            if (flag >= m)
            {
                q.pop();
                flag = 1;
            }
            else
            {
                int tmp = q.front();
                q.pop();
                q.push(tmp);
                flag++;
            }
        }
        cout << q.front() << endl;
    }
    return 0;
}