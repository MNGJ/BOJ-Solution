#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

#define MAX 987654321;
int INF = MAX;
int V, E, K;
vector<pair<int, int>> nodes[20001];
int dist[20001];

void Input()
{
	cin >> V >> E;
	cin >> K;
	int u, v, w;
	for (int i = 0; i < E; i++)
	{
		cin >> u >> v >> w;
		nodes[u].push_back({ w, v });
	}
}

void dijkstra(int node)
{
	priority_queue<pair<int, int>> pq; // 우선순위 큐는 기본 내림차순 정렬

	pq.push({ 0, node });
	dist[node] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int here = pq.top().second;
		pq.pop();
		if (dist[here] < cost) continue; // 이미 최단거리 정보 있으면 pass

		for (int i = 0; i < nodes[here].size(); i++)
		{
			int next_cost = cost + nodes[here][i].first;

			// here을 경유해서 가는게 빠르면 dist 갱신 후 push
			if (next_cost < dist[nodes[here][i].second])
			{
				dist[nodes[here][i].second] = next_cost;
				pq.push({ -next_cost, nodes[here][i].second });
				// 내림차순 정렬이라 최소값이 앞에 오도록 음수로 변환
			}
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	for (int i = 0; i <= V; i++)
		dist[i] = INF;
	dijkstra(K);

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF)
			cout << "INF" << '\n';
		else
			cout << dist[i] << '\n';
	}

	return 0;
}