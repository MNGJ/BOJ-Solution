#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int V;
vector<pair<int, int>> uv[100001];
bool visited[100001];
int ans = 0;
int max_node;
void Input()
{
	cin >> V;
	int u, v, dis;
	for (int i = 1; i <= V; i++)
	{
		cin >> u;
		cin >> v;
		while (v != -1)
		{
			cin >> dis;
			uv[u].push_back({ v, dis });
			cin >> v;
		}
	}
}

void DFS(int node, int sum)
{
	visited[node] = true;
	for (int i = 0; i < uv[node].size(); i++)
	{
		int next_node = uv[node][i].first;
		if (visited[next_node])
			continue;
		int cost = uv[node][i].second;
		if (ans < sum + cost)
		{
			ans = sum + cost;
			max_node = next_node;
		}
		visited[next_node] = true;
		DFS(next_node, sum + cost);
		visited[next_node] = false;
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	DFS(1, 0);
	visited[1] = false;
	DFS(max_node, 0);
	cout << ans;

	return 0;
}