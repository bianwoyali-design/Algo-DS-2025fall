#include <iostream>
#include <algorithm>
using namespace std;

struct Node
{
    int a;
    int b;
};

bool cmp(Node a, Node b)
{
    return a.a < b.a;
}

int main()
{
    int n;
    cin >> n;
    Node node[n];
    for (int i = 0; i < n; i++)
        cin >> node[i].a >> node[i].b;
    sort(node, node + n, cmp);
    for (int i = 0; i < n - 1; i++)
        if (node[i].b > node[i + 1].b)
        {
            cout << "Happy Alex" << endl;
            return 0;
        }
    cout << "Poor Alex" << endl;
    return 0;
}