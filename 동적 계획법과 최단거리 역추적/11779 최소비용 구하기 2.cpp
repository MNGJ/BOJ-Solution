#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string>
#include <tuple>
using namespace std;

#define MAX 1e9*2

struct CNS
{
	int cnt;
	int node;
	string str;
};

const int INF = MAX;
int n, m, A, B;
vector<pair<int, int>> uv[1001];
int dist[1001];
string sequence[1001];
int From[1001];
vector<int> ans;

void Input()
{
	cin >> n >> m;
	int u, v, cnt;
	for (int i = 0; i < m; i++)
	{
		cin >> u >> v >> cnt;
		uv[u].push_back({ cnt, v });
	}
	cin >> A >> B;
	for (int i = 0; i < 1001; i++)
		dist[i] = INF;
}

void find_start(int end_point)
{
	ans.push_back(end_point);
	if (A == end_point) return;
	else find_start(From[end_point]);
}

int dijkstra(int start_node, int end_node)
{
	priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
	pq.push({ 0, start_node });
	dist[start_node] = 0;
	while (!pq.empty())
	{
		int cost = get<0>(pq.top());
		int cur_node = get<1>(pq.top());
		pq.pop();
		if (dist[cur_node] < cost) continue;

		for (int i = 0; i < uv[cur_node].size(); i++)
		{
			int next_cost = cost + uv[cur_node][i].first;

			if (next_cost < dist[uv[cur_node][i].second])
			{
				dist[uv[cur_node][i].second] = next_cost;
				From[uv[cur_node][i].second] = cur_node;
				pq.push({ next_cost, uv[cur_node][i].second });
			}
		}
	}
	find_start(end_node);
	return dist[end_node];
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);

	Input();
	dijkstra(A, B);
	cout << dist[B] << '\n';
	cout << ans.size() << '\n';
	reverse(ans.begin(), ans.end());
	for (int i = 0; i < ans.size(); i++)
		cout << ans[i] << " ";

	return 0;
}