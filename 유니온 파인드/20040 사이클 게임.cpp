#include <iostream>
#include <vector>
using namespace std;

int n, m;
int parent[500001];
bool isFind;
int ans;

int Find(int a)
{
	if (parent[a] == a)
		return a;
	else
		return parent[a] = Find(parent[a]);
}

void Union(int a, int b, int m)
{
	a = Find(a);
	b = Find(b);
	if (a == b && !isFind)
	{
		isFind = true;
		ans = m;
	}
	if (a < b)
		parent[b] = a;
	else
		parent[a] = b;
}

void Input()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		parent[i] = i;
	int node1, node2;
	for (int i = 1; i <= m; i++)
	{

		cin >> node1 >> node2;
		Union(node1, node2, i);
		if (isFind)
			return;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);

	Input();
	cout << ans;

	return 0;
}