#include <iostream>
#include <vector>
using namespace std;

void moveDisk(int numDisk, char fromPole, char toPole)
{
    printf("%d:%c->%c\n", numDisk, fromPole, toPole);
}

void moveTower(int height, char fromPole, char withPole, char toPole)
{
    if (height == 1)
        moveDisk(1, fromPole, toPole);
    else
    {
        moveTower(height - 1, fromPole, toPole, withPole);
        moveDisk(height, fromPole, toPole);
        moveTower(height - 1, withPole, fromPole, toPole);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    char a, b, c;
    cin >> n >> a >> b >> c;
    moveTower(n, a, b, c);
    return 0;
}