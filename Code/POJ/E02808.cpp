#include <iostream>
using namespace std;

int main()
{
    int L, M;
    cin >> L >> M;
    int tree[L + 1] = {0};
    for (int i = 0; i < M; i++)
    {
        int begin, end;
        cin >> begin >> end;
        for (int j = begin; j <= end; j++)
            tree[j] = 1;
    }
    int cnt = 0;
    for (int i = 0; i <= L; i++)
        if (tree[i] == 0)
            cnt++;
    cout << cnt << endl;
    return 0;
}