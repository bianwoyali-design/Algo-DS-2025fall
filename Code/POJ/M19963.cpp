#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    
    vector<int> distance(n);
    vector<vector<double>> ratio_price(n, vector<double>(2));
    vector<double> ratio(n), price(n);
    
    for (int i = 0; i < n; i++)
    {
        int a, b;
        char str[256]; 
        scanf("%s", str); 
        sscanf(str, "(%d,%d)", &a, &b);
        distance[i] = a + b;
    }
    
    for (int i = 0; i < n; i++)
    {
        double a;
        scanf("%lf", &a);
        price[i] = a;
        ratio[i] = distance[i] / a;
        ratio_price[i][0] = distance[i] / a;
        ratio_price[i][1] = a;
    }

    sort(ratio.begin(), ratio.end());
    sort(price.begin(), price.end());
    
    double mid_ratio, mid_price;
    int ans = 0;
    
    if (n % 2 == 1)
    {
        mid_ratio = ratio[n / 2];
        mid_price = price[n / 2];
        for (int i = 0; i < n; i++)
            if (ratio_price[i][0] > mid_ratio && ratio_price[i][1] < mid_price)
                ans++;
    }
    else
    {
        mid_ratio = (ratio[n / 2] + ratio[n / 2 - 1]) / 2;
        mid_price = (price[n / 2] + price[n / 2 - 1]) / 2;
        for (int i = 0; i < n; i++)
            if (ratio_price[i][0] > mid_ratio && ratio_price[i][1] < mid_price)
                ans++;
    }
    
    cout << ans << endl;
    return 0;
}