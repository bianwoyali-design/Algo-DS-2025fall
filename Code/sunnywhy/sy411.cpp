#include <iostream>
#include <vector>
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> arr(n);
    vector<int> start(n + 1, 1);
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    auto Kadane = [&]() -> void
    {
        int max_curr = arr[0], max_glob = arr[0];
        for (int i = 1; i < n; i++)
        {
            if (max_curr >= 0)
            {
                max_curr += arr[i];
                start[i + 1] = start[i];
            }
            else
            {
                max_curr = arr[i];
                start[i + 1] = i + 1;
            }
            max_glob = max(max_glob, max_curr);
        }
    };

    Kadane();

    
}