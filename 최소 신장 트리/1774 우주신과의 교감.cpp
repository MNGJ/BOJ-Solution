#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

struct cool
{
	int x;
	int y;
};

struct line
{
	int u;
	int v;
	double dist;
};

int n, m;
int parent[1001];
cool cools[1001];
vector<line> edge;

bool cmp(const line& a, const line& b)
{
	return a.dist < b.dist;
}

int Find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = Find(parent[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

void Input()
{
	cin >> n >> m;
	for (int i = 1; i <= n; i++)
		parent[i] = i;
	for (int i = 1; i <= n; i++)
	{
		cin >> cools[i].x >> cools[i].y;
	}
	int tmp1, tmp2;
	for (int i = 1; i <= m; i++)
	{
		cin >> tmp1 >> tmp2;
		Union(tmp1, tmp2);
	}
	for(int i = 1; i <= n; i++)
		for (int j = i+1; j <= n; j++)
		{
			double d = sqrt(pow(cools[i].x - cools[j].x, 2) + pow(cools[i].y - cools[j].y, 2));
			edge.push_back({i, j, d});
		}
	sort(edge.begin(), edge.end(), cmp);
}

void Solve()
{
	double sum = 0;
	for (int i = 0; i < edge.size(); i++)
	{
 		int a = edge[i].u;
		int b = edge[i].v;
		a = Find(a);
		b = Find(b);
		if (a != b)
		{
			Union(a, b);
			sum += edge[i].dist;
		}
	}
	cout << fixed;
	cout.precision(2);
	cout << sum;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	return 0;
}