#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;

const int INF = 1e9;
int test_case;
int n, m, t, s, g, h;
vector<pair<int, int>> uv[2001];
int dist[2001];
vector<pair<int, int>> destination;
int gh_dist;

void Reset_dist()
{
	for (int i = 0; i <= n; i++)
		dist[i] = INF;
}

void Input()
{
	destination.clear();
	for (int i = 0; i < 2001; i++)
	{
		uv[i].clear();
		dist[i] = INF;
	}
	cin >> n >> m >> t;
	cin >> s >> g >> h;
	int a, b, d;
	for (int i = 0; i < m; i++)
	{
		cin >> a >> b >> d;
		if ((g == a && h == b) || (h == a && g == b))
			gh_dist = d;
		
		uv[a].push_back({ b, d });
		uv[b].push_back({ a, d });
	}
	int x;
	for (int i = 0; i < t; i++)
	{
		cin >> x;
		destination.push_back({x, INF});
	}
}

int dijkstra(int start_node, int end_node)
{
	Reset_dist();
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start_node });
	dist[start_node] = 0;
	while (!pq.empty())
	{
		int node = pq.top().second;
		int cost = pq.top().first;
		if (end_node == node)
			return cost;
		pq.pop();
		for (int i = 0; i < uv[node].size(); i++)
		{
			int next_node = uv[node][i].first;
			int next_cost = uv[node][i].second + cost;
			if (dist[next_node] > next_cost)
			{
				dist[next_node] = next_cost;
				pq.push({ next_cost,next_node });
			}
		}
	}
	return dist[end_node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	cin >> test_case;

	while (test_case--)
	{
		Input();
		for (int i = 0; i < t; i++)
		{
			int pass_gh = min(dijkstra(s, g) + gh_dist + dijkstra(h, destination[i].first), dijkstra(s, h) + gh_dist + dijkstra(g, destination[i].first));
			int straight = dijkstra(s, destination[i].first);
			if (pass_gh == straight)
				destination[i].second = straight;
		}
		sort(destination.begin(), destination.end());
		for (int i = 0; i < t; i++)
		{
			if (destination[i].second == INF)
				continue;
			cout << destination[i].first << " ";
		}
		cout << '\n';
	}

	return 0;
}