#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 벨만 포드 알고리즘		최단 경로를 찾는데 가중치에 음수가 있을 경우 벨만 포드 이용
//						음수가 간선 사이를 돌며 무한대로 수가 낮아지는 것을 음수사이클이라 하는데, 음수 사이클인지 아닌지를 판단하기 위한 알고리즘이라 봐도 됌
//						정점 수(N) - 1 만큼 탐색을 돌면 음수 사이클이 아닐 시 최단 경로가 되며, 음수 사이클일 경우 탐색을 한번 더 돌면 최단 경로 값이 바뀐다.(돌수록 -무한대로 수렴)

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