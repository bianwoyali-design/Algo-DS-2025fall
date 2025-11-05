#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int arr[n];
    int maxLen[n];
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
        maxLen[i] = 1;
    }
    int ans = 1;
    for (int i = 0; i < n - 1; i++)
        for (int j = i + 1; j < n; j++)
            if (arr[i] < arr[j])
            {
                maxLen[j] = maxLen[i] + 1 > maxLen[j] ? maxLen[i] + 1 : maxLen[j];
                ans = maxLen[j] > ans ? maxLen[j] : ans;
            }
    cout << ans << endl;
    return 0;
}