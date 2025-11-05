#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Node
{
    int t, it;
};

bool cmp(Node x, Node y)
{
    if (x.t != y.t) return x.t < y.t;
    return x.it < y.it;
}

int main()
{
    int n;
    cin >> n;
    vector<Node> time(n);
    for (int i = 0; i < n; i++)
    {
        cin >> time[i].t;
        time[i].it = i + 1;
    }

    sort(time.begin(), time.end(), cmp);

    double sum = 0;
    int tmp = n - 1;
    for (int i = 0; i < n - 1; i++)
        sum += (tmp--) * time[i].t;
    sum /= n;

    for (int i = 0; i < n; i++)
        printf("%d ", time[i].it);
    printf("\n%.2lf", sum);
    return 0;
}