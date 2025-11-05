#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr;
    for (int i = 0; i < n; i++)
    {
        int tmp;
        cin >> tmp;
        arr.push_back(tmp);
    }
    
    int cnt = 1;
    int flag = 0;
    for (int i = 1; i < n; i++)
    {
        int diff = arr[i] - arr[i - 1];
        if (diff > 0 && flag <= 0)
        {
            cnt++;
            flag = 1;
        }
        if (diff < 0 && flag >= 0)
        {
            cnt++;
            flag = -1;
        }
    }

    cout << cnt << '\n';
    return 0;
}