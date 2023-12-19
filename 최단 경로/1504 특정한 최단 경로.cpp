#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

#define MAX 1e8;

int INF = MAX;
int N, E;
long long dist[801];
int v1, v2;
vector<pair<int, int>> nodes[801];

void Input()
{
	cin >> N >> E;
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		nodes[u].push_back({ v, w });
		nodes[v].push_back({ u, w });
	}
	cin >> v1 >> v2;
}

void Reset_dist()
{
	for (int i = 0; i <= 800; i++)
		dist[i] = INF;
}

int dijkstra(int start_node, int end_node)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({0, start_node});
	Reset_dist();
	dist[start_node] = 0;
	while (!pq.empty())
	{
		long long cost = pq.top().first;
		int node = pq.top().second;
		pq.pop();
		for (int i = 0; i < nodes[node].size(); i++)
		{
			int next_node = nodes[node][i].first;
			long long next_cost = cost + nodes[node][i].second;
			if (next_cost > dist[next_node])
				continue;
			dist[next_node] = next_cost;
			pq.push({ next_cost, next_node });
		}
	}
	return dist[end_node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	long long v1v2 = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, N);
	long long v2v1 = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, N);
	long long result = min(v1v2, v2v1);
	if (result >= INF)
		cout << -1;
	else
		cout << result;

	return 0;
}