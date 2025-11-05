#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> ratings(n);
    for (int i = 0; i < n; i++)
        cin >> ratings[i];
    
    int pre;
    int candies = 1;
    pre = 1;
    int dec = 0, cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if (ratings[i] >= ratings[i - 1])
        {
            cnt = 1;
            pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1;
            candies += pre;
            dec = i;
        }
        else
        {
            cnt++;
            if (dec > 0 && ratings[dec] != ratings[dec - 1])
                cnt--;
            candies += cnt;
            pre = 1;
        }
    }

    cout << candies << '\n';
    return 0;
}