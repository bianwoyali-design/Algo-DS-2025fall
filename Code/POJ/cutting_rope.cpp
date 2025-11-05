#include <iostream>
#include <queue>
#include <functional>
#include <vector>
using namespace std;

long long min_Heap(long long arr[], long long n)
{
    priority_queue<long long, vector<long long>, greater<long long>> minHeap;
    for (int i = 0; i < n; i++)
    {
            minHeap.push(arr[i]);
    }
    long long totalCost = 0;
    while (minHeap.size() > 1)
    {
        long long first = minHeap.top();
        minHeap.pop();
        long long second = minHeap.top();
        minHeap.pop();
        totalCost += first + second;
        minHeap.push(first + second);
    }
    return totalCost;
}

int main()
{
    long long n;
    long long arr[20001];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("%ld\n", min_Heap(arr, n));
    return 0;
}
