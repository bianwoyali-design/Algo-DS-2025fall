#include <iostream>
using namespace std;

int main()
{
    int l = 0, r = 1000, mid = 0;
    while (l <= r)
    {
        mid = l + (r - l) / 2;
        if (query(mid) > 0)
            l = mid + 1;
        else if (query(mid) < 0)
            r = mid - 1;
        else
            break;
    }
    return 0;
}