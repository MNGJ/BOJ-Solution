#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

int N, M;
const long long INF = 1e12;
vector<pair<pair<int, int>, int>> uv;
long long dist[501];
bool isCycle;
void Input()
{
	cin >> N >> M;
	int u, v, w;
	for (int i = 0; i < M; i++)
	{
		cin >> u >> v >> w;
		uv.push_back({ {u, v}, w });
	}
}

void Bellman_Ford()
{
	dist[1] = 0;
	for (int i = 1; i <= N - 1; i++)
	{
		for (int j = 0; j < uv.size(); j++)
		{
			int u = uv[j].first.first;
			int v = uv[j].first.second;
			int cost = uv[j].second;

			if (dist[u] == INF) continue; // 한번이라도 계산 되었는지 판단
			if (dist[v] > dist[u] + cost)
				dist[v] = dist[u] + cost;
		}
	}

	for (int i = 0; i < uv.size(); i++)
	{
		int u = uv[i].first.first;
		int v = uv[i].first.second;
		int cost = uv[i].second;

		if (dist[u] == INF) continue;
		if (dist[v] > dist[u] + cost)
		{
			isCycle = true;
			return;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	for (int i = 0; i < 501; i++)
		dist[i] = INF;
	Bellman_Ford();

	if (isCycle)
		cout << -1;
	else
	{
		for (int i = 2; i <= N; i++)
		{
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}

	return 0;
}