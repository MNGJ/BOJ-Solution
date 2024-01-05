#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>
using namespace std;
#define MAX 2147483647

int V, E;
vector<tuple<int, int, int>> uv;
int check[10001];
int sum;
int Find(int a)
{
	if (check[a] == a)
		return a;
	else
		return check[a] = Find(check[a]);
}

void Union(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a < b)
		check[b] = a;
	else
		check[a] = b;
}

bool isCycle(int a, int b)
{
	a = Find(a);
	b = Find(b);
	if (a == b) return true;
	else return false;
}

void Input()
{
	cin >> V >> E;
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		uv.push_back({ w, u, v });
	}
	sort(uv.begin(), uv.end());
	for (int i = 1; i <= V; i++)
		check[i] = i;
}

void Solve()
{
	for (int i = 0; i < uv.size(); i++)
	{
		int node1 = get<1>(uv[i]);
		int node2 = get<2>(uv[i]);
		if (!isCycle(node1, node2))
		{
			sum += get<0>(uv[i]);
			Union(node1, node2);
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	Solve();

	cout << sum;

	return 0;
}