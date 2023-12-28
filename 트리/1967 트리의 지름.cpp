#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int N;
vector<pair<int, int>> uv[10001];
bool visited[10001];
int max_node;
int ans;
void Input()
{
	cin >> N;
	int u, v, w;
	for (int i = 1; i < N; i++)
	{
		cin >> u >> v >> w;
		uv[u].push_back({v, w});
		uv[v].push_back({ u, w });
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