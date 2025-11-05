#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

struct Node
{
	double v, w;
	double vpw;
}mine[101];

bool cmp(Node a, Node b)
{
	return a.vpw > b.vpw;
}

int main()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> mine[i].v >> mine[i].w;
		mine[i].vpw = mine[i].v / mine[i].w;
	}
	sort(mine, mine + n, cmp);
	int i = 0;
	double sum = 0;
	while (m > 0 && i < n)
	{
		if (mine[i].w <= m)
		{
			m -= mine[i].w;
			sum += mine[i].v;
		}
		else
		{
			sum += mine[i].vpw * m;
			m = 0;
		}
		i++;
	}
	printf("%.1lf\n", sum);
	return 0;
}